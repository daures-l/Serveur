/* 
 * File:   main.cpp
 * Author: daures_l
 *
 * Created on 31 janvier 2015, 21:46
 */

#include <iostream>
#include "../include/Server.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc < 2)
        std::cout << "./serveur [port]" << std::endl;
    
    Server  server;
    
    server.Init(5050);
    std::cout << "etat du server [" << server.get_etat() << "]" << std::endl;
    std::cout << "ac " << argc << std::endl;
    return 0;
}

