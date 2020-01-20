//
// Created by pikachu on 1/16/20.
//
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "Searcher.h"

template<class T>
class BestFirstSearch : public Searcher<T> {
    int numOfNodes;
    double totalPathCost;
    //inner class to use in the priority queue in the algorithm.
    class StateCompare {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return (left->getPathCost() > right->getPathCost());
        }
    };

public:

    BestFirstSearch(){
        numOfNodes = 0;
        totalPathCost = 0;
    }
    /**
     * Checks whether or not a specific node has been visited during the BFS algorithm.
     * @param nodesVec - vector of nodes that have been visited.
     * @param node - node to check if visited.
     * @return - true if it is false otherwise.
     */


    /**
     * Checks whether or not a specific state is in the priority queue. If so, returns true else false.
     */
    bool isNodeInQueue(
            priority_queue<State<T> *, vector<State<T> *>, StateCompare> priorityQueue,
            State<T> *node) {
        //goes over the queue until it's empty.
        while (!priorityQueue.empty()) {
            if (node->equals_to(priorityQueue.top())) {
                return true;
            }
            priorityQueue.pop();
        }
        return false;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        resetMembers();
        //keeps the nodes we've already traveled in
        vector<State<T> *> nodesVisited;
        //keeps the nodes we need to travel in. sorts the nodes from the ones with the lowest path-cost to the highest
        // one
        priority_queue<State<T> *, vector<State<T> *>, StateCompare> open;
        //the final path from the source node to the destination node
        vector<State<T> *> path;
        State<T> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        currentState->setPathCost(currentState->getCost());
        open.push(currentState);
        while (!open.empty()) {
            currentState = open.top();
            open.pop();
            this->numOfNodes+=1;
            //if the are no more paths to check to the destination node then return the path to it
            if (currentState->equals_to(searchable->getGoalState())) {
                path.insert(path.begin(), currentState);
                this->totalPathCost += currentState->getCost();
                while (!(currentState->equals_to(
                        searchable->getInitialState()))) {
                    currentState = currentState->getCameFrom();
                    path.insert(path.begin(), currentState);
//                    cout<<"before: " << totalPathCost << currentState->getState()<<endl;
                    this->totalPathCost += currentState->getCost();
//                    cout<<"after: " << totalPathCost << currentState->getState()<<endl;
                }
//                cout<<totalPathCost<<endl;
                return path;
            } else {
                //find all the adjacent nodes
                for (State<T> *adj : searchable->getAllPossibleStates(currentState)) {
                    //gets the current's adjacent State Path-Cost
                    double adjPathCost = currentState->getPathCost() + adj->getCost();
                    /*
                     * if the node was already visited and we dont need to find a cheaper way to it - continue,
                     * but if the node was already visited and we can to find a cheaper way to it - check
                     */
                    if (this->hasNodeBeenVisited(nodesVisited, adj) ||
                        isNodeInQueue(open, adj)) {
                        if (!this->hasNodeBeenVisited(nodesVisited, adj)
                            && isNodeInQueue(open, adj)) {
                            //compares the lowest cost of the same State with 2 different paths to it.
                            if (adjPathCost < adj->getPathCost()) {
                                //if cheaper path found - update it
                                adj->setCameFrom(currentState);
                                adj->setPathCost(adjPathCost);
                                open.emplace(adj);
                            }
                        }
                        continue;
                    } else {
                        //for a node we visit in the first time - update its information.
                        adj->setPathCost(adjPathCost);
                        adj->setCameFrom(currentState);
                        open.emplace(adj);
                    }
                }
                //insert the current node to nodesVisited to make sure we dont check it again
                nodesVisited.emplace_back(currentState);
            }
        }
        //could not find path from requested initial to goal.
        return path;
    }

    void resetMembers(){
        this->totalPathCost = 0;
        this->numOfNodes = 0;
    }

    double getNumOfNodesEvaluated() override {
        return numOfNodes;
    }

    double getTheCostOfPath() override {
        return totalPathCost;
    }

};

#endif //EX4_BESTFIRSTSEARCH_H