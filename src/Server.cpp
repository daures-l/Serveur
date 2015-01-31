/* 
 * File:   Server.cpp
 * Author: daures_l
 * 
 * Created on 31 janvier 2015, 21:52
 */

#include "../include/Server.h"
#include <string>
#include <iostream>


#include <netinet/in.h>

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
    if (_err)
    {
        _etat.assign("Init Fail");
        return false;
    }
    
    _etat.assign("Init OK");
    return true;
}

std::string Server::get_etat()
{
    return _etat;
}

void        Server::Run()
{
    bool    exit = true;
    std::string	buf;
    
    while (exit)
    {
        buf.clear();
        std::getline(std::cin, buf);

        if (buf.compare("exit") == 0)
            exit = false;
        else if (!buf.compare("etat"))
            std::cout << get_etat() << std::endl;
    }
}