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

class Djikstra : public graph_solutions {
    
public:
    Djikstra(vector<vector<int>> adjMatrix) : graph_solutions(adjMatrix) {}
    int solution_dkstra(int dest); 

};
