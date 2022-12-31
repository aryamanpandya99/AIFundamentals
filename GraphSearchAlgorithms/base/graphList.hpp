/*
Aryaman Pandya 
Base class for graph search implementations 
Adjacency List implementation 
*/
#ifndef graphMatrix_H_
#define graphMatrix_H_

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
    graphList(int num_vertices, int x, int y); 
    int char_to_index(char character); 
    void insert_edge(char src, char dest, int weight); 

protected: 
    std::vector<Node> adj_list_; 
    int n_;

};

#endif
