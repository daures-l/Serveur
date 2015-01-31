/* 
 * File:   Thread_manager.h
 * Author: daures_l
 *
 * Created on 31 janvier 2015, 22:28
 */

#ifndef THREAD_MANAGER_H
#define	THREAD_MANAGER_H

#include <thread>

class Thread_manager {
public:
    Thread_manager();
    Thread_manager(const Thread_manager& orig);
    virtual ~Thread_manager();
private:
    std::thread _thread;
};

#endif	/* THREAD_MANAGER_H */

