/* 
 * File:   Listener.h
 * Author: daures_l
 *
 * Created on 31 janvier 2015, 23:07
 */

#ifndef LISTENER_H
#define	LISTENER_H

#include <iostream>

class Listener {
public:
    Listener();
    Listener(const Listener& orig);
    virtual ~Listener();
    void    set_fd(int);
private:
    void    Do_listen();
    int     _fd;

};

#endif	/* LISTENER_H */

