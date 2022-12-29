CC = gcc
CFLAGS  = -g -Wall

AStar : graph_solutions.o FloydWarshall.o Djikstra.o
	g++ -o gs main.cpp AStar.o

AStar.o : AStar.cpp
	g++ -c AStar.cpp