//
// Created by yuvallevy on 13/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#endif //EX4_SOLVER_H
#pragma once
#include <string>
#include "Point.h"
using namespace std;

template<class P, class S> class Solver {
public:
    virtual S solve(P problem) = 0;

};