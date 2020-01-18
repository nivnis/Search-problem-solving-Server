//
// Created by yuvallevy on 18/01/2020.
//

#include "MyMatrixClientHandler.h"

MyMatrixClientHandler::MyMatrixClientHandler(MatrixSolver* matrixSolver1) {
    this->myCache = new FileCacheManager<string, string>(this->solutionMatrixNameFile);
    this->matrixSolver = matrixSolver1;
}

void MyMatrixClientHandler::handleClient(int client_socket) {
    vector<string> problemAsLongString = readFromBuffer(client_socket);
    Matrix* myMatrix = createMatrix(problemAsLongString);
    string solution;
    // getting the hash number of the problem.
    if(myCache->has_solution(this->theProbAsOnlyString)) {
        solution = myCache->get(this->theProbAsOnlyString);
    }
    else{
        // getting the actual problem.
        solution = this->matrixSolver->solve(myMatrix);
        //here i update the solution to cache
        myCache->save(this->theProbAsOnlyString, solution);
    }

    //here i send the solution to the client via socket
    int is_sent = send(client_socket, solution.c_str(), solution.size() , 0);
    if (is_sent == -1) {
        std::cout << "Error sending message" << std::endl;
    }

}

Matrix* MyMatrixClientHandler::createMatrix(vector<string> problemString){
    vector<State<Point> *> lineInMatrix;
    vector<vector<State<Point> *>> myMatrixVectors;
    vector<int> stateVal;
    vector<int> goal = divideStringByComma(problemString[problemString.size()-1]);
    vector<int> initial = divideStringByComma(problemString[problemString.size()-2]);
    Point goalPoint(goal[0], goal[1]);
    Point initialPoint(initial[0], initial[1]);

    for (int i = 0; i<problemString.size() - 2; i++){
        stateVal = divideStringByComma(problemString[i]);
        for(int k = 0; k< stateVal.size(); k++){
            State<Point>* state = new State<Point>(Point(i,k), stateVal[k]);
            lineInMatrix.push_back(state);
        }
        stateVal.clear();
        myMatrixVectors.push_back(lineInMatrix);
        lineInMatrix.clear();
    }
    Matrix* matrix = new Matrix(initialPoint, goalPoint, myMatrixVectors);
    return matrix;
}

vector<int> MyMatrixClientHandler:: divideStringByComma(string lineMatrix){
    vector<int> returnLine;
    int stop,i;
    string value;
    string comma = ",";
    for(i=0; i <=lineMatrix.size();i++) {
        while (lineMatrix[i] != comma[0] && i != lineMatrix.size()) {
            value += lineMatrix[i];
            i++;
        }
        returnLine.push_back(stoi(value));
        value="";
    }
    return returnLine;

}

vector<string> MyMatrixClientHandler::readFromBuffer(int client_socket){
    //reading from Client
//    char* buffer;
//    bzero(buffer, 1);
    char buffer[1024];
    bzero(buffer, 1024);
    vector<string> problemWithString;

    while(true) {
        string line = "";
        string lineWithOutpaces = "";
        size_t found;
        //read from the simulator to the buffer
        int checkChar = read(client_socket, buffer, 1);
        if(checkChar < 0){
            perror("Couldn't read");
        }
        while(buffer[0] != '\n') {
            line.append(buffer);
            read(client_socket, &buffer, 1);
        }
        lineWithOutpaces = removeSpaces(line);
        found = line.find("end");
        if (found != string::npos)
            break;
        this->theProbAsOnlyString.append(lineWithOutpaces);
        problemWithString.push_back(lineWithOutpaces);
    }
    return problemWithString;
}

// function that remove spaces.
string MyMatrixClientHandler::removeSpaces(string input){
    int length = input.length();
    for (int i = 0; i < length; i++) {
        if(input[i] == ' ')
        {
            input.erase(i, 1);
            length--;
            i--;
        }
    }
    return input;
}

