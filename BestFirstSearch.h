//
// Created by pikachu on 1/16/20.
//
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <queue>
#include <hash_set>
#include "PriorityQueueSearcher.h"
using namespace __gnu_cxx; // for hash_set


template<class T>
class BestFirstSearch : public PriorityQueueSearcher<T> {
public:
    vector<State<T> *> search(Searchable<T> *searchable) override {
        addToOpenPriorityQueue(searchable->getInitialState());
        hash_set <State<T>> closeHashSet = new hash_set<State<T>>();

        return vector<State<T> *>();
    }


};



















#endif //EX4_BESTFIRSTSEARCH_H

