//TODO::NEEDMotify
#include "../include/Qsocket.h"



int Q_getUdpSocket(){
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return fd;

}


// 不阻塞试试 return 0 success -1 failed
int set_socket_unblock(int sockfd){
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl F_GETFL failed");
        return -1;
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("fcntl F_SETFL failed");
        return -1;
    }
    return 0;
}



// // 绑定socket
// upd Don't need bind
// int t_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);



struct sockaddr_in *t_bindServerAddr(const char *ip,int port){
    struct sockaddr_in *addr=(struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    memset(addr,0,sizeof(struct sockaddr_in));
    addr->sin_family=AF_INET;
    addr->sin_addr.s_addr=inet_addr(ip);
    addr->sin_port=htons(port);
    return addr;
}