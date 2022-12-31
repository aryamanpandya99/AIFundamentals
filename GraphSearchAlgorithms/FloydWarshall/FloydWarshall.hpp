/*
Aryaman Pandya 
All-Pairs Shortest Path 
Using Dynamic programming to find the shortest path between nodes in 
an adjacency matrix 

*/

#include <iostream>
#include <vector>
#include "../base/graphMatrix.hpp"

using namespace std; 

class FloydWarshall : public graphMatrix {
    
public:
    FloydWarshall(vector<vector<int>> adjMatrix) : graphMatrix(adjMatrix) {}
    vector<vector<int>> solution_fw(); 
};
