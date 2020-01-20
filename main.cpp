#include <iostream>
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "MatrixSolver.h"
#include "BreadthFirstSearch.h"
#include "MyMatrixClientHandler.h"
#include "BestFirstSearch.h"
#include "DepthFirstSearch.h"
#include "AStar.h"

using namespace std;

#include <set>
int main() {
    Server* server = new MySerialServer();
    Searcher<Point>* algorithm = new DepthFirstSearch<Point>();
    MatrixSolver* matrixSolver = new MatrixSolver(algorithm);
    MyMatrixClientHandler* myMatrixClientHandler = new MyMatrixClientHandler(matrixSolver);
//    Server *server = new MySerialServer();
    server->open(5605, myMatrixClientHandler);
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