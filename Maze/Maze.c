//
//  Maze.c
//  BFS_maze
//
//  Created by efraim g on 13/08/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Graph.h"
#include "BreadthFirstSearch.h"
#include "Maze.h"



Maze_t* StartMaze(Queue_t** queue)
{
    Maze_t* maze = (Maze_t*)calloc(1, sizeof(Maze_t));
    if (!maze)
    {
        return NULL;
    }

    char board[SIZE][SIZE] = {
        {'#','#','#','#','A','#','#','#','#','#'},
        {'#',' ','#','#',' ','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ','#',' ','#'},
        {'#',' ','#','#',' ','#',' ','#',' ','#'},
        {'#',' ',' ',' ',' ','#',' ','#',' ','#'},
        {'#',' ','#','#',' ','#',' ',' ',' ','#'},
        {'#',' ',' ','#',' ','#','#','#',' ','#'},
        {'#',' ','#','#','#','#',' ','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#','#','B','#','#','#','#','#'}
    };

    for (int x = 0; x < SIZE; ++x)
    {
        for (int y = 0; y < SIZE; ++y)
        {
            maze->board[x][y].ch = board[x][y];
            maze->board[x][y].node = NULL;
            if (board[x][y] == 'A')
            {
                (*queue)->head = (Item_t*)malloc(sizeof(Item_t));
                (*queue)->tail = (*queue)->head;
                if (!(*queue)->head)
                {
                    FreeMaze(maze);
                    return NULL;
                }
                (*queue)->head->x = x;
                (*queue)->head->y = y;
                (*queue)->head->next = NULL;

                maze->board[x][y].node = (Node_t*)calloc(1, sizeof(Node_t));
                if (!maze->board[x][y].node)
                {
                    FreeMaze(maze);
                    return NULL;
                }
                maze->board[x][y].node->x = x;
                maze->board[x][y].node->y = y;
            }
        }
    }
    return maze;
}

void PrintMaze(Maze_t* maze)
{
    printf("\n\n");
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            printf("%c", maze->board[i][j].ch);
        }
        printf("\n");
    }
}


void GetRoute(Maze_t* maze, Item_t head)
{
    while (maze->board[head.x][head.y].ch != 'A')
    {
        maze->board[head.x][head.y].ch = '0';
        int next_x = maze->board[head.x][head.y].node->father->x;
        int next_y = maze->board[head.x][head.y].node->father->y;
        head.x = next_x;
        head.y = next_y;
    }
}

void FreeMaze(Maze_t* maze)
{
    for (int x = 0; x < SIZE; ++x)
    {
        for (int y = 0; y < SIZE; ++y)
        {
            if (maze->board[x][y].node)
            {
                DelteGraph(maze->board[x][y].node);
            }
        }
    }
    free(maze);
}
