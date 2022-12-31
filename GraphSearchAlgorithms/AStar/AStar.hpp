/*
Aryaman Pandya 
CS221: AI Principles and Techniques 
A* Search 
Uniform Cost Search with heuristics to 
estimate future costs 
*/

#include <iostream>
#include <vector>
#include <map>
#include "../base/graphList.hpp"

using namespace std; 


class AStar : public graphList{
    
public:
    AStar(int num_vertices, int x, int y) : graphList(num_vertices,x, y){} 
    int heuristic(Node& start, Node& goal); //most likely euclidean distances times weight 
    int solution_astar(char src, char dest); 
    
};
