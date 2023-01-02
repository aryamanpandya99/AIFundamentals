/*
Aryaman Pandya 
Base class for graph search implementations 
Adjacency List implementation 
*/

#include "graphList.hpp"
#include "graphMatrix.hpp"
#include <queue>
#include <cmath>
#include <tuple>

graphList::graphList(int num_vertices)
{
    char a = 'A'; 
    char vertex; 
    Node tmp; 
    n_ = num_vertices; 

    for(int i = 0; i < num_vertices; i++)
    {
        vertex = a + i;  
        tmp.name = vertex; 
        adj_list_.push_back(tmp);
    }
}

void graphList::insert_edge(char src, char dest, int weight)
{
    int idx_dest = char_to_index(dest); 
    int idx_src = char_to_index(src); 

    if(idx_dest > n_ || idx_dest < 0)
    {
        std::cout << "Edge cannot be inserted because destination vertex does not exist in graph\n"; 
        return; 
    }
    if (idx_src > n_ || idx_src < 0) {
        std::cout << "Edge cannot be inserted because source vertex does not exist in graph\n"; 
        return; 
    }

    adj_list_[idx_src].neighbours.insert(std::pair<char,int>(dest, weight));

}

int graphList::char_to_index(char character)
{
    return character - 'A'; 
}

bool graphList::add_coords(char vertex, int x, int y)
{
    int idx = char_to_index(vertex); 

    if(idx > n_ || idx < 0)
    {
        return false; 
    }

    adj_list_[idx].x = x; 
    adj_list_[idx].y = y;
    return true; 
}
