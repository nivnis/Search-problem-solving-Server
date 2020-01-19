//
// Created by yuvallevy on 18/01/2020.
//

#ifndef EX4_MYMATRIXCLIENTHANDLER_H
#define EX4_MYMATRIXCLIENTHANDLER_H

#pragma once
#include "ClientHandler.h"
#include "FileCacheManager.h"
#include "MatrixSolver.h"
#include "Solver.h"
#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;
class MyMatrixClientHandler : public ClientHandler {
private:
    CacheManager <string, string> *myCache;
    MatrixSolver* matrixSolver;
    string theProbAsOnlyString;
    string solutionMatrixNameFile = "MatrixSolutions.txt";

public:
    MyMatrixClientHandler(MatrixSolver* matrixSolver1);
//    MyMatrixClientHandler(const MatrixSolver& copyMatrixSolver1);
    void handleClient(int client_socket) override;
    Matrix* createMatrix(vector<string> problemString);
    vector<string> readFromBuffer(int client_socket);
    string removeSpaces(string input);
    vector<int> divideStringByComma(string lineMatrix);
};


#endif //EX4_MYMATRIXCLIENTHANDLER_H
