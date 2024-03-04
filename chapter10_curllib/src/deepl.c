#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>

// 解析json（省略了原始代码）

#include <jansson.h>

#if !defined(URL_HEAD_INCLUDE_API)
    #error "DEEPAPI is required to compile this example"
#endif


/**
 * @file deepl.c
 * @brief 使用DeepL API进行文本翻译的示例代码
 *
 * 该代码演示了如何使用DeepL API进行文本翻译。它接受命令行参数作为要翻译的文本，并根据文本的语言选择目标语言进行翻译。
 * 该代码使用libcurl库进行HTTP请求，并使用DeepL API密钥进行身份验证。
 *
 * 使用方法：
 *   deepl [要翻译的内容]
 *
 * 示例：
 *   deepl "Hello, world!"
 *
 * 该代码还包括一个辅助函数isEnglish，用于检查给定的字符串是否为英文。
 */


#define __STR(X) #X
#define STR(X) __STR(X)

typedef struct respon{
    char *data;
    size_t length;
}RESPON;


//缓存放请求内容
char BUFF[10240];

/**
 * 
 * 当curl -s -X POST 'https://api-free.deepl.com/v2/translate'
--header 'Authorization: DeepL-Auth-Key e8ad9dbd-17a0-9的4947e08:fx'
--data-urlencode "text=$args"
--data-urlencode 'target_lang=ZH'
*/

char format[30];

int isEnglish(const char *str); 

//需要return respon char 个数，要不然curl 会出错
size_t CallBackFun(void *respon,size_t one,size_t contentSize,void *userData);


char * analysisDeeplJson(const char *resp);



int main(int argc,char **argv){
    //判断参数
    if(argc<2){
        fprintf(stderr,"Usage: %s 要翻译的内容\n",argv[0]);
        return 1;
    }

    //显示帮助
    if(!strncmp(argv[1],"-h",2) || !strncmp(argv[1],"-H",2) || !strncmp(argv[1],"-H",2)){
        fprintf(stdout,"%s\n","使用deepl翻译文本");
        exit(EXIT_SUCCESS);

    }

    //判断参数中英文
    if(isEnglish(argv[1]))
        strcpy(format,"text=%s&target_lang=ZH");
    else
        strcpy(format,"text=%s&target_lang=EN");

//初始化接受内容的结构
RESPON *pdata=(RESPON *)malloc(sizeof(RESPON));
    pdata->length=0;
    pdata->data=malloc(1);


    
    


    int n=0;
    for(int i=1;i<argc;i++){
        n+=strlen(argv[i]);
    }

    char * argBuff=(char *)malloc(n+argc);
    memset(argBuff,0,n+argc);
    for(int i=1;i<argc;i++){
        strcat(argBuff,argv[i]);
        strcat(argBuff," ");
    }
    int len=strlen(argBuff);
    argBuff[len-1]='\0';

    // char *format="text=%s&target_lang=ZH";
    sprintf(BUFF,format,argBuff);
    // printf(">>>>>>BUFF=%s\n", BUFF);

    

    CURL *curl;
    CURLcode res;
    // url的请求头部分 放请求的密钥啥的 是一个链表
    struct curl_slist *headers = NULL; 
    headers = curl_slist_append(headers, STR(URL_HEAD_INCLUDE_API));
    if(headers ==NULL){
        printf("headers is null\n");
        exit(1);
    }
    // printf(">>>>>>APi=%s\n", STR(URL_HEAD_INCLUDE_API));
    

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl=curl_easy_init();
    if(curl){
        //传递URL
        curl_easy_setopt(curl,CURLOPT_URL,"https://api-free.deepl.com/v2/translate");
        //传递参数吧
        curl_easy_setopt(curl,CURLOPT_HTTPHEADER,headers);
        //传递post字段
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,BUFF);
        //回调函数
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,CallBackFun);
        //传递接受的结构
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,(void *)pdata);

        res=curl_easy_perform(curl);

        if(res!=CURLE_OK)
            fprintf(stderr,"curl_easy_perform() failed: %s\n",curl_easy_strerror(res));

        curl_easy_cleanup(curl);
        if(pdata->data){
            // printf("get the respon:%s\n",pdata->data);
            char *resData=analysisDeeplJson(pdata->data);
            printf("%s\n",resData);
            free(resData);
        }

        else
            printf("respon save faild\n");
    }
    curl_global_cleanup();
    free(argBuff);
    // sprintf(stdout,"$s","\n");
    // printf("\n还需要解析json\n");

    return 0;
}


int isEnglish(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!(str[i] >= ' ' && str[i] <= '~')) {
            return 0;
        }
    }
    return 1;
}


size_t CallBackFun(void *respon,size_t one,size_t contentSize,void *userData){
    size_t count = one *contentSize;
    RESPON *res=(RESPON *)userData;
    char *ptr=realloc(res->data,res->length +count +1);
    if(!ptr){
        printf("not enough memory (realloc Error),file:%s,lineno:%d",__FILE__,__LINE__);
        return 0;
    }
    res->data=ptr;
    memcpy(&res->data[res->length],respon,count);
    res->length +=count;
    res->data[res->length]=0;
    
    return count;
}

//解析deep响应内容
char * analysisDeeplJson(const char *resp){
    //respon格式{"translations":[{"detected_source_language":"ZH","text":"field"}]}
    json_error_t error;
    json_t *root, *translations, *first_item, *text;
    root=json_loads(resp,0,&error);
    if(!root) {
        fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
        return NULL;
    }

    translations = json_object_get(root, "translations");

    //响应为列表
    if(!json_is_array(translations)) {
        fprintf(stderr, "error: translations is not an array\n");
        json_decref(root);
        return NULL;
    }
        first_item = json_array_get(translations, 0);
    if(!json_is_object(first_item)) {
        fprintf(stderr, "error: first item is not an object\n");
        json_decref(root);
        return NULL;
    }

    text = json_object_get(first_item, "text");
    if(!json_is_string(text)) {
        fprintf(stderr, "error: text is not a string\n");
        json_decref(root);
        return NULL;
    }

    // printf("text: %s\n", json_string_value(text));

    int buffsize=strlen(json_string_value(text));
  

    char *value=(char *)malloc(1+strlen(json_string_value(text)));
    memset(value,0,buffsize+1);
    strcpy(value,json_string_value(text));
    value[buffsize]='\0';
    json_decref(root);
    return value;
}
