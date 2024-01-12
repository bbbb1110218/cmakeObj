#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>

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
    result = connect(sock, (struct sockaddr *)&target, sizeof(target));
    close(sock);

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    printf("Scanning ports on %s...\n", ip);

    for (int port = 1; port <= 65535; port++) {
        if (scan_port(ip, port) == 0) {
            printf("Port %d is open.\n", port);
        }
    }

    return 0;
}
