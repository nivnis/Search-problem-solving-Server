#include <iostream>
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"

using namespace std;

int main() {

    CacheManager<string, string> *cacheManager = new FileCacheManager();
    Solver<string, string> *solver = new StringReverser();
    ClientHandler *clientHandler = new MyTestClientHandler(cacheManager, solver);
//    Server *server = new MySerialServer();
    Server* server = new MySerialServer();
    server->open(5600, clientHandler);
    return 0;
}
