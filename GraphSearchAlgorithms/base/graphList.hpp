/*
Aryaman Pandya 
CS221: AI Principles and Techniques 
Djikstra's Algorithm  
Implementation of a slightly faster and better uniform cost 
search algorithm 
*/
#ifndef GRAPH_SOLUTIONS_H_
#define GRAPH_SOLUTIONS_H_

#include <iostream>
#include <vector>
#include <map>

using namespace std; 

struct Node {
    char name; 
    int x, y; 
    map<char, int> neighbours; //first var stores neigbour name, second stores distance to neighbour
}; 

class graphList {
    
public:
    graphList(); 
    int char_to_int(char character); 
    void insert_edge(char src, char dest, int weight); 

protected: 
    std::vector<Node> adj_list_; 
    int n_;

};

#endif
