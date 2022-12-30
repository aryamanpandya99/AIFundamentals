/*
Aryaman Pandya 
CS221: AI Principles and Techniques 
Djikstra's Algorithm  
Implementation of a slightly faster and better uniform cost 
search algorithm 
*/

#include <iostream>
#include <vector>
#include <map>
#include "../base/graph_solutions.hpp"

using namespace std; 

struct Node {
    char name; 
    int x, y; 
    vector<map<char, int>> neighbours; //first var stores neigbour name, second stores distance to neighbour
}; 

class AStar {
    
public:
    AStar(); 
    int heuristic(Node& start, Node& goal); //most likely euclidean distances 
    int solution_astar(char src, char dest); 
    int char_to_int(char character); 
    int num_vertices(); 
    void insert_edge(char src, char dest, int weight); 

private: 
    std::vector<Node> adj_list_; 

};
