/*
Aryaman Pandya 
Base class for graph search implementations 
*/
#ifndef GRAPH_SOLUTIONS_H_
#define GRAPH_SOLUTIONS_H_

#include <iostream>
#include <vector>

using namespace std; 

class graph_solutions {

protected:
    vector<vector<int>> adj_matrix_;
    int n_; 

public:
    graph_solutions(vector<vector<int>> adjMatrix);
    void printMatrix(vector<vector<int>> matrix); 

};

#endif
