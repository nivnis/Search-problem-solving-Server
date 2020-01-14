//
// Created by yuvallevy on 13/01/2020.
//
#pragma once
#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H
#endif //EX4_CACHEMANAGER_H
#include <string>
using namespace std;


template<typename P, typename S> class CacheManager{
private:
public:
    virtual void has_solution(P problem) = 0;
    virtual string get(P problem) = 0;
};