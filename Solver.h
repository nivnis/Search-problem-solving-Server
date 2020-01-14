//
// Created by yuvallevy on 13/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#endif //EX4_SOLVER_H
#pragma once
#include "string.h"
#include <string>
using namespace std;

template<typename P, typename S> class Solver {
private:


public:
    virtual S solve(P problem) = 0;

};