//
// Created by yuvallevy on 13/01/2020.
//
#pragma once

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#endif //EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
using namespace std;


template<typename P, typename S> class FileCacheManager : public CacheManager<P,S>{
private:

public:

    FileCacheManager();
    void has_solution(P problem);
    string get(P problem);
};