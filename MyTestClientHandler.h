//
// Created by yuvallevy on 13/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#endif //EX4_MYTESTCLIENTHANDLER_H
#pragma once
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <iostream>
#include <fstream>


using namespace std;
class MyTestClientHandler : public ClientHandler{
private:
    Solver solver;
    CacheManager myCache;
public:
    MyTestClientHandler();
    void handleClient(int socket);

};