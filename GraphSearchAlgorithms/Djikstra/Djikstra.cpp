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

    if(idx_dest > n_ || idx_dest < 0)
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

    while( !visited[idx_dest] && !pq.empty() )
    {
        tuple<int,int> tmp = pq.top();  
        pq.pop();
        idx = get<1>(tmp); 
        int i = 0; 

        for(const auto& neighbour : adj_list_[idx].neighbours)
        {
            if(visited[char_to_index(neighbour.first)])
            {
                continue; 
            }

            else if (shortest_path[i]>shortest_path[idx]+ neighbour.second) 
            {
                shortest_path[i]=shortest_path[idx]+ neighbour.second; 
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
