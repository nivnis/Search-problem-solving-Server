//
// Created by yuvallevy on 13/01/2020.
//
#pragma once

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#endif //EX4_FILECACHEMANAGER_H

#include <list>
#include "CacheManager.h"
#include "string.h"
#include "unordered_map"
#include <unordered_map>
#include "hash_map"
using namespace std;


class FileCacheManager : public CacheManager<string,string>{
private:
//    list<pair<string,string>> ob_list;
    unordered_map<string, string> my_cache;
public:

    FileCacheManager();
//    ~FileCacheManager();
    void save(string problem, string solution);
    bool has_solution(string problem);
    string get(string problem);
    void write_to_file(string solution_hash_file_name, string solution);
    string read_from_file(string key);
    string hash_to_string(string problem);
};