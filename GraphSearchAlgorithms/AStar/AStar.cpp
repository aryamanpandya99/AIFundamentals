/*
    Aryaman Pandya 
    AStar.cpp 
    Definition of functions required to perform A*
    search algorithm
    As of now this just contains un-tweaked Djikstra 
    Will incorporate a heuristic function to allow 
    translation to A* 
*/

#include "AStar.hpp"
#include <queue>
#include <tuple>

using namespace std; 

const int INFIN = 1000000000; 

//A* Algo implementation 

AStar::AStar()
{
    
}

int AStar::solution_astar(int dest)
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

    while( !visited[dest] && !pq.empty() )
    {
        tuple<int,int> tmp = pq.top();  
        pq.pop();
        idx = get<0>(tmp);  

        //this loop is slowing down runtime complexity, need to fix by maintaining neighbour list          
        for(int i = 0; i < n_; i++)
        {
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

int AStar::heuristic(int cost){
    return 0; 
}
