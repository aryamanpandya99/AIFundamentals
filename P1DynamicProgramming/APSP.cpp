/*
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

using namespace std; 

class graph_solutions {

private:
    vector<vector<int>> adj_matrix_;
    int n_; 

public:
    graph_solutions(vector<vector<int>> adjMatrix);
    vector<vector<int>> FloydWarshall();
    void printMatrix(); 

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

void printMatrix(vector<vector<int>> adjMatrix)
{
    int n = adjMatrix.size(); 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout<<adjMatrix[i][j]<<" "; 
        }
        std::cout<<std::endl; 
    }
}

int main()
{
    vector<vector<int>> adj_matrix
    {
        {0,   5,  10000, 10},
        {10000,  0,  3,  10000},
        {10000, 10000, 0,   1},
        {10000, 10000, 10000, 0}
    };
   
   graph_solutions solution_fw(adj_matrix); 
   std::cout<<"Before Optimizing: "<< std::endl; 
   printMatrix(adj_matrix);
   

   std::cout<<"After Optimizing: "<< std::endl;
   std::vector<vector<int>> optimized = solution_fw.FloydWarshall(); 
   printMatrix(optimized);
}