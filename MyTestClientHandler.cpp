//
// Created by yuvallevy on 13/01/2020.
//

#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(CacheManager<string, string> *cacheManager, Solver<string, string> *solver) {
    this->myCache = cacheManager;
    this->solver = solver;
}

void MyTestClientHandler::handleClient(int socket) {

}
