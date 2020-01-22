//
// Created by yuvallevy on 20/01/2020.
//

#include "MyParallelServer.h"

server_side::MyParallelServer::MyParallelServer(){
    this->server_socket = -1;
}

void server_side::MyParallelServer::open(int port, ClientHandler &clientHandler) {
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
    //we need to convert our number to a number that the network understands.

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
    //run the parallel server now
    runParallelServer(clientHandler);
}

void server_side::MyParallelServer::runParallelServer(ClientHandler &cHandler) {
    // initialize variables
    struct timeval timeout;
    int client_socket, clilentLen, rc;
    struct sockaddr_in cli_addr;
    clilentLen = sizeof(cli_addr);
    fd_set master_set;
    FD_ZERO(&master_set);
    FD_SET(server_socket, &master_set);
    //set the timeout
    timeout.tv_sec = 120;
    timeout.tv_usec = 0;

    while (true) {
        //start counting until timeout
        rc = select(server_socket + 1, &master_set, NULL, NULL, &timeout);
        //if we didn't reach timeout and the server socket made and action
        if (rc > 0) {
            /* Accept actual connection from the client */
            client_socket = accept(server_socket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilentLen);
            if (client_socket == -1) {
                cerr << "Error accepting Client" << std::endl;
                exit(1);
            }
            timeout.tv_sec = 120;
            runClientsWithThreads(client_socket, cHandler);
        }
        // we reached timeout
        else {
            cout<<"SERVER TIMEOUT!"<<endl;
            break;
        }
    }
        //close threads and socket
        stop();
}
//a static method that sends the problem to the clientHandler
static void handleAClient(int c_socket, ClientHandler *clientHandler) {
    //send to the clientHandler
    clientHandler->handleClient(c_socket);
}

void server_side::MyParallelServer::runClientsWithThreads(int c_socket, ClientHandler &clientHandler) {
    //adds a new thread and sends it to the handleAClient method
    this->myThreadQueue.push(thread(handleAClient, c_socket, &clientHandler));
}

void server_side::MyParallelServer::stop() {
    //close the server socket
    if(this->server_socket != -1){
        close(server_socket);
    }
    //end the threads
    while(!this->myThreadQueue.empty()) {
        this->myThreadQueue.front().join();
        this->myThreadQueue.pop();
    }
}