CC = gcc
CFLAGS  = -g -Wall

graph_solutions : graph_solutions.o FloydWarshall.o 
	g++ -o gs graph_solutions.o FloydWarshall.o

graph_solutions.o : graph_solutions.cpp 
	g++ -c graph_solutions.cpp

FloydWarshall.o : FloydWarshall.cpp 
	g++ -c FloydWarshall.cpp