//
// Created by yuvallevy on 13/01/2020.
//
#pragma once

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#endif //EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
using namespace std;


class FileCacheManager : public CacheManager{
private:

public:

    void has_solution(P problem);
    string get(P problem);
};