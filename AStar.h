//
// Created by yuvallevy on 17/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#endif //EX4_ASTAR_H

#include "Searcher.h"

template<class T>
class AStar : public Searcher<T> {
    int totalNumberOfNodes;
    double totalPathCost;

    //inner class to use in the priority queue in the algorithm.
    class StateComparator {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return ((left->getHeuristicDistance() + left->getPathCost()) >
                    (right->getHeuristicDistance() + right->getPathCost()));
        }
    };

public:
    AStar() {
        totalNumberOfNodes = 0;
        totalPathCost = 0;
    }

    bool isInQueue(
            priority_queue<State<T> *, vector<State<T> *>, StateComparator> pq,
            State<T> *node) {
        //goes over the queue until it's empty.
        while (!pq.empty()) {
            if (node->equals_to(pq.top())) {
                return true;
            }
            pq.pop();
        }
        return false;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        //our closed - keeps the nodes we've already traveled in so we won't need to evaluate them again
        vector<State<T> *> visitedNodes;
        //our open - a priority queue that stores the states we visit and sorts it from lowest path cost to largest
        priority_queue<State<T> *, vector<State<T> *>, StateComparator> open;
        //the final path from source to destination
        vector<State<T> *> path;
        State<T> *currentState = searchable->getInitialState();
        State<T> *goalState = searchable->getGoalState();
        currentState->setCameFrom(currentState);
        currentState->setPathCost(currentState->getCost());
        currentState->setHeuristicDistance(searchable->findDistance(currentState, goalState));
        open.push(currentState);
        while (!open.empty()) {
            currentState = open.top();
            open.pop();
            if (!this->hasNodeBeenVisited(visitedNodes, currentState)) {
                this->totalNumberOfNodes += 1;
            }
            //if this is our goal node
            if (currentState->equals_to(searchable->getGoalState())) {
                //insert the goal state to the path
                path.insert(path.begin(), currentState);
                //edit the goal node's path cost to the total path cost
                this->totalPathCost += currentState->getCost();
                //backtrace the path and evaluates the path cost
                while (!(currentState->equals_to(searchable->getInitialState()))) {
                    currentState = currentState->getCameFrom();
                    path.insert(path.begin(), currentState);
                    this->totalPathCost += currentState->getCost();
                }
                //return the correct path
                return path;
            } else
                {
                ///for all the neighbors
                vector<State<T> *> neighbors = searchable->getAllPossibleStates(currentState);
                for (State<T> *neighbor : neighbors) {
                    //the current neighbor Path Cost
                    double newPathCost = currentState->getPathCost() + neighbor->getCost();
                    //the current neighbor heuristic (distance from goal)
                    double heuristicDistance = searchable->findDistance(neighbor, goalState);
                    //the evaluated cost with heuristic
                    double evaluatedCost = newPathCost + heuristicDistance;
                    //if we already visited this node or it doesn't need to be updated
                    if (this->hasNodeBeenVisited(visitedNodes, neighbor) || isInQueue(open, neighbor)) {
                        if (!this->hasNodeBeenVisited(visitedNodes, neighbor) && isInQueue(open, neighbor)) {
                            //if the new path cost is cheaper - we update the node's path cost to it
                            if (evaluatedCost < (neighbor->getPathCost() + neighbor->getHeuristicDistance())) {
                                //if cheaper heuristic found - update adjacent State fields
                                neighbor->setCameFrom(currentState);
                                neighbor->setPathCost(newPathCost);
                                neighbor->setHeuristicDistance(heuristicDistance);
                                open.emplace(neighbor);
                            }
                        }
                        continue;
                    } else {
                        //it's the first time we meet this node so we update it
                        neighbor->setCameFrom(currentState);
                        neighbor->setPathCost(newPathCost);
                        neighbor->setHeuristicDistance(heuristicDistance);
                        open.emplace(neighbor);
                    }
                }
                    //inserting the current node to the visited nodes so we won't visit him again
                visitedNodes.emplace_back(currentState);
            }
        }
        //couldn't find the path - returns NO PATH FOUND
        return path;
    }

    double getNumOfNodesEvaluated() override {
        return totalNumberOfNodes;
    }

    double getTheCostOfPath() override {
        return totalPathCost;
    }

};