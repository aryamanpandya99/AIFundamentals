/*
    Definition of functions required to perform Djikstra's
    search algorithm
*/

#include "Djikstra/Djikstra.hpp"
#include "FloydWarshall/FloydWarshall.hpp"




int main()
{
    vector<vector<int>> adj_matrix
    {
        {99,   577,  10000, 10},
        {8975,  0,  3,  7898},
        {10000, 10000, 0,   7771},
        {489, 89755, 9097, 70}
    };
    
    cout << "******************Djikstra*********************\n"; 
    Djikstra djikstra_soln(adj_matrix); 
    std::cout<<"Input Adjacency Matrix: "<< std::endl; 

    djikstra_soln.printMatrix(adj_matrix);

    cout << "Given destination from source = vertex 4\n";
    
    int shortest_path = djikstra_soln.solution_dkstra(4); 
    std::cout<<"Shortest path to destination: "<<shortest_path<< endl;
}


int main()
{
    vector<vector<int>> adj_matrix
    {
        {99,   577,  10000, 10},
        {8975,  0,  3,  7898},
        {10000, 10000, 0,   7771},
        {489, 89755, 9097, 70}
    };
    
    cout << "***********Running Floyd Warshall Algo***************\n"; 
    FloydWarshall apsp_matrix(adj_matrix); 
    std::cout<<"Before Optimizing: "<< std::endl; 
    apsp_matrix.printMatrix(adj_matrix);
    
    std::cout<<"After Optimizing: "<< std::endl;
    std::vector<vector<int>> optimized = apsp_matrix.solution_fw(); 
    apsp_matrix.printMatrix(optimized);
}
