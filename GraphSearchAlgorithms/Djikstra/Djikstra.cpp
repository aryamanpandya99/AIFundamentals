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
int Djikstra::solution_dkstra(char dest)
{
    int idx_dest = char_to_index(dest); 

    /*if(idx_dest > n_ || idx_dest < 0)
    {
        cout << "Destination out of bounds"; 
        return INFIN; 
    }*/

    vector<bool> visited(n_, false); 
    vector<int> shortest_path(n_,INFIN); 
    shortest_path[0] = 0; 
    int idx = 0; 
    int current_distance = 0; 
    priority_queue<tuple<int, int>, std::vector<tuple<int, int>>, std::greater<tuple<int, int>>> pq; //tuple element 1 will be weight, element 2 will be vertex   

    pq.push(make_tuple(0, 0)); 
    tuple<int,int> tmp; 
    int i; 
    
    while( !visited[idx_dest] && !pq.empty() )
    {
        tmp = pq.top();  
        pq.pop();
        idx = get<1>(tmp); 
        i = 0; 

        for(const auto& neighbour : adj_list_[idx].neighbours)
        {
            i = char_to_index(neighbour.first);
            if(visited[i])
            {
                continue; 
            }

            else if (shortest_path[char_to_index(neighbour.first)]>shortest_path[idx]+ neighbour.second) 
            {
                shortest_path[i]=shortest_path[idx]+ neighbour.second; 
                pq.push(make_tuple(shortest_path[i], char_to_index(neighbour.first))); 
            }
        }

        visited[idx] = true; 
    }

    if(visited[idx_dest])
    {
        return shortest_path[idx_dest]; 
    }

    return INFIN; 
}
