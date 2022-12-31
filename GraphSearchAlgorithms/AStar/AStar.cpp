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

AStar::AStar()
{
    
}

int AStar::solution_astar(char src, char dest)
{
    int idx_dest = char_to_int(dest); 
    int idx_src = char_to_int(src); 

    int n = num_vertices(); 
    
    if(idx_dest > n || idx_dest < 0)
    {
        cout << "Destination out of bounds"; 
        return INFIN; 
    }

    vector<bool> visited(n, false); 
    vector<int> shortest_path(n,INFIN); 
    vector<float> future_cost(n, INFIN); 
    

    shortest_path[idx_src] = 0; 
    future_cost[idx_src] = heuristic(adj_list_[idx_src], adj_list_[idx_dest]); 
    
    int idx = idx_src; 
    int current_distance = 0; 
    
    priority_queue<tuple<int, int>, std::vector<tuple<int, int>>, std::greater<tuple<int, int>>> pq; //tuple element 1 will be weight, element 2 will be vertex  

    pq.push(make_tuple(0, idx)); 

    while( !visited[dest] && !pq.empty() )
    {
        tuple<int,int> tmp = pq.top();  
        pq.pop();
        idx = get<1>(tmp); //min

        //this loop is slowing down runtime complexity, need to fix by maintaining neighbour list          
        for(const auto& neighbour : adj_list_[idx].neighbours)
        {
            if(visited[char_to_int(neighbour.first)])
            {
                continue; 
            }
            
            if(!visited[i] && adj_matrix_[idx][i]!=0 && (shortest_path[i]>shortest_path[idx]+adj_matrix_[idx][i]))
            {
                shortest_path[i] = shortest_path[idx] + adj_matrix_[idx][i]; 
                pq.push(make_tuple(i, shortest_path[i])); 
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

int AStar::heuristic(Node& start, Node& goal)
{
    return sqrt((goal.x-start.x)^2 + (goal.y-start.y)^2);
}
