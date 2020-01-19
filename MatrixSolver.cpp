//
// Created by yuvallevy on 16/01/2020.
//

#include "MatrixSolver.h"
using namespace std;

MatrixSolver::MatrixSolver(Searcher<Point> *myAlgorithmSearcher) : myAlgorithmSearcher(myAlgorithmSearcher) {

}
// this is our Object Adopter.
string MatrixSolver::solve(Searchable<Point> *problem) {
    vector<State<Point>* > myPath;
    // calling the algorithm to solve the problem.
    myPath = this->myAlgorithmSearcher->search(problem);
    return returnPath(myPath);
}

// return a string which will show the path from the initial state to the goal as a string.
// can be: RIGHT,LET,UP,DOWN.
string MatrixSolver::returnPath(vector<State<Point> *> myPath) {
    if(myPath.empty()){
        return "No Path Found.";
    }
    string myStringSolution;
    int sizeOfPath = myPath.size();
    // going over the states.
    for(int i=0; i < sizeOfPath -1; i++){
        myStringSolution.append(returnNextMove(myPath.at(i)->getState(), myPath.at(i+1)->getState()));
        myStringSolution.append("(");
        myStringSolution.append(to_string((myPath.at(i)->getCost()+myPath.at(i+1)->getCost())));
        myStringSolution.append(")");
        myStringSolution.append(",");
    }
    myStringSolution.erase(myStringSolution.size()-1);
    return myStringSolution;
}

// return the next move as string.
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

