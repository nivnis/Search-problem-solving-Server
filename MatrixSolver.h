//
// Created by yuvallevy on 16/01/2020.
//

#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#pragma once
using namespace std;
class MatrixSolver : public Solver<Searchable<Point>*, string> {
private:
    Searcher<Point>* myAlgorithmSearcher;
    string returnPath(vector<State<Point>* > myPath);
    string returnNextMove(Point prevPoint ,Point thisPoint);

public:
    string solve(Searchable<Point> *problem) override;

    MatrixSolver(Searcher<Point> *myAlgorithmSearcher);

}


#endif //EX4_MATRIXSOLVER_H
