#include <iostream>
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "MatrixSolver.h"
#include "BreadthFirstSearch.h"
#include "MyMatrixClientHandler.h"

using namespace std;

int main() {
    Server* server = new MySerialServer();
    Searcher<Point>* algorithm = new BreadthFirstSearch<Point>();
    MatrixSolver* matrixSolver = new MatrixSolver(algorithm);
    MyMatrixClientHandler* myMatrixClientHandler = new MyMatrixClientHandler(matrixSolver);
//    Server *server = new MySerialServer();
    server->open(5610, myMatrixClientHandler);
    return 0;
}

//
//
//Server* server = new MySerialServer();
//CacheManager<string, string> *cacheManager = new FileCacheManager<string, string>("stringSolution.txt");
//Solver<string, string> *solver = new StringReverser();
//ClientHandler *clientHandler = new MyTestClientHandler(cacheManager, solver);
////    Server *server = new MySerialServer();
//server->open(5600, clientHandler);
//return 0;