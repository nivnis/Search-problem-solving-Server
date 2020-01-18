//
// Created by yuvallevy on 13/01/2020.
//

#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(CacheManager<string, string> *cacheManager, Solver<string, string> *solver) {
    this->myCache = cacheManager;
    this->solver = solver;
}

void MyTestClientHandler::handleClient(int client_socket) {
//    //reading from Client
//    char buffer[1024];
//    bzero(buffer, 1024);
//    string problem, curr_data, solution;

//    //read from the simulator to the buffer
//    int problemRead = read(client_socket, buffer, 1024);
//    problem.append(buffer, problemRead);
    //while we didn't meet the '\n'
//    while (!problem.find('\n')) {
//        problemRead = read(client_socket, buffer, 1024);
//        problem.append(buffer, problemRead);
//    }
    while (true) {
        //reading from Client
        char buffer[1024];
        bzero(buffer, 1024);
        string problem, curr_data, solution;
        //read from the simulator to the buffer
        int problemRead = read(client_socket, buffer, 1024);
        problem.append(buffer, problemRead);

        if(problem.compare("end") == 0) {
            break;
        }
        string problem_after_hash = hash_to_string(problem);

        // getting the hash number of the problem.
        if(myCache->has_solution(problem_after_hash)) {
            solution = myCache->get(problem_after_hash);
        }
        else{
            // getting the actual problem.
            solution = solver->solve(problem);
            //here i update the solution to cache
            myCache->save(problem_after_hash, solution);
        }

        //here i send the solution to the client via socket
        int is_sent = send(client_socket, solution.c_str(), solution.size() , 0);
        if (is_sent == -1) {
            std::cout << "Error sending message" << std::endl;
        }

    }

//    string problem_after_hash = hash_to_string(problem);
//
//    // getting the hash number of the problem.
//    if(myCache->has_solution(problem_after_hash)) {
//        solution = myCache->get(problem_after_hash);
//    }
//    else{
//        // getting the actual problem.
//        solution = solver->solve(problem);
//        //here i update the solution to cache
//        myCache->save(problem_after_hash, solution);
//    }
//
//    //here i send the solution to the client via socket
//    int is_sent = send(client_socket, solution.c_str(), solution.size() , 0);
//    if (is_sent == -1) {
//        std::cout << "Error sending message" << std::endl;
//    }

}
string MyTestClientHandler::hash_to_string(string problem){
    hash<string> hasher;
    size_t solution_before_hash = hasher(problem);
    string solution;
    stringstream mystream;
    mystream << solution_before_hash;
    solution = mystream.str();
    return solution;
}