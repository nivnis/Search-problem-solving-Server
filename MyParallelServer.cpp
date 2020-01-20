////
//// Created by yuvallevy on 20/01/2020.
////
//
//#include "MyParallelServer.h"
//
//MyParallelServer::MyParallelServer(){
//    this->client_socket = -1;
//}
//void MyParallelServer::open(int port, ClientHandler &clientHandler) {
//    this->port = port;
//    int timeout_in_seconds = 240.0;
////create socket
//    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
//    if (socketfd == -1) {
//        //error
//        std::cerr << "Could not create a socket"<<std::endl;
//        exit(1);
//    }
//
//    //bind socket to IP address
//    // we first need to create the sockaddr obj.
//    sockaddr_in address; //in means IP4
//    address.sin_family = AF_INET;
//    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
//    address.sin_port = htons(port);
//    //we need to convert our number
//    // to a number that the network understands.
//
//    //the actual bind command
//    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
//        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
//        exit(1);
//    }
//    //making socket listen to the port
//    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
//        std::cerr<<"Error during listening command"<<std::endl;
//        exit(1);
//    } else{
//        std::cout<<"Server is now listening ..."<<std::endl;
//    }
//    this->client_socket = socketfd;
//
//    // from here we start the clients.
//    while(true) {
//        struct timeval tv;
//        tv.tv_sec = timeout_in_seconds;
//        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
//        int newSocket;
//        // accepting a Client
////        listen(client_socket, 24000);
//        int addrlen = sizeof(address);
//        newSocket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
//        if (newSocket == -1) {
//            std::cerr << "Error accepting Client" << std::endl;
//            exit(1);
//        }
//
//
//        this->myThreadQueue.push(thread(clientHandler->handleClient(newSocket), newSocket))
//
//    }
//    // finish.
//    stop();
//
//}
//
//void MyParallelServer::stop() {
//    if(this->client_socket != -1){
//        close(client_socket);
//    }
//    while(!this->myThreadQueue.empty()){
//        this->myThreadQueue.front().join();
//        this->myThreadQueue.pop();
//    }
//}
