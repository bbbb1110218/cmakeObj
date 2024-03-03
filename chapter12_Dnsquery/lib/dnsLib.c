#include "dnslib.h"
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>






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

/**
 * @brief  LIKE: www.baidu.com -> 3www5baidu3com0
 * @debug:
 * @param url src
 * @param buff  dst
 * @return size_t sizeof(dst)
 */


size_t QformatUrl(const char *url,char *buff){
    memcpy(buff+1,url,strlen(url)+2);
    buff[strlen(url)+1]=0;
    buff[0]='.';

    int currentPos=0;
    int size=0;
    int i;

    for( i=0;i<strlen(url)+1;i++){
        if(buff[i]=='.'){
            buff[currentPos]=size;
            currentPos=i;
            size=0;
        }
        else{
            size++;
        }
    }
    buff[currentPos]=size;
    return strlen(buff)+1;
}


/**
 * @brief 测试输出到文件 方便查看
 * 
 * @param fileName 输出的文件名称
 * @param buff     content
 * @param len       sizeof(content)
 */
void QoutputTest(const char *fileName, void *buff,size_t len){
    int fd=open(fileName,O_CREAT|O_RDWR,0666);
    write(fd,buff,len);
    close(fd);
}

/**打印结构 输出到文本*/
void QshowDns(const char *fileName, T_QUERY_DNS *dns){
    int fd=open(fileName,O_CREAT|O_RDWR,0666);
    write(fd,(void *)&dns->header,sizeof(dns->header));
    write(fd,(void *)&dns->query.buff,dns->query.buffLen);
    write(fd,(void *)&dns->query.type,sizeof(dns->query.type));
    write(fd,(void *)&dns->query.t_class,sizeof(dns->query.t_class));
    close(fd);
    
}

/**写入到buff里面*/
size_t QwriteDnsToBuff(char *buff,  T_QUERY_DNS *dns){
    size_t len=0;
    memcpy(buff+len,&dns->header,sizeof(dns->header));
    len+=sizeof(dns->header);
    memcpy(buff+len,&dns->query.buff,dns->query.buffLen);
    len+=dns->query.buffLen;
    memcpy(buff+len,&dns->query.type,sizeof(dns->query.type));
    len+=sizeof(dns->query.type);
    memcpy(buff+len,&dns->query.t_class,sizeof(dns->query.t_class));
    len+=sizeof(dns->query.t_class);
    return len;
}   

/**测试打印缓存里面的内容里面的内容*/
void Q_showBuff(char *buff,size_t len){

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
}
/** @brief:请求的类型  false 为请求  True 为响应*/
bool DNSQueryType(struct T_DNS_HEADER *dnsHeader){
    SHOW_FLAGS("dnsHeader->FLAGS",dnsHeader->FLAGS);
    printf("[f]ile:%s,line:%d,function:%s]\n >>>>>>%hu\n",__FILE__,__LINE__,__FUNCTION__,dnsHeader->FLAGS);
    printf("[file:%s,line:%d,function:%s]\n >>>>>>%hu\n",__FILE__,__LINE__,__FUNCTION__,dnsHeader->FLAGS);
    printf("%hu\n",dnsHeader->FLAGS);
    printf("%hu\n",dnsHeader->FLAGS & (unsigned short)(0x0080));


    // return 1;
    return !(dnsHeader->FLAGS >>15 );/**右移动7位取反*/
} 

/** @brief*/
bool DNSIsRecursion(struct T_DNS_HEADER *dnsHeader){
    return dnsHeader->FLAGS & 0x01;
}

bool DnsIsQueryTruncated(struct T_DNS_HEADER *dnsHeader){
    return dnsHeader->FLAGS & 0x02;
}



int DNSQueryCount(struct T_DNS_HEADER *dnsHeader){
    return (int)dnsHeader->ANSWERS;
}

//TODO
int read_offset(unsigned char *buffer, int *offset) {
    int pointer = buffer[*offset] & 0x3f; // 只保留低6位
    pointer = (pointer << 8) + buffer[*offset + 1]; // 与后一个字节相加
    *offset += 2; // 移动偏移量
    return pointer;
}

// 解析DNS响应中的域名
//TODO

/// @brief 
/// @param buffer 
/// @param offset 
void parse_dns_name(unsigned char *buffer, int *offset) {
    int compressed = 0; // 指示是否为压缩指针
    int i = 0; // 用于记录读取的字节数
    while (buffer[*offset] != 0) { // 直到遇到结尾字符
        if ((buffer[*offset] & 0xc0) == 0xc0) { // 如果是压缩指针
            if (!compressed) { // 如果还没处理过压缩指针
                compressed = 1;
                *offset += 2; // 压缩指针占两个字节
            }
            int pointer = read_offset(buffer, offset); // 读取偏移量
            parse_dns_name(buffer, &pointer); // 递归调用解析
            return;
        } else { // 非压缩指针
            int len = buffer[*offset]; // 读取长度
            (*offset)++; // 移动偏移量
            for (int j = 0; j < len; j++) { // 读取域名
                printf("%c", buffer[*offset]);
                (*offset)++;
                i++;
            }
            printf(".");
        }
    }
    if (!compressed) // 如果不是压缩指针
        (*offset)++; // 结尾字符占一个字节
}

