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

namespace server_side {
    class MyParallelServer : public Server {
    private:
        queue<thread> myThreadQueue;
        int server_socket;
    public:
        //constructor
        MyParallelServer();
        //opens server socket and listens
        void open(int port, ClientHandler &clientHandler) override;
        //closes the threads and ports.
        void stop() override;
        //run the parallel server
        void runParallelServer(ClientHandler &cHandler);
        //adds threads to the thread queue and sends them to the clienthandler
        void runClientsWithThreads(int c_socket, ClientHandler &clientHandler);

    };
}
#endif //EX4_MYPARALLELSERVER_H
