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
int Djikstra::solution_dkstra(int dest)
{
    if(dest > n_ || dest < 0)
    {
        cout << "Destination out of bounds"; 
        return INFIN; 
    }

    vector<bool> visited(n_, false); 
    vector<int> shortest_path(n_,INFIN); 
    shortest_path[0] = 0; 
    int idx = 0; 
    int current_distance = 0; 
    priority_queue<tuple<int, int>> pq; //tuple element 1 will be vertex, element 2 will be distance  

    pq.push(make_tuple(0, 0)); 

    while(!visited[dest] || !pq.empty())
    {
        tuple<int,int> tmp = pq.top();  
        pq.pop(); 
        idx = get<0>(tmp);  
        for(int i = 0; i < n_; i++)
        {
            if(!visited[i] && adj_matrix_[idx][i] && (shortest_path[i]<shortest_path[idx]+adj_matrix_[idx][i]))
            {
                shortest_path[i] = shortest_path[idx] + adj_matrix_[idx][i]; 
                pq.push(make_tuple(i, adj_matrix_[idx][i])); 
            }
        }
        
        visited[idx] = true; 
    }

    if(visited[dest])
    {
        return shortest_path[dest]; 
    }

    return INFIN; 
}
