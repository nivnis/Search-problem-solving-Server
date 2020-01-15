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

public:
    // a state when we have a cost - like Astar or any algorithem with a cost.
    State(T state, double cost){
        this->cost = cost;
        this->state = state;
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
    T get_state() const(){
        return this->state;
    }

};


#endif //EX4_STATE_H
