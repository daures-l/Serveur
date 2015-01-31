/* 
 * File:   main.cpp
 * Author: daures_l
 *
 * Created on 31 janvier 2015, 21:46
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc < 2)
        std::cout << "./serveur [port]" << std::endl;
    
    std::cout << "ac " << argc << std::endl;
    return 0;
}

