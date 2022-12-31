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
#include "../base/graph_solutions.hpp"

using namespace std; 

struct Node {
    char name; 
    int x, y; 
    map<char, int> neighbours; //first var stores neigbour name, second stores distance to neighbour
}; 

class AStar {
    
public:
    AStar(); 
    int heuristic(Node& start, Node& goal); //most likely euclidean distances times weight 
    int solution_astar(char src, char dest); 
    int char_to_int(char character); 
    int num_vertices(); 
    void insert_edge(char src, char dest, int weight); 

private: 
    std::vector<Node> adj_list_; 

};
