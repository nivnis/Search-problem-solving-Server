//
// Created by pikachu on 1/16/20.
//
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H
#pragma once
#include "Searcher.h"

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    //inner class to sort the ordered set from lowest cost to biggest.
    class StateComparator {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return (left->getCost() < right->getCost());
        }

    };
    double costOfThePath;
    int numberOfNodesVisitedTotal;
    State<T> *goalState, *initialState, *currState;
    set <State<T> *, StateComparator > open;
    unordered_set <State<T> *> closed;
    vector<State<T> *> path;
public:
    BestFirstSearch() {
        this->costOfThePath = 0;
        this->numberOfNodesVisitedTotal = 0;
    }

    State<T>* getLowestFromOpen() {
        State<T>* state;
        state = *open.begin();
        open.erase(state);
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
    }

    bool isInOpen(set <State<T> *, StateComparator > s, State<T> * wantedNode) {
        //return s.count(wantedNode) != 0;
        return s.find(wantedNode) != s.end();
    }

    bool isInUnorderedSet(unordered_set <State<T> *> unorderedSet, State<T> * wantedNode) {
        return unorderedSet.find(wantedNode) != unorderedSet.end();
    }


    vector<State<T> *> search(Searchable<T> *searchable) override {
        initialState = searchable->getInitialState();
        goalState = searchable->getGoalState();
        open.insert(initialState);
        initialState->setCameFrom(initialState);

        while (!open.empty()) {
            currState = getLowestFromOpen();
            closed.insert(currState);
            //if we reached the goalState
            if(searchable->isGoal(currState)) {
                backTrace();
                return path;
            }

            //HERE I SHOULD GO TO SUCCESSORS AND KEEP GOING
            vector<State<T>*> successors = searchable->getAllPossibleStates(currState);
            for(State<T> * s : successors) {
                double newPathCost = currState->getCost() + s->getCost();
                //it's the first time we meet this node (state)
                if(!isInOpen(open, s) && !isInUnorderedSet(closed, s)) {
                    s->setCameFrom(currState);
                    s->setCost(newPathCost);
                    open.insert(s);
                }
                //not the first time we meet this node - check if the new cost is better than the current one
                else if(s->getCost() > newPathCost) {
                    s->setCost(newPathCost);
                    s->setCameFrom(currState);
                    open.insert(s);
                }
            }
        }
        return path;
    }

    double getNumOfNodesEvaluated() override {
        return numberOfNodesVisitedTotal;
    }

    double getTheCostOfPath() override {
        return costOfThePath;
    }

};



















#endif //EX4_BESTFIRSTSEARCH_H

