//
// Created by yuvallevy on 13/01/2020.
#include "MySerialServer.h"

MySerialServer::MySerialServer(){

}

void MySerialServer::open(int port, ClientHandler *myTestClientHandler){
    int timeout_in_seconds = 120;
    this->port = port;
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

//    //making socket listen to the port
//    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
//        std::cerr<<"Error during listening command"<<std::endl;
//        exit(1);
//    } else{
//        std::cout<<"Server is now listening ..."<<std::endl;
//    }

    while(true) {
        //timeout condition
        struct timeval tv;
        tv.tv_sec = timeout_in_seconds;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

        //making socket listen to the port
        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            std::cerr<<"Error during listening command"<<std::endl;
            exit(1);
        } else{
            std::cout<<"Server is now listening ..."<<std::endl;
        }

        // accepting a Client
//        listen(client_socket, 24000);
        int addrlen = sizeof(address);
        client_socket = accept(socketfd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_socket == -1) {
            std::cerr<<"Error accepting Client"<<std::endl;
            exit(1);
        }

        myTestClientHandler->handleClient(client_socket);
        close(client_socket); //closing the listening socket
    }
}


void MySerialServer::stop(){

}