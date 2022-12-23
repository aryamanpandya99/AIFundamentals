CC = gcc
CFLAGS  = -g -Wall

graph_solutions : graph_solutions.o FloydWarshall.o Djikstra.o
	g++ -o gs graph_solutions.o FloydWarshall.o Djikstra.o

graph_solutions.o : base/graph_solutions.cpp 
	g++ -c base/graph_solutions.cpp

FloydWarshall.o : FloydWarshall/FloydWarshall.cpp 
	g++ -c FloydWarshall/FloydWarshall.cpp

Djikstra.o : Djikstra/Djikstra.cpp
	g++ -c Djikstra/Djikstra.cpp