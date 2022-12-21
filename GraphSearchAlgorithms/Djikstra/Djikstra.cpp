/*
    Definition of functions required to perform Djikstra's
    search algorithm
*/

#include "Djikstra.hpp"
#include <queue>
#include <tuple>

using namespace std; 

const int INFIN = 1000000000; 

//Djikstra's Algo implementation 
int Djikstra::solution_dkstra(dest)
{
    vector<bool> visited(n_, false); 
    vector<int> shortest_path(n_,INFIN); 
    shortest_path[0] = 0; 
    int count = 0; 
    int current_distance = 0; 
    priority_queue<tuple<int, int>> pq; //tuple element 1 will be vertex, element 2 will be distance  

    while(!visited[dest])
    {
        for(int i = 0; i < n_; i++)
        {
            if(!visited[i] && adj_matrix_[count][i])
            {
                pq.push(make_tuple(i, adj_matrix_[count][i])); 
            }
        }
    
    }
}
