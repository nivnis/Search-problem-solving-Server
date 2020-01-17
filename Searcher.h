//
// Created by pikachu on 1/17/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#pragma once
#include <queue>
#include <hash_set>
#include "State.h"
#include "Searchable.h"
using namespace __gnu_cxx; // for hash_set

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
