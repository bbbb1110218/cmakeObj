#ifndef __DNS_LIB_H__
#define __DNS_LIB_H__

#include <arpa/inet.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define BUFFSIZE                    1024

//Query flag
#define FLAGS_QUERY                 0x0000
#define FLAGS_TRUNCATED             0x0200 //被截断
#define FLAGS_RECURSE               0x0100 //递归查询 

//Respon flag
// #define


/**
 * @brief 
 * 
 *  DNS: query selection
 * 
 *  TRANSCATION ID:         2 byte
 *  
 *  FLAGS:                  2Byte
*  0... ....  .... ....  0 query 1 response  
*  .000 0...  .... ....  opcode:stand query  
*  .... .0.. .... .... = Authoritative: Server is not an authority for domain
*  .... ..0. .... .... = Truncated: Message is not truncated
*  .... ...1 .... .... = Recursion desired: Do query recursively
*  .... .... 1... .... = Recursion available: Server can do recursive queries
*  .... .... .0.. .... = Z: reserved (0)
*  .... .... ..0. .... = Answer authenticated: Answer/authority portion was not authenticated by the server
*  .... .... ...0 .... = Non-authenticated data: Unacceptable
*  .... .... .... 0000 = Reply code: No error (0) 
*
*  QUESTION:                2Byte    Questions: 1
*  Answers :                2Byte    dns.count.answers
*  Authority RRs:           2Byte    权威纪录 
*  additional RRS：         2Byte     附加纪录
*  
*  Queries:
*  name: www.baidu.com   format 3www5baidu3com0  end by 0
*  type: short           2Byte  1:A纪录  5:cname 
*  Class: short          2Byte  1:IN
*
*
*  Answers:
*  Name:  Offset     0xc00c   最高两位不要  0xc00c & 0x3FFF   是整个响应的偏移量  响应[0xc00c & 0x3FFF]开始0结束
*  type:  short 2Byte 1:A纪录
*  class:short  2Byte 1:IN
*  TIME TO LIVE: int   单位秒
*   DATE length : unsigned short 
*  address: ip 地址
*
*
*
*
*/


typedef struct Dns_header{
    unsigned short TRANS_ID;            //查询ID
    unsigned short FLAGS;               //标志位
    unsigned short QUESTIONS;           //问题
    unsigned short ANSWERS;             //回答
    unsigned short AUTHORITY;           //权威
    unsigned short ADDITIONAL;          //附加信息
} Dns_header;

//header大小 应该是12个字节
#define DNSHEADERSIZE                  sizeof(struct Dns_header)

typedef struct DNS_buff{
    char  buff[BUFFSIZE];
    size_t buffLen;
}Dns_buff;


typedef struct Dns_tailer{
    unsigned short type;
    unsigned short t_class;
}Dns_tailer;


typedef struct Dns_all{
    Dns_header header;
    Dns_buff buff_t;
    Dns_tailer tailer;
}Dns_all;


//定义一个全局的访问DNS得头部
extern Dns_all globalDns;

#define __FUNC_AREA_
#define __FUNC_AREA_

__FUNC_AREA_

void initGlobalDns();
void GlobalDnsSetFlag(unsigned short flg);

//返回查询ID
unsigned short getTransId();

//返回全局的指针 方便调试
Dns_all* getGlobalDns();

void SHOW_GLOBAL_DELETEME();
/*打印缓存的内容*/
void Q_showBuff(const char *buff,size_t len);
/**设置Url 复制到缓存里面*/
void setQueryUrl(const char *url);

//初始化缓存;
void initbuff();

__FUNC_AREA_

extern Dns_all globalDns;


#endif  //__DNS_LIB_H_