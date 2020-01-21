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
#include "ClientHandler.h"
#pragma once

#include "Server.h"
#include "MyTestClientHandler.h"

using namespace std;
namespace server_side {
    class MySerialServer : public Server {
    private:
        int port;
        int client_socket;
    public:
        MySerialServer();

        void open(int port, ClientHandler &myTestClientHandler) override;

        void stop();
    };
}
#endif //EX4_MYSERIALSERVER_H