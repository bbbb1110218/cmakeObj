#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>



int scan_port(const char *ip, int port) {
    struct sockaddr_in target;
    int sock;
    int result;

    // 创建socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // 设置目标地址和端口
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    // 尝试连接
    //connect连接成功返回0，失败返回-1
    result = connect(sock, (struct sockaddr *)&target, sizeof(target));
    close(sock);

    return result;
}

int main(int argc, char *argv[]) {
    if(strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--help")==0 ||strcmp(argv[1],"-H")==0 || strcmp(argv[1],"-help")==0 ){
        printf("测试TCP是否开放\n");
        printf("Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    if(ip[0]<'0' || ip[0]>'9'){
        fprintf(stderr,"IP地址格式错误:not >>>>> [%s]\n",argv[0]);
        return -1;
    }
    printf("Scanning ports on %s...\n", ip);

    for (int port = 1; port <= 65535; port++) {
        if (scan_port(ip, port) == 0) {
            printf("Port %d is open.\n", port);
        }
    }

    return 0;
}
