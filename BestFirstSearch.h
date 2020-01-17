//
// Created by pikachu on 1/16/20.
//
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "Searcher.h"

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    //inner class to sort the priority queue from lowest cost to biggest.
    class StateComparator {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return (left->getPathCost() > right->getPathCost());
        }
    };
    double costOfThePath;
    int numberOfNodesVisitedTotal;
    State<T> *goalState, *initialState, *currState;
    priority_queue<State<T> *, vector<State<T> *>, StateComparator> open;
    hash_set <State<T> *> closed;
    vector<State<T> *> path;
public:
    BestFirstSearch() {
        this->costOfThePath = 0;
        this->numberOfNodesVisitedTotal = 0;
    }
    State<T>* popFromOpen() {
        State<T>* state;
        state = open.top();
        open.pop();
        //here i should increase the num of nodes evaluated
        numberOfNodesVisitedTotal++;
        return state;
    }

    void backTrace() {
        costOfThePath += currState->getCost();
        path.insert(path.begin(), currState);
        while(!currState->equals_to(initialState)) {
            currState = currState->getCameFrom();
            costOfThePath += currState->getCost();
            path.insert(path.begin(), currState);
        }
    };

    vector<State<T> *> search(Searchable<T> *searchable) override {
        initialState = searchable->getInitialState();
        goalState = searchable->getGoalState();
        open.push(initialState);
        initialState->setCameFrom(initialState);
        while (open.size() > 0) {
            currState = popFromOpen();
            closed.insert(currState);
            //if we reached the goalState
            if(currState->equals_to(goalState)) {
                backTrace();
                return path;
            }
        }
        return vector<State<T> *>();
    }
    //HERE I SHOULD GO TO SUCCESSORS AND KEEP GOING


};



















#endif //EX4_BESTFIRSTSEARCH_H

