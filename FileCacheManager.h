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
#include <fstream>
#include <sstream>
using namespace std;

template <class P, class S>
class FileCacheManager : public CacheManager<P,S>{
private:
//    list<pair<string,string>> ob_list;
    unordered_map<string, string> my_cache;
    string fileSolutionsName;
public:

    FileCacheManager(string fileSolutionsName){
        this->fileSolutionsName = fileSolutionsName;
        solutionsToMap();
    };
//    ~FileCacheManager();
    void save(P problem, S theSolution){
        string problemHashed = hash_to_string((string)problem);
        this->my_cache[problem] = problemHashed;
        write_to_file(problem, problemHashed, theSolution);
    }

    void write_to_file(P problem, P problemHashed, S theSolution){
        string solutionNameFile =  (string)problemHashed;
        solutionNameFile.append(".txt");
        ofstream solutionFileStream;
        solutionFileStream.open(solutionNameFile, ios::out);
        if(!solutionFileStream.is_open()){
            throw "Cant open file.";
        }else {
            // saving the solution in a specific file.
            solutionFileStream << (string) theSolution;
            solutionFileStream.close();
            // saving problemHashed and solution hashed in one big file so we can load it from there all the
            // solutions at the beginning of the program.
            ofstream matrixSolutionFileStream;
            matrixSolutionFileStream.open(fileSolutionsName, ios::out);
            if (!matrixSolutionFileStream.is_open()) {
                throw "Cant open file.";
            }else{
                // saving the problem and the problem hashed in out big solution cache file.
                matrixSolutionFileStream << (string) problem << "!" << (string) problemHashed << endl;
                solutionFileStream.close();
            }
        }
    }
    // need to make sure we are sending the problem already hashed!
    bool has_solution(P problem){
        string problemHashed = hash_to_string((string)problem);
        if(my_cache.count((string)problemHashed)){
            return true;
        }else {
            return false;
        }
    }
    // need to pass the problem hashed already.
    string get(P problem){
        string problemHashed = hash_to_string((string)problem);
        string solution;
        //obj = (*my_cache[key]).second;
        solution = read_from_file(my_cache[problemHashed]);
        return solution;
    }

    string read_from_file(S solutionHashed) {
        string theSolutionToReturn;
        string solutionNameFile = (string) solutionHashed;
        solutionNameFile.append(".txt");
        ifstream solutionFileStream;
        solutionFileStream.open(solutionNameFile, ios::in);
        if (!solutionFileStream.is_open()) {
            throw "Cant open file.";
        } else {
            // reading line by line the solution from the file.
            while (getline(solutionFileStream, theSolutionToReturn)) {
                solutionFileStream >> theSolutionToReturn;
            }
            solutionFileStream.close();
        }
        // return solution;
        return theSolutionToReturn;
    }


    string hash_to_string(P problem){
        hash<string> hasher;
        size_t solution_before_hash = hasher((string)problem);
        string solution;
        stringstream mystream;
        mystream << solution_before_hash;
        solution = mystream.str();
        return solution;
    }

    void solutionsToMap(){
        string line;
        fstream solutionFileStream;
        solutionFileStream.open(fileSolutionsName, ios::in);
        if (!solutionFileStream.is_open()) {
//            perror("Cant open solution file.");
//            exit(1);

            // There is no solutions yet so there is no such file.
            return;
        } else {
            // each line is problem and problem hashed divided by "!". we will add each pair to the cache map solutions.
            while(getline(solutionFileStream, line)){
                std::size_t found = line.find("!");
                string problem = line.substr(0, found);
                string solution = line.substr(found+1, line.size()-(found+1));
                // add problem to solution in the cache of solutions.
                this->my_cache[problem] = solution;
            }
            solutionFileStream.close();
        }
    }
};