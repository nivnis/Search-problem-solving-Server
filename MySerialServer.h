//
// Created by yuvallevy on 13/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <vector>
#include <thread>
#endif //EX4_MYSERIALSERVER_H
#include "ClientHandler.h"
#pragma once

#include "Server.h"
#include "MyTestClientHandler.h"

using namespace std;
class MySerialServer : public Server{
private:
    int port;
    int client_socket;
public:
    MySerialServer();
    void open(int port, MyTestClientHandler myTestClientHandler);
    void stop();
};