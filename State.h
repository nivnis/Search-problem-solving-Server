//
// Created by yuvallevy on 15/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#pragma once
using namespace std;


template <class T> class State {
private:
    T state;
    double cost;
    State<T>* came_from;
    double myPathCost;
    double distanceTillState;

public:
    // check if they are from state.
    // check if they are from state.
    // constructor with no cost.
    State(T state) : state(state){
        this->came_from = nullptr;
        this->myPathCost = -1;
    }
    // a state when we have a cost - like Astar or any algorithem with a cost.
    State(T state, double cost) : state(state){
        this->cost = cost;
        this->came_from = nullptr;
    }
    // check if they are from state.
    bool equals_to(State other_state){
        if(this->state == other_state.get_state()){
            return true;
        }else{
            return false;
        }
    }
    T getState() const {
        return this->state;
    }

    void setCameFrom(State<T> *cameFrom) {
        came_from = cameFrom;
    }


    double getCost() const {
        return cost;
    }

    State<T> *getCameFrom() const {
        return came_from;
    }

    void setState(T state) {
        State::state = state;
    }

    void setCost(double cost) {
        State::cost = cost;
    }

    void setDistanceTillState(double distanceTillState) {
        distanceTillState = distanceTillState;
    }

    double getDistanceTillState() const {
        return distanceTillState;
    }
};


#endif //EX4_STATE_H
