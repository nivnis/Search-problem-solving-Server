//
// Created by yuvallevy on 16/01/2020.
//

#include "MatrixSolver.h"
using namespace std;

MatrixSolver::MatrixSolver(Searcher<Point> *myAlgorithmSearcher) : myAlgorithmSearcher(myAlgorithmSearcher) {

}

string MatrixSolver::solve(Searchable<Point> *problem) {
    vector<State<Point>* > myPath;
    myPath = this->myAlgorithmSearcher->search(problem);
    return returnPath(myPath);
}

string MatrixSolver::returnPath(vector<State<Point> *> myPath) {
    if(myPath.empty()){
        return "-1";
    }
    string myStringSolution;
    int sizeOfPath = myPath.size();
    for(int i=0; i < sizeOfPath; i++){
        myStringSolution.append(returnNextMove(myPath.at(i)->getState(), myPath.at(i+1)->getState()));
        myStringSolution.append(",");
    }
    return myStringSolution;
}

// return the next move in string.
string MatrixSolver::returnNextMove(Point prevPoint, Point thisPoint) {
    int prevLeft = prevPoint.getLeft();
    int prevRight = prevPoint.getRight();
    int currLeft = thisPoint.getLeft();
    int currRight = thisPoint.getRight();
    if(prevLeft < currLeft){
        return "DOWN";
    } else if (prevLeft > currLeft){
        return "UP";
    } else if (prevRight < currRight){
        return "RIGHT";
    } else{
        return "LEFT";
    }
}

