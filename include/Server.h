/* 
 * File:   Server.h
 * Author: daures_l
 *
 * Created on 31 janvier 2015, 21:52
 */

#ifndef SERVER_H
#define	SERVER_H

#include    <string>

#include    "../include/Listener.h"

class Server {
public:
    Server();
    Server(const Server& orig);
    virtual ~Server();
    
    bool        Init(int);
    std::string get_etat();
    void        Run();
private:
    bool            _err;
    int             _fd_server;
    std::string     _etat;
    
    Listener    list;
};

#endif	/* SERVER_H */

