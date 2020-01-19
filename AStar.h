//
// Created by yuvallevy on 17/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H


#include "Searcher.h"
template <class T>
class Astar : public Searcher<T>{
private:
    //inner class to sort the set from lowest cost + heuristic to biggest.
    class StateComparator {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return (left->getPathCost() + left->getHeuristicDistance() > right->getPathCost()
                                                                         + right->getHeuristicDistance());
        }
    };
    double costOfThePath;
    int numberOfNodesVisitedTotal;
    State<T> *goalState, *initialState, *currState;
    set <State<T> *, StateComparator > open;
    unordered_set <State<T> *> closed;
    vector<State<T> *> path;
public:
    Astar() {
        this->costOfThePath = 0;
        this->numberOfNodesVisitedTotal = 0;
    }
    State<T>* getLowestFromOpen() {
        State<T>* state;
        state = open.begin();
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
        return s.count(wantedNode) != 0;
    }

    bool isInUnorderedSet(unordered_set <State<T> *> unorderedSet, State<T> * wantedNode) {
        return unorderedSet.count(wantedNode) != 0;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        initialState = searchable->getInitialState();
        goalState = searchable->getGoalState();
        initialState->setHeuristicDistance(searchable->findDistance(initialState, goalState));
        initialState->setCameFrom(initialState);
        open.insert(initialState);
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
                //heuristic value of the successor
                double nodeHeuristicValue = searchable->findDistance(s, goalState);
                double totalPathCost = newPathCost + nodeHeuristicValue;
                //it's the first time we meet this node (state)
                if(!isInOpen(open, s) && !isInUnorderedSet(closed, s)) {
                    s->setCameFrom(currState);
                    s->setCost(newPathCost);
                    s->setHeuristicDistance(nodeHeuristicValue);
                    open.insert(s);
                }
                //not the first time we meet this node - check if the new cost is better than the current one
                else if((s->getCost() + s->getHeuristicDistance()) > totalPathCost) {
                    s->setCost(newPathCost);
                    s->setHeuristicDistance(nodeHeuristicValue);
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

#endif //EX4_ASTAR_H