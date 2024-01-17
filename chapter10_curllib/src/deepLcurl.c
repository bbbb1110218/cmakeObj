#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>

#if !defined(DEEPLAPI)
    #error "DEEPAPI is required to compile this example"
#endif


#define __STR(X) #X
#define STR(X) __STR(X)

//缓存放请求内容
char BUFF[10240];

/**
 * 
 * 当curl -s -X POST 'https://api-free.deepl.com/v2/translate'
--header 'Authorization: DeepL-Auth-Key e8ad9dbd-17a0-9的4947e08:fx'
--data-urlencode "text=$args"
--data-urlencode 'target_lang=ZH'
*/

int main(int argc,char **argv){
    if(argc<2){
        fprintf(stderr,"Usage: %s 要翻译的内容\n",argv[0]);
        return 1;
    }

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

    char *format="text=%s&target_lang=ZH";
    sprintf(BUFF,format,argBuff);

    

    CURL *curl;
    CURLcode res;
    // url的请求头部分 放请求的密钥啥的 是一个链表
    struct curl_slist *headers = NULL; 
    headers = curl_slist_append(headers, STR(DEEPLAPI));
    // printf(">>>>>>APi=%s\n", STR(DEEPLAPI));
    

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl=curl_easy_init();
    if(curl){
        curl_easy_setopt(curl,CURLOPT_URL,"https://api-free.deepl.com/v2/translate");
        curl_easy_setopt(curl,CURLOPT_HTTPHEADER,headers);
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,BUFF);

        res=curl_easy_perform(curl);

        if(res!=CURLE_OK)
            fprintf(stderr,"curl_easy_perform() failed: %s\n",curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    free(argBuff);
    // sprintf(stdout,"$s","\n");
    printf("\n还需要解析json\n");

    return 0;
}