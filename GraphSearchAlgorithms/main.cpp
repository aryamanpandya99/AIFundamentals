/*
    Definition of functions required to perform Djikstra's
    search algorithm
*/

#include "Djikstra/Djikstra.hpp"
#include "FloydWarshall/FloydWarshall.hpp"
#include "base/graphList.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>    

using namespace std; 

const int INFIN = 1000000000; 

void run_fw(vector<vector<int>> adj_matrix)
{
    cout << "***********Running Floyd Warshall Algo***************\n"; 
    FloydWarshall apsp_matrix(adj_matrix); 
    std::cout<<"Before Optimizing: "<< std::endl; 
    apsp_matrix.printMatrix(adj_matrix);
    
    std::cout<<"After Optimizing: "<< std::endl;
    auto start = std::chrono::system_clock::now();
    std::vector<vector<int>> optimized = apsp_matrix.solution_fw(); 
    auto end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> runtime = end-start;
    
    apsp_matrix.printMatrix(optimized);
    std::cout << "Runtime for Dynamic Programming Algorithm: " << runtime.count() << 
                                                                "s\n"; 
}

void run_dkstra(int num_vertices)
{
    cout << "******************Djikstra*********************\n"; 
    Djikstra djikstra_soln(num_vertices); 
    djikstra_soln.insert_edge('A', 'B', 2); 
    djikstra_soln.insert_edge('A', 'E', 14);
    djikstra_soln.insert_edge('B', 'C', 8);
    djikstra_soln.insert_edge('B', 'D', 6);
    djikstra_soln.insert_edge('C', 'E', 3);

    cout << "Given destination from source: vertex 4\n";

    auto start = std::chrono::system_clock::now();
    int shortest_path = djikstra_soln.solution_dkstra('D'); 
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> runtime = end-start;

    if(shortest_path!= INFIN)
    {
        std::cout << "Runtime for Djikstra's Search Algorithm: " << runtime.count() << 
                                                                "s\n"; 
        std::cout<<"Shortest path to destination: "<<shortest_path<< endl;
    }

    else {
        std::cout<<"Traversal not possible\n"; 
    }
    
}

int main()
{
    //declare some adjacency matrix - this will be interactive eventually 
    vector<vector<int>> adj_matrix
    {
        {0,   577,  10000, 10, 56, 0},
        {8975,  0,  3,  7898, 0, 4353},
        {10000, 10000, 0,   7771, 2435, 45},
        {489, 455, 9097, 0, 45242, 356}, 
        {489, 0, 78, 0, 0, 245}, 
        {489, 34, 2, 0, 67, 0}, 
    };

    //Calls our search algorithms on our adjacency matrix
    run_fw(adj_matrix); 
    run_dkstra(6); 

}
