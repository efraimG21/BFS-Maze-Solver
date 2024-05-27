

# BFS-Maze-Solver

BFS-Maze-Solver is a C program that solves mazes using the Breadth-First Search (BFS) algorithm. The maze is represented as a 2D grid, and the program finds the shortest path from a starting point 'A' to a destination 'B'.

## Features

- Implementation of BFS to find the shortest path in a maze
- Dynamic memory allocation for the maze, queue, and graph nodes
- Comprehensive error handling
- Clear and modular code structure

## Getting Started

### Prerequisites

To compile and run this project, you need a C compiler like `gcc`.

### Building the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/efraimG21/BFS-Maze-Solver.git
   cd BFS-Maze-Solver
   ```

2. Compile the code:

   ```bash
   gcc main.c BreadthFirstSearch.c Maze.c Queue.c Graph.c -o bfs_maze
   ```

3. Run the executable:

   ```bash
   ./bfs_maze
   ```

## Code Structure

- `BreadthFirstSearch.c`: Implements the BFS algorithm.
- `Maze.c`: Initializes the maze and handles maze-related operations.
- `Queue.c`: Provides queue operations to support BFS.
- `Graph.c`: Manages the graph nodes used in the BFS algorithm.


## Usage

The program initializes a maze with a predefined layout. The starting point is marked by 'A' and the destination by 'B'. The program then uses BFS to find the shortest path from 'A' to 'B' and prints the maze with the path marked.

### Example Output

```
####A#####
# ## ### #
#      # #
# ## # # #
#    # # #
# ## #   #
#  # ### #
# #### # #
#        #
####B#####
```

After finding the route:

```
####A#####
# ##0### #
#   0  # #
# ##0# # #
#0000# # #
#0## #   #
#0 # ### #
#0#### # #
#0000    #
####B#####
```


## Complexity Analysis

### Time Complexity

The time complexity of the BFS algorithm in a maze is \(O(V + E)\), where \(V\) is the number of vertices (cells in the maze) and \(E\) is the number of edges (connections between the cells). In a grid-based maze with `n` rows and `m` columns:
- \(V = n \times m\)
- \(E = O(4 \times V) = O(n \times m)\) because each cell can have up to 4 neighbors.

Thus, the time complexity simplifies to \(O(n \times m)\).

### Space Complexity

The space complexity of the BFS algorithm is \(O(V)\), where \(V\) is the number of vertices. This is because we need to store:
- The queue, which can hold up to \(V\) vertices in the worst case.
- The visited nodes or the node information in the maze.

Hence, the space complexity is also \(O(n \times m)\).

## Contributing

Contributions are welcome! If you have any improvements or bug fixes, please fork the repository, make your changes, and submit a pull request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a pull request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
