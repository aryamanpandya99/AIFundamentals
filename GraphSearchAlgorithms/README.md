# Graph Search Algorithms
This is repository contains C++ implementations for different commonly-used graph search algorithms. These algorithms have a ton of utility in AI applications such as language models and motion planning for mobile robots.

## Compiling and running:
Two of the algorithms were implemented using adjacency matrices for ease of use. It made more sense to model better search methods such as A* using adjacency lists, so they don't inherit from the same base class.

### Djikstra, Floyd-Warshall Algorithms
The makefile in the repository root directory will compile the Floyd Warshall and Djikstra implementations and can be run using "./gs"

### A* Search
To compile and run the A* search implementation, use the makefile in the AStar directory and run using "./as" **in progress**