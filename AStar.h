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
    //inner class to sort the priority queue from lowest cost + heuristic to biggest.
    class StateComparator {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return (left->getPathCost() + left->getDistanceTillState() > right->getPathCost()
            + right->getDistanceTillState());
        }
    };
    double costOfThePath;
    int numberOfNodesVisitedTotal;
    State<T> *goalState, *initialState, *currState;
    priority_queue<State<T> *, vector<State<T> *>, StateComparator> open;
    unordered_set <State<T> *> closed;
    vector<State<T> *> path;
public:
    Astar() {
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
    }

    bool isInPriorityQueue( priority_queue<State<T> *, vector<State<T> *>, StateComparator> pq, State<T> * wantedNode) {
        while (!pq.empty()) {
            if(pq.top()->equals_to(wantedNode)) {
                return true;
            }
            pq.pop();
        }
        return false;
    }

    bool isInUnorderedSet(unordered_set <State<T> *> unorderedSet, State<T> * wantedNode) {
        return unorderedSet.count(wantedNode) != 0;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        initialState = searchable->getInitialState();
        goalState = searchable->getGoalState();
        initialState->setDistanceTillState(searchable->findDistance(initialState, goalState));
        initialState->setCameFrom(initialState);
        open.push(initialState);
        while (open.size() > 0) {
            currState = popFromOpen();
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
                if(!isInPriorityQueue(open, s) && !isInUnorderedSet(closed, s)) {
                    s->setCameFrom(currState);
                    s->setCost(newPathCost);
                    s->setDistanceTillState(nodeHeuristicValue);
                    open.emplace(s);
                }
                //not the first time we meet this node - check if the new cost is better than the current one
                else if((s->getCost() + s->getDistanceTillState()) > totalPathCost) {
                    s->setCost(newPathCost);
                    s->setDistanceTillState(nodeHeuristicValue);
                    s->setCameFrom(currState);
                    open.emplace(s);
                }
            }
        }
        return path;
    }

    double getCostOfThePath() const {
        return costOfThePath;
    }

    int getNumberOfNodesVisitedTotal() const {
        return numberOfNodesVisitedTotal;
    }

};