//
// Created by yuvallevy on 16/01/2020.
//

#ifndef EX4_SEARCHSOLVER_H
#define EX4_SEARCHSOLVER_H

#endif //EX4_SEARCHSOLVER_H

#pragma once

#include "Searchable.h"
#include "Searcher.h"
using namespace std;

// this is the OB for the problem.
template <class T>
class SearchSolver : public Solver<Searchable<T>, vector<T>>{
private:
    Searcher<T> searcher;
public:

    SearcherSolver(Searchable<T> searcher){
        this->searcher = searcher;
    }
    vector<T> solve(Searchable<T> problem){
        return this->searcher.search(prblem);
    }


};