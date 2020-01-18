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
#define NO_PATH -1
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
        int i = myState->getState().getLeft(); // row
        int j = myState->getState().getRight(); // column

        // first check that my point o my state is not out of rows and columns.
        if ( i < 0 || j < 0 ||i >= rows || j >= columns){
            perror("Out of bounce");
            exit(1);
        }
        if(i != 0 && myMatrix[i-1][j]->getCost() != NO_PATH){
            Point newPoint(i-1,j);
            State<Point>* possibleNewState = getStateWithAPoint(newPoint);
            if(possibleNewState->getCameFrom() == nullptr){
                possibleNewState->setCameFrom(myState);
            }
            myPossibleState.push_back(possibleNewState);
        }
        if(j != 0 && myMatrix[i][j-1]->getCost() != NO_PATH){
            Point newPoint(i,j-1);
            State<Point>* possibleNewState = getStateWithAPoint(newPoint);
            if(possibleNewState->getCameFrom() == nullptr){
                possibleNewState->setCameFrom(myState);
            }
            myPossibleState.push_back(possibleNewState);
        }
        if(this->rows -1 != i && myMatrix[i+1][j]->getCost() != NO_PATH){
            Point newPoint(i+1,j);
            State<Point>* possibleNewState = getStateWithAPoint(newPoint);
            if(possibleNewState->getCameFrom() == nullptr){
                possibleNewState->setCameFrom(myState);
            }
            myPossibleState.push_back(possibleNewState);
        }
        if(this->columns -1 != j && myMatrix[i][j+1]->getCost() != NO_PATH){
            Point newPoint(i,j+1);
            State<Point>* possibleNewState = getStateWithAPoint(newPoint);
            if(possibleNewState->getCameFrom() == nullptr){
                possibleNewState->setCameFrom(myState);
            }
            myPossibleState.push_back(possibleNewState);
        }
        return myPossibleState;
    }
    State<Point>* getStateWithAPoint(Point thisPoint){
        return myMatrix[thisPoint.getLeft()][thisPoint.getRight()];
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
