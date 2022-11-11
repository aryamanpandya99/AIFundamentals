/*
All-Pairs Shortest Path 
Using Dynamic programming to find the shortest path between nodes in 
an adjacency matrix 


This project (along with most of the others in this repo) are extremely basic problems as a 
CS and AI techniques refresher as I transition between one advanced class (Computer Vision)
and another (either NLP or Reinforcement learning)

The goal is not to learn the algorithms the best, but to re-familiarize myself with certain 
techniques 
*/

#include <iostream>
#include <vector>

using namespace std; 

//here the memoization is in the storing of the shortest path in the dist vector
int shortest_path(int n, vector<vector<int>> adjMatrix)
{
    vector<vector<int>> dist(n, vector<int>(n)); 

    for (int u = 0; i < n; i++)
    {
        for(int v = 0; j < n; j++)
        {
            if(u==v)
            {
                dist[u][v] = 0; 
            }
            else
            {
                dist[u][v] = adjMatrix[u][v]; 
            }
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                }
            }
        }
    }

}

int main()
{
    vector<vector<int>> adj_matrix
    {
        {0, -1, -2, 0},
        {4, 0, 2, 4},
        {5, 1, 0, 2}, 
        {3, -1, 1, 0}
    };
   
}