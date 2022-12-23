/*
Aryaman Pandya 
All-Pairs Shortest Path 
Using Dynamic programming to find the shortest path between nodes in 
an adjacency matrix 

*/

#include <iostream>
#include <vector>
#include "../base/graph_solutions.hpp"

using namespace std; 

class FloydWarshall : public graph_solutions {
    
public:
    FloydWarshall(vector<vector<int>> adjMatrix) : graph_solutions(adjMatrix) {}
    vector<vector<int>> solution_fw(); 
};
