//
//  Graph.c
//  BFS_maze
//
//  Created by efraim g on 12/08/2023.
//

#include <stdlib.h>
#include "Graph.h"


void Req (Node_t* haed, int i);
void FreeRoots(Node_t* haed);
void ReqDelteGraph(Node_t* haed, int i);

Node_t* AddNode(Node_t* father, int x, int y)
{
    int i = 0;
    Node_t* node = (Node_t*)malloc(sizeof(Node_t));
    if (!node)
    {
        return NULL;
    }
    while (father->roots[i])
    {
        ++i;
    }
    father->roots[i] = node;
    node->father = father;
    node->x = x;
    node->y = y;
    return node;
}


void DelteGraph(Node_t* head)
{
    ReqDelteGraph(head, 0);
    free(head);
}


void ReqDelteGraph(Node_t* head, int i)
{
    if (head->roots[i] == NULL && head->father != NULL)
    {
        FreeRoots(head->father);
        return;
    }
    if (head->roots[i]->roots[0] != NULL)
    {
        ReqDelteGraph(head->roots[i], 0);
    }
    ReqDelteGraph(head->roots[i], 1 + i);
}

void FreeRoots(Node_t* head)
{
//    for (int i = 0; (i < 3) && (head->roots[i] != NULL); ++i)
//    {
//        free(head->roots[i]);
//    }
}
