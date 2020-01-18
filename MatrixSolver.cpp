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
        return "No Path Found.";
    }
    string myStringSolution;
    int sizeOfPath = myPath.size();
    for(int i=0; i < sizeOfPath -1; i++){
        myStringSolution.append(returnNextMove(myPath.at(i)->getState(), myPath.at(i+1)->getState()));
        myStringSolution.append(",");
    }
    myStringSolution.erase(myStringSolution.size()-1);
    return myStringSolution;
}

// return the next move in string.
string MatrixSolver::returnNextMove(Point prevPoint, Point thisPoint) {
    int prevLeft = prevPoint.getX();
    int prevRight = prevPoint.getY();
    int currLeft = thisPoint.getX();
    int currRight = thisPoint.getY();
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

