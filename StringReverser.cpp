//
// Created by yuvallevy on 14/01/2020.
//

#include "StringReverser.h"

StringReverser::StringReverser() {}

string StringReverser::solve(string problem) {

    string rev;
    for (int i = problem.size() - 1; i >= 0; i--) {
        rev = rev.append(1, problem[i]);
    };
    return rev;
}
