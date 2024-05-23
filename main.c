//
//  main.c
//  BFS_maze
//
//  Created by efraim g on 12/08/2023.
//


#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Maze.h"
#include "BreadthFirstSearch.h"


int main(void)
{
    
    Queue_t* queue = (Queue_t*)malloc(sizeof(Queue_t));
    if (!queue)
    {
        fprintf(stderr, "Memory allocation failed for queue\n");
        return EXIT_FAILURE;
    }
    Maze_t* maze = StartMaze(&queue);
    if (!maze)
    {
        fprintf(stderr, "Memory allocation failed for maze\n");
        free(queue);
        return EXIT_FAILURE;
    }

    PrintMaze(maze);

    while (!SetRoots(maze->board, queue));
    
    GetRoute(maze, *queue->head);
    PrintMaze(maze);
    
    DeleteQueue(queue->head);
    free(queue);
    FreeMaze(maze);
    
    
    return 0;
}

