/*
Aryaman Pandya 
CS221: AI Principles and Techniques 
Djikstra's Algorithm  
Implementation of a slightly faster and better uniform cost 
search algorithm 
*/

#include <iostream>
#include <vector>
#include "../base/graphList.hpp"

using namespace std; 

class Djikstra : public graphList {
    
public:
  Djikstra(int num_vertices, int x, int y);
  int solution_dkstra(char dest); 

};
