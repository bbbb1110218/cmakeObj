#ifndef __T_SOCKET_H__
#define __T_SOCKET_H__

 #include <sys/socket.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <netinet/in.h>
  #include <arpa/inet.h>

// 新建socket
// int t_socket(int domain, int type, int protocol);



int Q_getUdpSocket();


// 不阻塞试试 return 0 success -1 failed
int set_socket_unblock(int sockfd);



// // 绑定socket
// upd Don't need bind
// int t_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);



struct sockaddr_in *t_bindServerAddr(const char *ip,int port);


#endif 