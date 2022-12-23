/*
Aryaman Pandya 
All-Pairs Shortest Path 
Using Dynamic programming to find the shortest path between nodes in 
an adjacency matrix 

*/
#include "FloydWarshall.hpp"


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
