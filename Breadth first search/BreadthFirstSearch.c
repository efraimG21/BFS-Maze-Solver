//
//  BreadthFirstSearch.c
//  BFS_maze
//
//  Created by efraim g on 13/08/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#include "Graph.h"
#include "Maze.h"
#include "BreadthFirstSearch.h"

#define SIZE 10


int SetRoots(Board_t board[SIZE][SIZE], Queue_t* queue)
{
    if (queue->head == NULL)
    {
        return true;
    }
    
    int x = queue->head->x;
    int y = queue->head->y;
    
    if ((x != 0 && board[x - 1][y].ch == 'B') ||
        (x != SIZE - 1 && board[x + 1][y].ch == 'B') ||
        (y != 0 && board[x][y - 1].ch == 'B') ||
        (y != SIZE - 1 && board[x][y + 1].ch == 'B'))
    {
        return true;
    }
    
    if (x != 0 && board[x - 1][y].ch == ' ' && !board[x - 1][y].node)
    {
        queue->tail = AddItem(queue->tail, x - 1, y);
        board[x - 1][y].node = AddNode(board[x][y].node, x - 1, y);
    }
    if (x != SIZE - 1 && board[x + 1][y].ch == ' ' && !board[x + 1][y].node)
    {
        queue->tail = AddItem(queue->tail, x + 1, y);
        board[x + 1][y].node = AddNode(board[x][y].node, x + 1, y);
    }
    if (y != 0 && board[x][y - 1].ch == ' ' && !board[x][y - 1].node)
    {
        queue->tail = AddItem(queue->tail, x, y - 1);
        board[x][y - 1].node = AddNode(board[x][y].node, x, y - 1);
    }
    if (y != SIZE - 1 && board[x][y + 1].ch == ' ' && !board[x][y + 1].node)
    {
        queue->tail = AddItem(queue->tail, x, y + 1);
        board[x][y + 1].node = AddNode(board[x][y].node, x, y + 1);
    }
    
    queue->head = RemoveItem(queue->head);
    return false;
}

