//
// Created by yuvallevy on 13/01/2020.
//
#pragma once

#include "sstream"
#include "fstream"
#include "istream"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <vector>
#include <thread>
#pragma once
using namespace std;
#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#endif //EX4_CLIENTHANDLER_H
using namespace std;


class ClientHandler{
private:

public:
    virtual void handleClient(int client_socket) = 0;
};