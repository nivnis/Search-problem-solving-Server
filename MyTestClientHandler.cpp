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
    string data, curr_data, problem, solution;
    //vector<float> valVector;

    //read from the simulator to the buffer
    int i = 0;
    int valread = read(client_socket, buffer, 1024);
    data.append(buffer, valread);
    //while we didn't meet the '\n'
    while (!data.find('\n')) {
        valread = read(client_socket, buffer, 1024);
        data.append(buffer, valread);
    }
//    //curr_data is our float now
//    curr_data = data.substr(0, data.find('\n'));
//    data.erase(0, data.find('\n') + 1);
//    valVector = getValVector(curr_data);
//    //HERE I UPDATE THE VAR MAP BY SIM
//    SymbolTable* symbolTable = SymbolTable::getInstance();
//    for (float value : valVector) {
//        symbolTable->setVarBySim(this->simArr[i%36],value);
//        i++;
//    }

    problem = data;



    if(myCache->get(problem) != NULL) {
        solution = myCache->get(problem);
    }
    else{
        solution = solver->solve(problem);
    }
    int is_sent = send(client_socket, solution.c_str(), solution.size() , 0);
    if (is_sent == -1) {
        std::cout << "Error sending message" << std::endl;
    }


    //here i send the solution to the client via socket
}
