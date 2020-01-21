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

namespace boot{
    class Main{
    public:
        int main(int argc,char** argv){
            if(argc <= 1){
                perror("ERROR: No port was inserted");
                return 0;
            }
            int portNum = stoi(argv[1]);
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
