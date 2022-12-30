/*
    Aryaman Pandya 
    Djikstra.cpp 
    Definition of functions required to perform Djikstra's
    search algorithm
    Typically, Djikstra computes all the shortest paths, but 
    we're choosing to tweak it so that it stops after finding 
    the solution we desire. 
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
    priority_queue<tuple<int, int>, std::vector<tuple<int, int>>, std::greater<tuple<int, int>>> pq; //tuple element 1 will be weight, element 2 will be vertex   

    pq.push(make_tuple(0, 0)); 

    while( !visited[dest] && !pq.empty() )
    {
        tuple<int,int> tmp = pq.top();  
        pq.pop();
        idx = get<1>(tmp);   

        //this loop is slowing things down since it's iterating over all elements not just ones that are neighbours 
        for(int i = 0; i < n_; i++)
        {
            if(!visited[i] && adj_matrix_[idx][i]!=0 && (shortest_path[i]>shortest_path[idx]+adj_matrix_[idx][i]))
            {
                shortest_path[i] = shortest_path[idx] + adj_matrix_[idx][i]; 
                pq.push(make_tuple(shortest_path[i], i)); 
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
