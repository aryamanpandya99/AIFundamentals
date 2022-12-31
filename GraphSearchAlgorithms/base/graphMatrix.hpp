/*
Aryaman Pandya 
Base class for graph search implementations 
Adjacency Matrix implementation 
*/
#ifndef GRAPHMATRIX_H_
#define GRAPHMATRIX_H_

#include <iostream>
#include <vector>

using namespace std; 

class graphMatrix {

protected:
    vector<vector<int>> adj_matrix_;
    int n_; 

public:
    graphMatrix(vector<vector<int>> adjMatrix);
    void printMatrix(vector<vector<int>> matrix); 

};

#endif
