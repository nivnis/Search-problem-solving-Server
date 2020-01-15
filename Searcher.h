//
// Created by yuvallevy on 15/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#endif //EX4_SEARCHER_H
#pragma once
#include "State.h"
#include "Searchable.h"
#include <vector>
using namespace std;


template <class T> class Searcher{
public:
    virtual vector<State<T>* > search(Searchable<T>* searchable) = 0;
    virtual int getNumberOfNodes() const = 0;tk
};