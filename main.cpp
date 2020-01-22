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
#define default_portNum 5600
using namespace std;

namespace boot{
    class Main{
    public:
        int main(int argc,char** argv){
            int portNum;
            if(argc > 1){
                portNum = stoi(argv[1]);
            } else {
                portNum = default_portNum;
            }
            Searcher<Point> *searchAlgorithm = new AStar<Point>();
            MatrixSolver matrixSolver(searchAlgorithm);
            FileCacheManager<string,string> cacheManager("MatrixSolutions.txt");
            MyMatrixClientHandler matrixClientHandler(&matrixSolver, &cacheManager);
            MyMatrixClientHandler matrixClientHandler1(matrixClientHandler);
            server_side::MyParallelServer parallelServer;
            parallelServer.open(portNum, matrixClientHandler);
            delete(searchAlgorithm);
            return 0;
        }
    };
}

int main(int argc,char** argv) {
    boot::Main bootMain;
    bootMain.main(argc,argv);
    return 0;
}
