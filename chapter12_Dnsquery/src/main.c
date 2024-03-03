#include <stdio.h>
#include "dnslib.h"
#include <fcntl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "t_socket.h"

// #define SHORT_BIG_ENDIAN(x) ((x << 8)|(x >> 8))

#ifndef MARCO_DNS_SERVER
    #error "need set MARCO_DNS_SERVER"
    #error "需要设置宏"
#else
    #define DNS_SERVER MARCO_DNS_SERVER
#endif 
#define DNS_PORT 53
#define BUF_SIZE 1024

#if defined (DEBUG)
    #define SHOW(format,x) fprintf(stdout,format,x)
#endif 


#define DEBUG_SHOW(format,x)   


int main(int argc,char *argv[]){

    if(argc !=2){
        fprintf(stderr,"Usage :%s <Url>\n",argv[0]);
        exit(1);
    }

    SHOW("Request URl:%s \n",argv[1]);
    SHOW("DNS  SERVER:%s\n",DNS_SERVER);
    
    int sockfd;
    struct sockaddr_in dns_server;
    // struct sockaddr_in dns_current;
    char query[BUF_SIZE];
    char buff[BUF_SIZE];
    char response[BUF_SIZE];


    // bzero(query,BUF_SIZE);
    // bzero(response,BUF_SIZE);

    memset(query,0,BUF_SIZE);
    memset(buff,0,BUF_SIZE);
    memset(response,0,BUF_SIZE);

/** build Querty content */

    T_QUERY_DNS dns;
    T_QUERY_DNS * pr;

    // const char * url="dididi.co";
    
    dns.header.TRANS_ID=htons(0x4444);
    dns.header.FLAGS=htons(0x0300);
    dns.header.QUESTIONS=htons(1);
    dns.header.ANSWERS=htons(0x0000);
    dns.header.AUTHORITY=0;
    dns.header.ADDITIONAL=0;
    dns.query.buffLen= QformatUrl(argv[1],dns.query.buff);
    dns.query.type=htons((unsigned short)1);
    dns.query.t_class=htons((unsigned short)1);
    size_t n=QwriteDnsToBuff(query,&dns);

//TODO::debug 
/**
 * @brief :TODO need fixit
 * @output: segmentation fault 访问了不应该访问的内存
 * 
 */
    printf("\nGEtQueryTYpe(&dns.header) result is %s\n",DNSQueryType(&(dns.header))?"True":"False");

    Q_showBuff(query,n);

    sockfd=Q_getUdpSocket();

    memset(&dns_server,0,sizeof(struct sockaddr_in));

    dns_server.sin_family=AF_INET;
    dns_server.sin_addr.s_addr=inet_addr(DNS_SERVER);
    dns_server.sin_port=htons(DNS_PORT);


    

    if (sendto(sockfd, query, n, 0, (struct sockaddr *)&dns_server, sizeof(dns_server)) < 0) {
        perror("sendto failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len = sizeof(dns_server);
    int recv_size = recvfrom(sockfd, response, BUF_SIZE, 0, (struct sockaddr *)&dns_server, &len);
    
    if (recv_size < 0) {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }

    printf("\n\n\nrecv_size: %d\n\n\n", recv_size);

    Q_showBuff(response,recv_size);

    pr=(T_QUERY_DNS *)response;

    // if(DNSQueryType(&(pr->header))){
    //     printf("GetQueryType(&dns.header) result is ture\n");

    // }else{
    //     printf("GetQueryType(&dns.header) result is false\n");
    // }

    // printf("GEtQueryTYpe(&dns.header) result is %s\n",DNSQueryType(&(pr->header))?"True":"False");

        printf("GEtQueryTYpe(&dns.header) result is %s\n",DNSQueryType(&(pr->header))?"True":"False");




    close(sockfd);

    // free(dns_server);



/** before  testCoding ... 
    // fprintf(stdout,"Nothing\n");

    // header.id = SHORT_BIG_ENDIAN(0x1234);

    // testStruct *ps=&header;



    // int fd=open("tmp.dat",O_CREAT|O_RDWR,0666);
    // write(fd,&header,sizeof(header));
    // close(fd);
    // int fd2=open("test.dat",O_CREAT|O_RDWR,0666);
    // write(fd2,ps,sizeof(header));
    // close(fd2);
*/

    return 0;
}

/**
 * 接收到的结构 
 *  id                  2
 *  flag                2
 *  question            2
 *  answer              2
 *  authority           2
 *  additional          2 
 *  QUERY:
 *   3www5baidu3com0    14
 *   type               2
 *   class              2 
 *  
 * 
 *   ANSWER:
 *   name:   0xc00c      2
 *   type: 2   1         
 *  class: 2  1
 *  timetolive :4 int 
 *   Data length:  2 unsigned short
 *   ip address: 4 
 * 
 *   ADDITIONAL:
 *   name：        root 1
 *   type：        opt  2
 *   udp payload size:  2    
 *   extended RCODE:    1
 *  version:            1
 *    z:                3
 *   data_len:          2 
 */   