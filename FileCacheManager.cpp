////
//// Created by yuvallevy on 13/01/2020.
////
//
//#include <sstream>
//#include <fstream>
//#include "FileCacheManager.h"
//#include "iostream"
//using namespace std;
//FileCacheManager::FileCacheManager(){
//}
////~FileCacheManager::FileCacheManager() = default;
//void FileCacheManager::save(string problem, string solution){
////    // not present in cache
////    if (my_cache.find(key) == my_cache.end()) {
////        // cache is full
////        if (ob_list.size() == (unsigned)capacity) {
////            // delete least recently used element
////            auto last = ob_list.end();
////            last--;
////
////            // Pops the last element.
////            ob_list.pop_back();
////
////            // Erase the last
////            my_cache.erase(last->first);
////        }
////    }
////        // present in cache
////    else
////        ob_list.erase(my_cache[key]);
////
////    // update reference
//
//    // convert the solution into hash number.
//    string hash_solution = hash_to_string(solution);
//    // create the new file of the solution.
//    write_to_file(hash_solution,solution);
//    // updating the solution map with the problem and the solution.
//    my_cache[problem] = hash_solution;
//    //    my_cache[key] = ob_list.begin();
//}
//string FileCacheManager::get(string problem){
//    string solution;
//    //obj = (*my_cache[key]).second;
//    solution = read_from_file(my_cache[problem]);
//    return solution;
//
//}
////void FileCacheManager::foreach(function<void(T&)> func) {
////    for (auto x : ob_list) {
////        func(x.second);
////    }
////}
//
//void FileCacheManager::write_to_file(string solution_hash_file_name, string solution){
//    string f_name =  solution_hash_file_name;
//    f_name.append(".txt");
//    ofstream file;
//    file.open(f_name);
//    if(!file.is_open()){
//        throw "Cant open file.";
//    }
//    file << solution;
//    file.close();
//}
//string FileCacheManager::read_from_file(string solution_hash_name) {
//    int i = 0;
//    string line, word;
//    string solution = "";
//    string f_name = solution_hash_name;
//    f_name.append(".txt");
//    fstream file;
////    ifstream myfile (f_name);
//    file.open(f_name);
//    if (file.is_open()){
//        while(!file.eof()) {
//            file >> word;
//            if (i == 0) {
//                solution.append(word);
//            }
//            if(i>0) {
//                solution.append(" ");
//                solution.append(word);
//            }
//            i++;
////        solution.append(line);
////        while(getline(myfile,line)){
////            cout << line << endl;
////            solution.append(line);
////        }
//        }
//
//        file.close();
//        return solution;
//    }
//    else {
//        cout << "Unable to open file";
//        // dont forget to throw error and catch it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//        return NULL;
//    }
//}
//string FileCacheManager::hash_to_string(string problem){
//    hash<string> hasher;
//    size_t solution_before_hash = hasher(problem);
//    string solution;
//    stringstream mystream;
//    mystream << solution_before_hash;
//    solution = mystream.str();
//    return solution;
//}
//bool FileCacheManager::has_solution(string problem){
//    if(my_cache.count(problem)){
//        return true;
//    }else {
//        return false;
//    }
//}
