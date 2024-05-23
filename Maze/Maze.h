//
//  Maze.h
//  BFS_maze
//
//  Created by efraim g on 13/08/2023.
//

#ifndef Maze_h
#define Maze_h

#include "Graph.h"

#define SIZE 10

typedef struct Board{
    char ch;
    Node_t* node;
}Board_t;

typedef struct Maze {
    Board_t board[SIZE][SIZE];
} Maze_t;

Maze_t* StartMaze(Queue_t** queue);
void PrintMaze(Maze_t* maze);
void GetRoute(Maze_t* maze, Item_t haed);
void FreeMaze(Maze_t* maze);

#endif /* Maze_h */
