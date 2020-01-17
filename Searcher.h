//
// Created by pikachu on 1/17/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#pragma once
#include "ISearcher.h"
#include <queue>

template <class T> class Searcher : public ISearcher<T>{
private:
    int evaluatedNodes;
protected:
    void addNodeToEvaluatedNodes() {
        evaluatedNodes++;
    }
};


#endif //EX4_SEARCHER_H
