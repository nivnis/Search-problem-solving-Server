//
// Created by yuvallevy on 13/01/2020.
//
#pragma once
#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#endif //EX4_SERVER_H

#include "ClientHandler.h"
using namespace std;
namespace side_server {
class Server;
}
class side_server::Server {
private:
    int port;
public:
    virtual void open(int port, ClientHandler clientHandler) = 0;
    virtual void stop() = 0;
};