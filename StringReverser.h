//
// Created by yuvallevy on 14/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#pragma once


#include "Solver.h"
using namespace std;

class StringReverser : public Solver<string,string> {
public:
    StringReverser();
    string solve(string problem);
};




#endif //EX4_STRINGREVERSER_H
