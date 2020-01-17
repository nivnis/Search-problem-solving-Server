//
// Created by yuvallevy on 13/01/2020.
//
#pragma once
#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H
#endif //EX4_CACHEMANAGER_H
#include <string>
#include <iostream>
using namespace std;


template<class P, class S> class CacheManager{
private:
public:
    virtual S get(P problem) = 0;
    virtual bool has_solution(P problem) = 0;
    virtual void save(P problem, S solution) = 0;
    virtual string hash_to_string(P problem) = 0;
};