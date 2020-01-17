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

template <class T> class Searcher{
private:
//    int evaluatedNodes;
public:
    virtual vector<State<T>* > search(Searchable<T> *searchable) = 0;
    virtual double getNumOfNodesEvaluated() = 0;
    virtual double getTheCostOfPath() = 0;
//    void addNodeToEvaluatedNodes() {
//        evaluatedNodes++;
//    }
};


#endif //EX4_SEARCHER_H
