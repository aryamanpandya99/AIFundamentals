/*
Aryaman Pandya 
Base class for graph search implementations 
Adjacency Matrix implementation
*/

#include <iostream>
#include <vector>
#include "graphMatrix.hpp"

using namespace std; 

graphMatrix::graphMatrix(vector<vector<int>> adjMatrix)
{
    adj_matrix_ = adjMatrix;
    n_ = adj_matrix_.size(); 
}

void graphMatrix::printMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size(); 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout<<matrix[i][j]<<" "; 
        }
        std::cout<<std::endl; 
    }
    std::cout<<endl; 
}

