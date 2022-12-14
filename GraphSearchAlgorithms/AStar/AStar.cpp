/*
    Aryaman Pandya 
    AStar.cpp 
    Definition of functions required to perform A*
    search algorithm
    As of now this just contains un-tweaked Djikstra 
    along with some helper functions that will be 
    necessary for the switch to A* 
*/

#include "AStar.hpp"
#include <queue>
#include <cmath>
#include <tuple>

using namespace std; 

const int INFIN = 1000000000; 

//A* Algo implementation 


int AStar::solution_astar(char src, char dest)
{
    int idx_dest = char_to_index(dest); 
    int idx_src = char_to_index(src); 

    
    if(idx_dest > n_ || idx_dest < 0)
    {
        cout << "Destination out of bounds"; 
        return INFIN; 
    }

    vector<bool> visited(n_, false); 
    vector<int> shortest_path(n_,INFIN); 
    vector<double> future_cost(n_, INFIN); 
    

    shortest_path[idx_src] = 0; 
    future_cost[idx_src] = heuristic(adj_list_[idx_src], adj_list_[idx_dest]); 
    
    int idx = idx_src; 
    int current_distance = 0; 
    
    priority_queue<tuple<int, int>, std::vector<tuple<int, int>>, std::greater<tuple<int, int>>> pq; //tuple element 1 will be fScore, element 2 will be vertex  

    pq.push(make_tuple(future_cost[idx_src], idx)); 

    while(!pq.empty() )
    {
        tuple<int,int> tmp = pq.top();  
        pq.pop();
        idx = get<1>(tmp); 
        int i = 0; 

        if(idx_dest == idx)
        {
            visited[idx_dest] = true; 
            break; 
        }

        for(const auto& neighbour : adj_list_[idx].neighbours)
        {
            i = char_to_index(neighbour.first);
            if(visited[char_to_index(neighbour.first)])
            {
                continue; 
            }

            else if (shortest_path[i]>shortest_path[idx]+ neighbour.second) 
            {
                shortest_path[i]=shortest_path[idx]+ neighbour.second; 
                future_cost[i] = heuristic(adj_list_[i], adj_list_[idx_dest]) + shortest_path[i];
                pq.push(make_tuple(future_cost[i], char_to_index(neighbour.first))); 
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

double AStar::heuristic(Node& start, Node& goal)
{ 
    return sqrt(pow(double (goal.x-start.x), 2.0) + pow(double (goal.y-start.y),2.0));
}
