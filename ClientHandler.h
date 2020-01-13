//
// Created by yuvallevy on 13/01/2020.
//
#pragma once

#include "sstream"
#include "fstream"
#include "istream"
#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#endif //EX4_CLIENTHANDLER_H
using namespace std;


class ClientHandler{
private:

public:
    virtual void handleClient(int socket);
};