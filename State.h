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
    bool equals_to(State* other_state){
        if(this->state == other_state->getState()){
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
    //comment

    ////////////////////////////////////////////////////
    void setPathCost(double pathCost) {
        State::myPathCost = pathCost;
    }

    double getPathCost() {
        return this->myPathCost;
    }

    void setHeuristicDistance(double distanceTillState) {
        distanceTillState = distanceTillState;
    }

    double getHeuristicDistance() const {
        return distanceTillState;
    }

//    //operator overloading below to check inequalities between the costs of each state.
//    const bool operator==(const State &other) {
//        return (this->equals_to(other));
//    }
//
//    const bool operator<(const State &other) {
//        return (this->getCost() < other.getCost());
//    }
//
//    const bool operator>(const State &other) {
//        return (this->getCost() > other.getCost());
//    }
//
//    const bool operator<=(const State &other) {
//        return (this->getCost() <= other.getCost());
//    }
//
//    const bool operator>=(const State &other) {
//        return (this->getCost() >= other.getCost());
//    }

//    const hash<State> {
//        std::size_t operator()(S const& s) const noexcept
//        {
//            std::size_t h1 = std::hash<std::string>{}(s.first_name);
//            std::size_t h2 = std::hash<std::string>{}(s.last_name);
//            return h1 ^ (h2 << 1); // or use boost::hash_combine (see Discussion)
//        }
//    };
};


#endif //EX4_STATE_H