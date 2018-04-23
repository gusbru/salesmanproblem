//
// Created by Gustavo Brunetto on 23/04/18.
//

#ifndef SERVERUDP_SERVER_H
#define SERVERUDP_SERVER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "port.h"
#define BUFSIZE 2048

class Server
{
private:
    struct sockaddr_in myaddr{};          // this address (server)
    struct sockaddr_in remaddr{};         // remote address (client)
    socklen_t addrlen = sizeof(remaddr);  // length of addresses
    int recvlen;                          // # bytes received
    int fd;                               // out socket
    int msgcnt = 0;                       // messages counter
    char buf[BUFSIZE];           // receive buffer


public:
    Server();
};


#endif //SERVERUDP_SERVER_H
