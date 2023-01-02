CC = gcc
CFLAGS  = -g -Wall

graph_solutions : graphList.o graphMatrix.o FloydWarshall.o Djikstra.o AStar.o
	g++ -o gs main.cpp graphList.o graphMatrix.o FloydWarshall.o Djikstra.o AStar.o

graphList.o : ../base/graphList.cpp
	g++ -c ../base/graphList.cpp

graphMatrix.o : ../base/graphMatrix.cpp 
	g++ -c ../base/graphMatrix.cpp

FloydWarshall.o : ../FloydWarshall/FloydWarshall.cpp 
	g++ -c ../FloydWarshall/FloydWarshall.cpp

Djikstra.o : ../Djikstra/Djikstra.cpp
	g++ -c ../Djikstra/Djikstra.cpp

AStar.o : ../AStar/AStar.cpp
	g++ -c ../AStar/AStar.cpp