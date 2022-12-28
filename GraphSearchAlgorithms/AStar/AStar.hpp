/*
Aryaman Pandya 
CS221: AI Principles and Techniques 
Djikstra's Algorithm  
Implementation of a slightly faster and better uniform cost 
search algorithm 
*/

#include <iostream>
#include <vector>
#include "../base/graph_solutions.hpp"

using namespace std; 

class AStar : public graph_solutions {
    
public:
    AStar(vector<vector<int>> adjMatrix) : graph_solutions(adjMatrix) {}
    int heuristic(int cost); 
    int solution_astar(int dest); 
};
