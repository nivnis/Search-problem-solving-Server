//
// Created by yuvallevy on 18/01/2020.
//

#include "MyMatrixClientHandler.h"

MyMatrixClientHandler::MyMatrixClientHandler(MatrixSolver* matrixSolver1, CacheManager<string, string> *cacheManager)
: matrixSolver(matrixSolver1){
    this->myCache = cacheManager;
}
// copy constructor
MyMatrixClientHandler::MyMatrixClientHandler(const MyMatrixClientHandler* copyClientHandler,
        CacheManager<string, string> *cacheManager) :matrixSolver(copyClientHandler->matrixSolver) {
    this->myCache = cacheManager;
}

void MyMatrixClientHandler::handleClient(int client_socket) {
    // reading from buffer and getting the matrix as vector of strings.
    // creating a matrix out of the vector.
    vector<string> problemAsLongString = readFromBuffer(client_socket);
    string allString= "";
    for(int i =0; i<problemAsLongString.size();i++){
        allString.append(problemAsLongString[i]);
    }

    Matrix* myMatrix = createMatrix(problemAsLongString);
    string solution;
    // getting the hash number of the problem.
    if(myCache->has_solution(allString)) {
        solution = myCache->get(allString);
        cout<<"from CACHE: "<<solution<<endl;
    }
    else{
        // getting the actual problem.
        solution = this->matrixSolver->solve(myMatrix);
        cout<<"created NEW solution: "<<solution<<endl;
        //here i update the solution to cache
        myCache->save(allString, solution);
    }

    //here i send the solution to the client via socket
    int is_sent = send(client_socket, solution.c_str(), solution.size() , 0);
    if (is_sent == -1) {
        std::cout << "Error sending message" << std::endl;
    }

}
// creating the matrix = the problem.
Matrix* MyMatrixClientHandler::createMatrix(vector<string> problemString){
    vector<State<Point> *> lineInMatrix;
    vector<vector<State<Point> *>> myMatrixVectors;
    vector<int> stateVal;
    vector<int> goal = divideStringByComma(problemString[problemString.size()-1]);
    vector<int> initial = divideStringByComma(problemString[problemString.size()-2]);
    // the goal point of the matrix.
    Point goalPoint(goal[0], goal[1]);
    // the initial point of the matrix.
    Point initialPoint(initial[0], initial[1]);
    // creating each line of the vector string and creating a line of states for the matrix.
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
    // the matrix to return.
    Matrix* matrix = new Matrix(initialPoint, goalPoint, myMatrixVectors);
    return matrix;
}
// a func that gets a line of the matrix and convert it into a vector of costs.
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
        // read each time until reaching "\n".
        while(buffer[0] != '\n') {
            line.append(buffer);
            read(client_socket, &buffer, 1);
        }
        // removing spaces.
        lineWithOutpaces = removeSpaces(line);
        // if reached "end" - we finished reading the problem.
        found = line.find("end");
        if (found != string::npos)
            break;
        // adding the line of the matrix we just read to the vector of strings.
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

