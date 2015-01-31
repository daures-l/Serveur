/* 
 * File:   Listener.cpp
 * Author: daures_l
 * 
 * Created on 31 janvier 2015, 23:07
 */

#include "../include/Listener.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

Listener::Listener() {
}

Listener::Listener(const Listener& orig) {
}

Listener::~Listener() {
}
void    Listener::set_fd(int fd)
{
    _fd = fd;
}

void    Listener::Do_listen()
{
    sockaddr_in addr_cl;
    socklen_t   len = sizeof(addr_cl);
    int         fd_cl;
    
    
    fd_cl = accept(_fd, (struct sockaddr*) &addr_cl, &len); 
    if (fd_cl == -1)
        std::cout << "err accept Listener::Do_listen" << std::endl;
    std::cout   << "User co !" << inet_ntoa(addr_cl.sin_addr) << std::endl;

}
