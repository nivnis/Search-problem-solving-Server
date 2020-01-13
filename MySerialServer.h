//
// Created by yuvallevy on 13/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#endif //EX4_MYSERIALSERVER_H
#include "ClientHandler.h"

#include "Server.h"
using namespace std;
class MySerialServer : public Server{
private:

public:
    void open(int port, ClientHandler clientHandler);
    void stop();

};