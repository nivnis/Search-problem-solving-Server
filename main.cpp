#include <iostream>
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "MatrixSolver.h"
#include "BreadthFirstSearch.h"
#include "MyMatrixClientHandler.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "MyParallelServer.h"

using namespace std;

#include <set>
int main() {

    Searcher<Point> *searchAlgorithm = new AStar<Point>();
    MatrixSolver matrixSolver(searchAlgorithm);
    FileCacheManager<string,string> cacheManager("MatrixSolutions.txt");
    MyMatrixClientHandler matrixClientHandler(&matrixSolver, &cacheManager);
    MyMatrixClientHandler matrixClientHandler1(matrixClientHandler);
    MyParallelServer parallelServer;
    parallelServer.open(5600, matrixClientHandler);
    delete(searchAlgorithm);
    return 0;


//    Searcher<Point> *searchAlgorithm = new AStar<Point>();
//    MatrixSolver matrixSolver(searchAlgorithm);
//    FileCacheManager<string,string> cacheManager("MatrixSolutions.txt");
//    MyMatrixClientHandler matrixClientHandler(&matrixSolver, &cacheManager);
//    MyMatrixClientHandler matrixClientHandler1(matrixClientHandler);
//    MyParallelServer parallelServer;
//    parallelServer.open(5600, matrixClientHandler);
//    delete(searchAlgorithm);
//    return 0;
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