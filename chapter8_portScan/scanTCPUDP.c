#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int scan_tcp_port(const char *ip, int port) {
    struct sockaddr_in target;
    int sock;
    int result;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    result = connect(sock, (struct sockaddr *)&target, sizeof(target));
    close(sock);

    return result;
}

int scan_udp_port(const char *ip, int port) {
    struct sockaddr_in target;
    int sock;
    int result;
    char buffer[1];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    result = sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&target, sizeof(target));
    close(sock);

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    printf("Scanning TCP and UDP ports on %s...\n", ip);

    for (int port = 1; port <= 65535; port++) {
        if (scan_tcp_port(ip, port) == 0) {
            printf("TCP Port %d is open.\n", port);
        }

        if (scan_udp_port(ip, port) == 0) {
            printf("UDP Port %d may be open.\n", port);
        }
    }

    return 0;
}
