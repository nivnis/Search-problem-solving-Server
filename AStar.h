//
// Created by yuvallevy on 17/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#endif //EX4_ASTAR_H

#include "Searcher.h"
template <class T>
class Astar : public Searcher<T>{

private:
    double costOfThePath;
    int numberOfNodesVisitedTotal;
    pri
public:

    vector<State<T> *> search(Searchable<T> *searchable) override {

    }

    double getNumOfNodesEvaluated() override {
        return this->numberOfNodesVisitedTotal;
    }

    double getTheCostOfPath() override {
        this->costOfThePath;
    }
    bool thisNodeBeenVisited(vector<State<T>*> nodesBeenVisited, State<T>* currNode){
        for(State<T>* node : nodesBeenVisited) {
            if (node->equals_to(currNode)) {
                return true;
            }
        }
        return false;
    }

};