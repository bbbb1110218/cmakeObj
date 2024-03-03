#ifndef __DNS_LIB_H__
#define __DNS_LIB_H__

#include "Qpreinclude.h"
#include <arpa/inet.h>
#include <stdbool.h>

#define NEED_DEBUG 1 
#define NO_DEBUG   0

#if NEED_DEBUG


typedef struct T_DNS_HEADER{
    unsigned short TRANS_ID;            //查询ID
    unsigned short FLAGS;               //标志位
    unsigned short QUESTIONS;           //问题
    unsigned short ANSWERS;             //回答
    unsigned short AUTHORITY;           //权威
    unsigned short ADDITIONAL;          //附加信息
} T_DNS_HEADER;

bool DNSQueryType(struct T_DNS_HEADER *dnsHeader);
int DNSQueryCount(struct T_DNS_HEADER *dnsHeader);

void parse_dns_name(unsigned char * buffer, int * offset);

typedef struct T_QUERY{
    char  buff[128];
    int buffLen;
    unsigned short type;
    unsigned short t_class;
}T_QUERY;




typedef struct T_QUERY_DNS{
    T_DNS_HEADER header;
    T_QUERY query;
}T_QUERY_DNS;



size_t QformatUrl(const char *url,char *buff);

void QoutputTest(const char *fileName, void *buff,size_t len);

void QshowDns(const char *fileName, T_QUERY_DNS *dns);


/**写入到buff里面*/
size_t QwriteDnsToBuff(char *buff,  T_QUERY_DNS *dns);
void Q_showBuff(char *buff,size_t len);

#define __STR(x) #x
#define STR(x) __STR(x)
#define SHOW_STR(x) printf("%s : ",STR(x))


#define SHOW_FLAGS(INFO,_unsigned_short_value)    SHOW_STR(INFO) ;\
int a=15; \
do{ \
    printf("%s",((_unsigned_short_value >> a ) & 0x01 ) ? "1":"0"); \
    a--; \
}while(a) ; \
printf("%s","\n");





























#else 
 


// DNS header structure
struct DNS_HEADER {
    unsigned short id; // identification number
    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag     是 1 bit 字段：0 表示查询报文，1 表示响应报文。
    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available
    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};

typedef struct DNS_HEADER DNS_HEADER;

// DNS question structure
struct QUESTION {
    unsigned short qtype;
    unsigned short qclass;
};

struct testStruct{
    unsigned short id1;
    unsigned short id2;
    unsigned short id3;
    unsigned short id4;
    unsigned short id5;
    unsigned short id6;

};

typedef struct testStruct testStruct;

extern  DNS_HEADER header;
#endif




#endif  // __DNS_LIB_H__