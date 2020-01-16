//
// Created by yuvallevy on 16/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#pragma once
#include "State.h"
#include "Searchable.h"
#include "Point.h"
#include <vector>
using namespace std;


class Matrix : public Searchable<Point> {

private:
    vector<vector<State<Point>* >> myMatrix;
    State<Point> *initialState;
    State<Point> *goalState;
    int rows;
    int columns;

public:
    Matrix(Point initialPoint, Point goalPoint, vector<vector<State<Point>* >> matrix){
        this->initialState = new State<Point>(initialPoint);
        this->goalState = new State<Point>(goalPoint);
        this->myMatrix = matrix;
        this->rows = matrix.size();
        this->columns = matrix[0].size();
    }

    State<Point> *getInitialState() override{
        return this->initialState;
    }

    State<Point> *getGoalState() override{
        return this->goalState;
    }

    vector<State<Point> *> getAllPossibleStates(State<Point> *myState) override {
        vector<State<Point>*> myPossibleState;
        int i = myState->getState().getLeft();
        int j = myState->getState().getRight();

        // first check that my point o my state is not out of rows and columns.
        if
    }


    bool isGoal(State<Point>* myState){
        return this->goalState == myState;
    }

    vector<vector<State<Point>* >> &getMyMatrix(){
        return myMatrix;
    }

    int getRows() const {
        return rows;
    }

    int getColumns() const {
        return columns;
    }
};


#endif //EX4_MATRIX_H
