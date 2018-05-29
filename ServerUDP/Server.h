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
#include <cstring>
#include "SearchPath.h"
#include "CityConnections.h"
#include "port.h"

class Server
{
private:
    struct sockaddr_in ser_addr{};          // this address (server)
    struct sockaddr_in rem_addr{};          // remote address (client)
    socklen_t rem_len = sizeof(rem_addr);   // length of addresses
    int recvlen;                            // # bytes received
    int ser_fd, cli_fd;                     // out socket
    int msgcnt = 0;                         // messages counter
    char buf[BUFSIZE], contentBuf[BUFSIZE]; // receive buffer


public:
    Server();
};


#endif //SERVERUDP_SERVER_H
