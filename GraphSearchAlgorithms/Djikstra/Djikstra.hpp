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
    Djikstra() {}
    int solution_dkstra(int dest); 

};
