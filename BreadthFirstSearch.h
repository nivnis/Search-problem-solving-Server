//
// Created by yuvallevy on 17/01/2020.
//

#ifndef EX4_BREADFIRSTSEARCH_H
#define EX4_BREADFIRSTSEARCH_H

#endif //EX4_BREADFIRSTSEARCH_H

#include "Searcher.h"
template <class T>
class BreadthFirstSearch : public Searcher<T>{
private:
    double costOfThePath;
    int numberOfNodesVisitedTotal;

public:
    BreadthFirstSearch() {
        this->costOfThePath = 0;
        this->numberOfNodesVisitedTotal = 0;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        queue<State<T>* > theStateQueue;
        vector<State<T>* > myPath;
        vector<State<T>* > nodesBeenVisited;
        State<T>* initialNode = searchable->getInitialState();
        State<T>* currNode = searchable->getInitialState();
        State<T>* goalNode = searchable->getGoalState();
        currNode->setCameFrom(currNode);
        nodesBeenVisited.emplace(currNode);
        theStateQueue.push(currNode);
        while(!theStateQueue.empty()) {
            currNode = theStateQueue.front();
            theStateQueue.pop();
            this->numberOfNodesVisitedTotal = this->numberOfNodesVisitedTotal + 1;
            if (!currNode->equals_to(goalNode)) {
                // its not the goal node.
                for (State<T> *optionalNode : searchable->getAllPossibleStates(currNode)) {
                    if (thisNodeBeenVisited(nodesBeenVisited, optionalNode)) {
                        continue;
                    } else {
                        optionalNode->setCameFrom(currNode);
                        nodesBeenVisited.emplace_back(optionalNode);
                        theStateQueue.push(optionalNode);
                    }
                }
            } else {
                this->costOfThePath = costOfThePath + currNode->getCost();
                myPath.push_back(currNode);
                for (int i = 0; i < theStateQueue.size(); i++) {
                    if (currNode->equals_to(initialNode)) {
                        return myPath;
                    } else {
                        currNode = currNode->getCameFrom();
                        this->costOfThePath = this->costOfThePath + currNode->getCost();
                        myPath.push_back(currNode);
                    }
                }
            }
        }
        // no path;
        return myPath;
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