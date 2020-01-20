//
// Created by yuvallevy on 20/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <vector>
#include <thread>
#include "Server.h"
#include <queue>
#include "MyTestClientHandler.h"

class MyParallelServer : public Server{
private:
    queue<thread> myThreadQueue;
    int server_socket;
public:
    MyParallelServer();
    void open(int port, ClientHandler &clientHandler) override;
    void stop() override;
    void runParallelServer(ClientHandler &cHandler);
    void runClientsWithThreads(int c_socket, ClientHandler &clientHandler);

};

#endif //EX4_MYPARALLELSERVER_H
