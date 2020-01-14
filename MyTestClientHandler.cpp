//
// Created by yuvallevy on 13/01/2020.
//

#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(CacheManager<string, string> *cacheManager, Solver<string, string> *solver) {
    this->myCache = cacheManager;
    this->solver = solver;
}

void MyTestClientHandler::handleClient(int client_socket) {
    //reading from Client
    char buffer[1024];
    bzero(buffer, 1024);
    string problem, curr_data, solution;
    //vector<float> valVector;

    //read from the simulator to the buffer
    int i = 0;
    int valread = read(client_socket, buffer, 1024);
    problem.append(buffer, valread);
    //while we didn't meet the '\n'
    while (!problem.find('\n')) {
        valread = read(client_socket, buffer, 1024);
        problem.append(buffer, valread);
    }


    if(myCache->get(problem) != NULL) {
        solution = myCache->get(problem);
    }
    else{
        solution = solver->solve(problem);
        //here i update the solution to cache
    }



    //here i send the solution to the client via socket
    int is_sent = send(client_socket, solution.c_str(), solution.size() , 0);
    if (is_sent == -1) {
        std::cout << "Error sending message" << std::endl;
    }
}
