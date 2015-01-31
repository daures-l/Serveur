/* 
 * File:   Server.cpp
 * Author: daures_l
 * 
 * Created on 31 janvier 2015, 21:52
 */

#include "../include/Server.h"
#include <string>
#include <iostream>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <resolv.h>
#include "openssl/ssl.h"
#include "openssl/err.h"

Server::Server() {
}

Server::Server(const Server& orig) {
}

Server::~Server() {
}

bool    Server::Init(int port)
{
    int fd_server;
    sockaddr_in addr;

    _err  = false;
    _etat.assign("Init :");
    _fd_server = socket(PF_INET, SOCK_STREAM, 0);
    
    //bzero(&addr, sizeof(addr));
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    _etat.append("bind / listen");
    if ( bind(_fd_server, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        std::cout << "can't bind port" << std::endl;
        _err = true;
    }
    if (listen(_fd_server, 10) != 0 )
    {
        std::cout << "Can't configure listening port" << std::endl;
        _err = true;
    }
    _etat.assign("Init OK");
    
    
    
    /*
    
        while (1) {
            struct sockaddr_in addr;
            socklen_t len = sizeof (addr);
            SSL *ssl;

            int client = accept(server, (struct sockaddr*) &addr, &len); 
            printf("Connection: %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
            ssl = SSL_new(ctx); 
            SSL_set_fd(ssl, client); 
            Servlet(ssl); }
        close(server);
        SSL_CTX_free(ctx);
        */
}

std::string Server::get_etat()
{
    return _etat;
}