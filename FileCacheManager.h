//
// Created by yuvallevy on 13/01/2020.
//
#pragma once

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#endif //EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "string.h"
using namespace std;


class FileCacheManager : public CacheManager<string,string>{
private:

public:

    FileCacheManager();

    void has_solution(string problem);

    string get(string problem);
};