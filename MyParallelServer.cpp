//
// Created by yuvallevy on 20/01/2020.
//

#include "MyParallelServer.h"

MyParallelServer::MyParallelServer(){
    this->server_socket = -1;
}

void MyParallelServer::open(int port, ClientHandler &clientHandler) {
//create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        exit(1);
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
        exit(1);
    }
    //making socket listen to the port
    if (listen(socketfd, 20) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        exit(1);
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    this->server_socket = socketfd;
    runParallelServer(clientHandler);
}

void MyParallelServer::runParallelServer(ClientHandler &cHandler) {
    // from here we start the clients.
    int client_socket;
    int clilentLen;
    struct sockaddr_in cli_addr;
    clilentLen = sizeof(cli_addr);
    timeval timeOut;
    timeOut.tv_usec = 0;

    while(true) {
        timeOut.tv_sec = 0;

        /* Accept actual connection from the client */
        client_socket = accept(server_socket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilentLen);
        if (client_socket == -1) {
            //if we reached timeout we stop the server
            if (errno == EWOULDBLOCK || errno == EAGAIN){
                break;
            }
            cerr << "Error accepting Client" << std::endl;
            exit(1);
        }

        if (setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeOut, sizeof(timeOut)) < 0)   {
            perror("ERROR on setting timeOut");
            exit(1);
        }
        runClientsWithThreads(client_socket, cHandler);

        timeOut.tv_sec = 1;

        if (setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeOut, sizeof(timeOut)) < 0)   {
            perror("ERROR on setting timeOut");
            exit(1);
        }
    }
    stop();
}

static void handleAClient(int c_socket, ClientHandler *clientHandler) {
    clientHandler->handleClient(c_socket);
}

void MyParallelServer::runClientsWithThreads(int c_socket, ClientHandler &clientHandler) {
    this->myThreadQueue.push(thread(handleAClient, c_socket, &clientHandler));
}

void MyParallelServer::stop() {
    if(this->server_socket != -1){
        close(server_socket);
    }
    while(!this->myThreadQueue.empty()) {
        this->myThreadQueue.front().join();
        this->myThreadQueue.pop();
    }
}