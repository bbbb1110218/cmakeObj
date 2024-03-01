#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DNS_SERVER_IP "119.29.29.29"
#define DNS_SERVER_PORT 53
#define MAX_BUF_SIZE 512

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char sendbuf[MAX_BUF_SIZE];
    char recvbuf[MAX_BUF_SIZE];
    int n;

    // 创建UDP套接字
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(DNS_SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(DNS_SERVER_IP);

    // 构造DNS查询报文
    memset(sendbuf, 0, MAX_BUF_SIZE);
    sendbuf[0] = 0x12;  // ID
    sendbuf[1] = 0x34;
    sendbuf[2] = 0x01;  // Flags: standard query
    sendbuf[3] = 0x00;
    sendbuf[4] = 0x00;  // Questions: 1
    sendbuf[5] = 0x01;
    sendbuf[6] = 0x00;  // Answer RRs: 0
    sendbuf[7] = 0x00;
    sendbuf[8] = 0x00;  // Authority RRs: 0
    sendbuf[9] = 0x00;
    sendbuf[10] = 0x00;  // Additional RRs: 0
    sendbuf[11] = 0x00;
    // Query for www.baidu.com
    sendbuf[12] = 0x03;  // Length of "www"
    strcpy(sendbuf + 13, "www");
    sendbuf[17] = 0x05;  // Length of "baidu"
    strcpy(sendbuf + 18, "baidu");
    sendbuf[24] = 0x03;  // Length of "com"
    strcpy(sendbuf + 25, "com");
    sendbuf[29] = 0x00;  // End of domain name
    sendbuf[30] = 0x00;  // Type: A
    sendbuf[31] = 0x01;
    sendbuf[32] = 0x00;  // Class: IN
    sendbuf[33] = 0x01;

    // 发送DNS查询
    sendto(sockfd, sendbuf, 34, 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    // 接收DNS响应
    n = recvfrom(sockfd, recvbuf, MAX_BUF_SIZE, 0, NULL, NULL);
    if (n < 0) {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }

    // 打印响应报文
    for (int i = 0; i < n; i++) {
        printf("%02x ", (unsigned char)recvbuf[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    close(sockfd);
    return 0;
}