/*
Aryaman Pandya 
All-Pairs Shortest Path 
Using Dynamic programming to find the shortest path between nodes in 
an adjacency matrix 


This snippet of code, along with most of the others in this repo, is 
an extremely basic problem as a CS and AI techniques refresher as I transition 
between one slightly more advanced class (Computer Vision) and another.

The goal is not to learn the algorithms the best, but to re-familiarize 
myself with certain practices 
*/

#include <iostream>
#include <vector>
#include "../base/graph_solutions.hpp"

using namespace std; 

class FloydWarshall : public graph_solutions {
    
public:
    FloydWarshall(vector<vector<int>> adjMatrix) : graph_solutions(adjMatrix) {}
    vector<vector<int>> solution_fw(); 
};

vector<vector<int>> FloydWarshall::solution_fw()
{ 
    vector<vector<int>> dist(n_, vector<int>(n_)); 

    for (int u = 0; u < n_; u++)
    {
        for(int v = 0; v < n_; v++)
        {
            if(u==v)
            {
                dist[u][v] = 0; 
            }
            else
            {
                dist[u][v] = adj_matrix_[u][v]; 
            }
        }
    }

    for(int k = 0; k < n_; k++)
    {
        for(int i = 0; i < n_; i++)
        {
            for(int j = 0; j < n_; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                }
            }
        }
    }
    
    return dist; 

}


int main()
{
    vector<vector<int>> adj_matrix
    {
        {099,   577,  10000, 10},
        {8975,  0,  3,  7898},
        {10000, 10000, 0,   7771},
        {489, 89755, 9097, 70}
    };
   
   FloydWarshall apsp_matrix(adj_matrix); 
   std::cout<<"Before Optimizing: "<< std::endl; 
   apsp_matrix.printMatrix();
   

   std::cout<<"After Optimizing: "<< std::endl;
   std::vector<vector<int>> optimized = apsp_matrix.solution_fw(); 
   apsp_matrix.printMatrix();
}
