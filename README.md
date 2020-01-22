# Searching Algorithms Server

This is a code for a searching problem-solving server. 
The server gets a searching problem and solves it by using the A* algorithm - giving the optimal cost to the solution.

In this project we:
```bash
1) Connecting the server to a client via TCP/IP connection protocol.
2) Accepting problems to the server and sending solutions to them.
```

## Details
We open a server that handles up to 20 clients in parallel. 
Each client sends a problem by a matrix with a starting point and ending point.
The server directs each client to a client handler that will solve the problem.
The matrix search problem is lexered to a vector of state vectors which we send to the algorithm (our searcher) as a searchable. 
Each state holds a point that indicates it's location in the matrix and the cost of itself.
First, the client handler will check if there is already a solution to the problem in the directory and if there is a solution - it will be sended to the client.
If there isn't an existing solution, the client handler uses the best algorithm to solve the searching problem and sends the solution's path back to the client and then ends the communication with the specific client.
We tested four different algorithms for a searching problem that considers cost in an empirical experiment (the scores are in the github directory) - and we chose the A* algorithm to solve the problem.

## Additional Details
* There is and option to choose a serial server instead of the parallel one.
   The serial server handles each client at a time.
* There is an option to choose a string reversing problem instead of a searching problem.
To use the two options above you need to call the mySerialServer and/or the stringReverser classes in the main.

## Compiling

Everything you need is right here in this repository.
just run the following command:
```bash
g++  -std=c++14  *.cpp -Wall  -Wextra  -Wshadow  -Wnon-virtual-dtor -pedantic -o a.out  -pthread
```
## Running

The server searcher receives a single argument which is the port that the server should work on.
After compiling - execute the program by writing one of the next commands:
1. ```bash
	./a.out portNum
	```
	portNum refers to the port number you want the server to work on.
2. ```bash
	./a.out
	```
	This will run the default port number 5600.
	
After running the program - clients will connect to the server and get solutions to their problems. 
The server will be activated for two minutes untill timeout.
## Syntax
every matrix is written in the next pattern:
```bash
Matrix (the matrix)
initial point (a,b)
goal point (c,b)
"end"
```
each line will be over with a '\n'.
