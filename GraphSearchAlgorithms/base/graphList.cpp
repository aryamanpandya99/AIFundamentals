/*
    Aryaman Pandya 
    graphList.cpp 
    Definition of functions required to perform A*
    search algorithm
    As of now this just contains un-tweaked Djikstra 
    along with some helper functions that will be 
    necessary for the switch to A* 
*/

#include "graphList.hpp"
#include <queue>
#include <cmath>
#include <tuple>

void graphList::insert_edge(char src, char dest, int weight)
{
    int idx_dest = char_to_int(dest); 
    int idx_src = char_to_int(src); 

    if(idx_dest > n_ || idx_dest < 0)
    {
        std::cout << "Edge cannot be inserted because destination vertex does not exist in graph\n"; 
        return; 
    }
    else if (idx_src > n_ || idx_src < 0) {
        std::cout << "Edge cannot be inserted because source vertex does not exist in graph\n"; 
        return; 
    }

    adj_list_[idx_src].neighbours.insert(std::pair<char,int>(dest, weight));
    n_++; 

}

int graphList::char_to_int(char character)
{
    return character - 'A'; 
}