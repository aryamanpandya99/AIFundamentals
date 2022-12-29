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

class AStar {
    
public:
    AStar(); 
    int heuristic(int cost); 
    int solution_astar(int dest); 

};
