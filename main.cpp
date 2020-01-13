#include <iostream>
#include "FIleCacheManager.h"
#include "Solver.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"

int main() {
    CacheManager<string, string> *cacheManager = new FileCacheManager<string, string>();
    Solver<string, string> *solver = new Solver<string, string>();
    ClientHandler *clientHandler = new MyTestClientHandler(*cacheManager, *solver);
//    Server *server = new MySerialServer();
    Server *server = new MySerialServer();
    server->open(5400, *clientHandler);
    return 0;
}
