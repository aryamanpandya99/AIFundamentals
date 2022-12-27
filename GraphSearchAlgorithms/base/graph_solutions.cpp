/*
Aryaman Pandya 
Base class for graph search implementations 
*/

#include <iostream>
#include <vector>
#include "graph_solutions.hpp"

using namespace std; 

graph_solutions::graph_solutions(vector<vector<int>> adjMatrix)
{
    adj_matrix_ = adjMatrix;
    n_ = adj_matrix_.size(); 
}

void graph_solutions::printMatrix(vector<vector<int>> matrix)
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

