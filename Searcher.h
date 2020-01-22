//
// Created by pikachu on 1/17/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#pragma once
#include <queue>
#include <unordered_set>
#include "State.h"
#include "Searchable.h"
#include <set>
#include <iterator>

template <class T> class Searcher{
private:
//    int evaluatedNodes;
public:
    virtual vector<State<T>* > search(Searchable<T> *searchable) = 0;
    virtual ~Searcher() = default;
    virtual double getNumOfNodesEvaluated() = 0;
    virtual double getTheCostOfPath() = 0;
    //checks if the wanted wantedNode is in the vector
    bool hasNodeBeenVisited(vector<State<T> *> nodesVector, State<T> *wantedNode) {
        for (State<T> *state : nodesVector) {
            if (state->equals_to(wantedNode)) {
                return true;
            }
        }
        return false;
    }
};


#endif //EX4_SEARCHER_H
