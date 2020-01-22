//
// Created by yuvallevy on 13/01/2020.
#include "MySerialServer.h"

server_side::MySerialServer::MySerialServer(){}

void server_side::MySerialServer::open(int port, ClientHandler &myTestClientHandler){
    int timeout_in_seconds = 120;
    //this->port = port;
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
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        exit(1);
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }

    struct timeval timeout;
    int client_socket, clilentLen, rc;
    struct sockaddr_in cli_addr;
    clilentLen = sizeof(cli_addr);
    fd_set master_set;
    FD_ZERO(&master_set);
    FD_SET(socketfd, &master_set);
    //set the timeout
    timeout.tv_sec = timeout_in_seconds;
    timeout.tv_usec = 0;

    while (true) {
        //start counting until timeout
        rc = select(socketfd + 1, &master_set, NULL, NULL, &timeout);
        //if we didn't reach timeout and the server socket made and action
        if (rc > 0) {
            // accepting a Client
            int addrlen = sizeof(address);
            client_socket = accept(socketfd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
            if (client_socket == -1) {
                std::cerr<<"Error accepting Client"<<std::endl;
                exit(1);
            }
            timeout.tv_sec = timeout_in_seconds;
            myTestClientHandler.handleClient(client_socket);
            close(client_socket); //closing the listening socket
        }
        else {
            cout<<"SERVER TIMEOUT!"<<endl;
            stop();
            break;
        }
    }
}

void server_side::MySerialServer::stop(){

}