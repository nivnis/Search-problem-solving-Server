cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex4 main.cpp CacheManager.h ClientHandler.h FileCacheManager.cpp FileCacheManager.h MySerialServer.h
        MySerialServer.cpp MyTestClientHandler.h MyTestClientHandler.cpp Server.h Solver.h StringReverser.cpp
        StringReverser.h Searchable.h Searcher.h State.h)