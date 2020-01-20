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
        // queue of states which we will push and pop during the algorithm.
        queue<State<T>* > theStateQueue;
        // path of states to return.
        vector<State<T>* > myPath;
        vector<State<T>* > noPathFound;
        // vector of nodes that already been visited.
        vector<State<T>* > nodesBeenVisited;
        // create our initial state for the algorithm.
        State<T>* initialNode = searchable->getInitialState();
        // set our current node for the algorithm stars as the initial node of the problem
        State<T>* currNode = searchable->getInitialState();
        // create our goal state for the algorithm.
        State<T>* goalNode = searchable->getGoalState();
        currNode->setCameFrom(currNode);
        nodesBeenVisited.push_back(currNode);
        theStateQueue.push(currNode);
        // we will go over all the states in the queue until we finish.
        while(!theStateQueue.empty()) {
            currNode = theStateQueue.front();
            theStateQueue.pop();
            // increasing the number of node we visited in this problem by 1.
            this->numberOfNodesVisitedTotal = this->numberOfNodesVisitedTotal + 1;
            if (!currNode->equals_to(goalNode)) {
                // its not the goal state.
                // check all the neighbors of our curr node if we visited them or not.
                for (State<T> *optionalNode : searchable->getAllPossibleStates(currNode)) {
                    if (this->hasNodeBeenVisited(nodesBeenVisited, optionalNode)) {
                        continue;
                    } else {
                        // each node we didnt visit, we mark their dad node as out curr node.
                        optionalNode->setCameFrom(currNode);
                        nodesBeenVisited.emplace_back(optionalNode);
                        theStateQueue.push(optionalNode);
                    }
                }
            } else {
                // its the goal state
                this->costOfThePath = costOfThePath + currNode->getCost();
                myPath.insert(myPath.begin(), currNode);
                while (!currNode->equals_to(initialNode)) {
                    // trace out way back with the states from goal to initial state.
                    currNode = currNode->getCameFrom();
                    // increasing the cost of the path from goal to initial state.
                    this->costOfThePath = this->costOfThePath + currNode->getCost();
                    myPath.insert(myPath.begin(), currNode);
                }
                cout << "Cost: " << this->costOfThePath << endl;
                cout << "Nodes: " << this->numberOfNodesVisitedTotal << endl;
                return myPath;
//                for (int i = 0; i < theStateQueue.size(); i++) {
//                    // trace out way back with the states from goal to initial state.
//                    if (currNode->equals_to(initialNode)) {
//                        return myPath;
//                    } else {
//                        currNode = currNode->getCameFrom();
//                        // increasing the cost of the path from goal to initial state.
//                        this->costOfThePath = this->costOfThePath + currNode->getCost();
//                        myPath.push_back(currNode);
//                    }
//                }
            }
        }
        // no path;
        return noPathFound;
    }

    double getNumOfNodesEvaluated() override {
        return this->numberOfNodesVisitedTotal;
    }

    double getTheCostOfPath() override {
        return this->costOfThePath;
    }

};