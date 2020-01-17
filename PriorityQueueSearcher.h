////
//// Created by yuvallevy on 15/01/2020.
////
//
//#ifndef EX4_SEARCHER_H
//#define EX4_SEARCHER_H
//
//#endif //EX4_SEARCHER_H
//#pragma once
//
//#include "Searcher.h"
//#include "State.h"
//#include <queue>
//using namespace std;
//
//template <class T> class PriorityQueueSearcher : public Searcher<T>{
//
//private:
//    queue<State<T>> openPriorityQueue;
//public:
//    PriorityQueueSearcher() {
//        openPriorityQueue = new queue<State<T>>;
//    }
//
//    virtual ~PriorityQueueSearcher() {
//        delete(openPriorityQueue);
//    }
//
//
//protected:
//    State<T> popOpenPriorityQueue() {
//        State<T> state;
//        state = openPriorityQueue.front();
//        openPriorityQueue.pop();
//        //here i should increase the num of nodes evaluated
//        return state;
//    }
//    void addToOpenPriorityQueue(State<T> state) {
//        openPriorityQueue.push(state);
//    }
//};