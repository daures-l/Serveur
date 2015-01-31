/* 
 * File:   Thread_manager.cpp
 * Author: daures_l
 * 
 * Created on 31 janvier 2015, 22:28
 */

#include "../include/Thread_manager.h"

Thread_manager::Thread_manager() {
}

Thread_manager::Thread_manager(const Thread_manager& orig) {
}

Thread_manager::~Thread_manager() {
}
/*
void    Thread_manager::Run()
{
    _thread = std::thread(std::bind(&Thread_ctrl::Do_CTRL, this));
}*/

std::string Thread_manager::get_etat()
{
    return _etat;
}

void        Thread_manager::Join()
{
    _thread.join();
}