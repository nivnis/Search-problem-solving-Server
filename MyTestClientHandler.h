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
class MyTestClientHandler : public ClientHandler {
private:
    CacheManager <string, string> *myCache;
    Solver<string, string>  *solver;
public:
    MyTestClientHandler(CacheManager<string, string> *cacheManager, Solver<string, string> *solver);
    void handleClient(int client_socket) override;
    string hash_to_string(string problem);
};