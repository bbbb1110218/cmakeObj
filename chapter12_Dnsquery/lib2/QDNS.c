//TODO::need motify include 

#include "../include/QDNS.h"

#include "../include/Qpreinclude.h"




//全局的DNS 头部
Dns_all globalDns;


//LIB专用缓存
static struct DNS_buff  libBuff;
static struct DNS_buff  Buff;



void initGlobalDns(){
    srand(time(NULL));
    //生成随机查询ID
#if NEED_DEBUG
    globalDns.header.TRANS_ID = 1;
#else 
    globalDns.header.TRANS_ID = (unsigned int) rand() % 0xFFFF;
#endif  //NEED_DEBUG
    //设置递归查询;
    GlobalDnsSetFlag(FLAGS_RECURSE); 

}


//设置head的flag
void GlobalDnsSetFlag(unsigned short flg){
    globalDns.header.FLAGS |= flg;
}



//返回查询ID
unsigned short getTransId(){
    return globalDns.header.TRANS_ID;
}



//返回全局的指针 方便调试
Dns_all* getGlobalDns(){
    return &globalDns;
}


//TODO 查看所有 记得删除
void SHOW_GLOBAL_DELETEME(){
    
    printf("STYLE 1:---------------------------------------------------\n");
    SHOW_FLAGS("TRANS_ID  :",globalDns.header.TRANS_ID);
    SHOW_FLAGS("FLAGS     :",globalDns.header.FLAGS);
    SHOW_FLAGS("QUESTIONS :",globalDns.header.QUESTIONS);
    SHOW_FLAGS("ANSWERS   :",globalDns.header.ANSWERS);
    SHOW_FLAGS("AUTHORITY :",globalDns.header.AUTHORITY);
    SHOW_FLAGS("ADDITIONAL:",globalDns.header.ADDITIONAL);
    
    Q_showBuff(globalDns.buff_t.buff,globalDns.buff_t.buffLen);
    SHOW_FLAGS("type      :",globalDns.tailer.type);
    SHOW_FLAGS("t_class   :",globalDns.tailer.t_class);
    printf("\nSTYLE 2:---------------------------------------------------\n");
    size_t tmp=sizeof(globalDns.header);
    char *p=(char *)&globalDns.header;
    Q_showBuff(p,tmp);
    Q_showBuff(globalDns.buff_t.buff,globalDns.buff_t.buffLen);
     tmp=sizeof(globalDns.tailer);
    p=(char *)&globalDns.tailer;
    Q_showBuff(p,tmp);
}

/**缓存填充到全局的globalDns里面*/
void fillUrlToGlobalDns(){
    memcpy(globalDns.buff_t.buff,libBuff.buff,libBuff.buffLen);
    globalDns.buff_t.buffLen=libBuff.buffLen;
}
/**设置Url 复制到缓存里面*/
void setQueryUrl(const char *url){
    initbuff();
    // unsigned char firstDot=0;
    // libBuff.buffLen

    memcpy(libBuff.buff+1,url,strlen(url)+2);
    libBuff.buff[strlen(url)+1]=0;
    libBuff.buff[0]='.';

    int currentPos=0;
    unsigned char size=0;
    int i;

    for( i=0;i<strlen(url)+1;i++){
        if(libBuff.buff[i]=='.'){
            libBuff.buff[currentPos]=size;
            currentPos=i;
            size=0;
        }
        else{
            size++;
        }
    }
    libBuff.buff[currentPos]=size;
    libBuff.buffLen=strlen(url)+2;
    fillUrlToGlobalDns();
    //header.question +
    if(globalDns.buff_t.buffLen)
        globalDns.header.QUESTIONS++;
}



//初始化缓存;
void initbuff(){
    libBuff.buffLen=0;
    memset(libBuff.buff,0,BUFFSIZE);
}

/* 打印缓存 的内容*/
void Q_showBuff(const char *buff,size_t len){
    // printf("%s---\n","Global buff Show start----");
    for (int i = 0; i < len; i++) {
            fprintf(stdout, "%02x", (unsigned char)buff[i]);
            if (i % 16 == 7) {
                fprintf(stdout, "   ");
            } else {
                fprintf(stdout, " ");
            }
            if (i % 16 == 15 || i == len - 1) {
                // Pad extra spaces if len is not multiple of 16
                int padding = (16 - (i % 16) - 1) * 3;
                for (int j = 0; j < padding; j++) {
                    fprintf(stdout, " ");
                }
                fprintf(stdout, " | ");
                // Print ASCII representation
                for (int j = i - (i % 16); j <= i; j++) {
                    if (buff[j] >= ' ' && buff[j] <= '~') {
                        fprintf(stdout, "%c", buff[j]);
                    } else {
                        fprintf(stdout, ".");
                    }
                }
                fprintf(stdout, "\n");
            }
        }
    //  printf("%s---","buff");
    //  printf("%s---\n","Global buff Show End----");
}


