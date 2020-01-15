//
// Created by yuvallevy on 15/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#endif //EX4_SEARCHABLE_H


#pragma once
#include "State.h"
#include <vector>
#include <string>
using namespace std;


template <class T> class Searchable{
public:

    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>* myState) = 0;
};