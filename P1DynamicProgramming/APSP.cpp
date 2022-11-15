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
class graph_solutions {

private:
    vector<vector<int>> adj_matrix_;
    int n_; 

public:
    graph_solutions(vector<vector<int>> adjMatrix);
    vector<vector<int>> FloydWarshall();

};

graph_solutions::graph_solutions(vector<vector<int>> adjMatrix)
{
    adj_matrix_ = adjMatrix;
    n_ = adj_matrix_.size(); 
}

vector<vector<int>> graph_solutions::FloydWarshall()
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
        {0, -1, -2, 0},
        {4, 0, 2, 4},
        {5, 1, 0, 2}, 
        {3, -1, 1, 0}
    };
   
   graph_solutions solution1(adj_matrix); 
}