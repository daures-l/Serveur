/* 
 * File:   Thread_manager.h
 * Author: daures_l
 *
 * Created on 31 janvier 2015, 22:28
 */

#ifndef THREAD_MANAGER_H
#define	THREAD_MANAGER_H

#include <thread>
#include <mutex>
#include <string>

class Thread_manager {
public:
    Thread_manager();
    Thread_manager(const Thread_manager& orig);
    virtual         ~Thread_manager();
    std::string     get_etat();
    void            Join();
    
protected:
    std::thread     _thread;
    std::mutex      _mutex;
    std::string     _etat;
};

#endif	/* THREAD_MANAGER_H */

