#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define DNS_SERVER "192.168.50.1"
#define DNS_PORT 53
#define BUF_SIZE 1024

// DNS报文结构
struct dns_header {
    uint16_t id;
    uint16_t flags;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
};

int main(int argc,char *argv[]) {
    // if(argc !=2){
    //     printf("Usage: %s <DNS SERVER IP>\n",argv[0]);
    //     exit(1);
    // }

    // const char *DNS_SERVER=argv[1];

    int sockfd;
    struct sockaddr_in dns_server;
    char query[BUF_SIZE];
    char response[BUF_SIZE];
    
    // 创建套接字
    if ((sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // 设置DNS服务器地址
    memset(&dns_server, 0, sizeof(dns_server));
    dns_server.sin_family = AF_INET;
    dns_server.sin_addr.s_addr = inet_addr(DNS_SERVER);
    dns_server.sin_port = htons(DNS_PORT);
    
    // 构造DNS查询报文
    struct dns_header *dns_hdr = (struct dns_header *)query;
    dns_hdr->id = htons(0x1234); // 任意值
    dns_hdr->flags = htons(0x0100); // 标准查询 小端序
    dns_hdr->qdcount = htons(1); // 一个问题
    dns_hdr->ancount = 0;
    dns_hdr->nscount = 0;
    dns_hdr->arcount = 0;
    
    // 将查询的域名转换成标准格式
    // char *domain = "www.baidu.com";
    char *domain = "\3www\5baidu\3com\0";
    char *ptr = query + sizeof(struct dns_header);
    strcpy(ptr, domain);
    for (int i = 0; i < strlen(domain); ++i) {
        if (ptr[i] == '.') {
            ptr[i] = (char)(strlen(ptr + i + 1));
        }
    }
    ptr += strlen(domain) + 1;
    *((uint16_t *)ptr) = htons(1); // 查询类型为A记录
    ptr += 2;
    *((uint16_t *)ptr) = htons(1); // 查询类别为Internet
    
    // 向DNS服务器发送查询报文
    if (sendto(sockfd, query, sizeof(struct dns_header) + strlen(domain) + 2 + 4, 0, (struct sockaddr *)&dns_server, sizeof(dns_server)) < 0) {
        perror("sendto failed");
        exit(EXIT_FAILURE);
    }
    
    // 接收DNS服务器的响应
    socklen_t len = sizeof(dns_server);
    int recv_size = recvfrom(sockfd, response, BUF_SIZE, 0, (struct sockaddr *)&dns_server, &len);
    if (recv_size < 0) {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }
    
    // 解析响应报文并打印IP地址
    uint16_t answer_count = ntohs(*(uint16_t *)(response + 6));
    if (answer_count > 0) {
        printf("IP地址: ");
        for (int i = 0; i < recv_size; ++i) {
            if (response[i] == '\xC0') { // 指针指向标签
                uint16_t offset = ntohs(*(uint16_t *)(response + i + 1)) & 0x3FFF;
                i = offset - 1;
            } else if ((response[i] & 0xC0) == 0) { // 非压缩标签
                printf("%d", response[i]);
                if (i < recv_size - 1 && (response[i + 1] & 0xC0) == 0) printf(".");
            }
        }
        printf("\n");
    } else {
        printf("未找到该域名的IP地址\n");
    }
    
    // 关闭套接字
    close(sockfd);
    
    return 0;
}
