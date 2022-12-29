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
    int n = num_vertices(); 
    
    if(dest > n || dest < 0)
    {
        cout << "Destination out of bounds"; 
        return INFIN; 
    }

    vector<bool> visited(n, false); 
    vector<int> shortest_path(n,INFIN); 
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
        for(int i = 0; i < n; i++)
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

int AStar::heuristic(int x0, int y0, int x1, int y1)
{
    return sqrt((x1-x0)^2 + (y1-y0)^2);
}

int AStar::num_vertices()
{
    return adj_list_.size(); 
}

void AStar::insert_edge(char src, char dest, int weight)
{
    int idx_dest = char_to_int(dest); 
    int idx_src = char_to_int(src); 

    if(idx_dest > num_vertices() || idx_src < 0)
    {
        std::cout << "Edge cannot be inserted because destination vertex does not exist in graph\n"; 
        return; 
    }
    else if (idx_src > num_vertices() || idx_src < 0) {
        std::cout << "Edge cannot be inserted because source vertex does not exist in graph\n"; 
        return; 
    }
    tuple<char, int> tmp = make_tuple(dest, weight); 

    adj_list_[idx_src].neighbours.push_back(tmp);

}

int AStar::char_to_int(char character)
{

}
