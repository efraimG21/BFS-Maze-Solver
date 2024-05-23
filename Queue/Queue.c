//
//  Queue.c
//  BFS_maze
//
//  Created by efraim g on 12/08/2023.
//


#include <stdlib.h>
#include "Queue.h"


Item_t* AddItem(Item_t* tail, int x, int y)
{
    Item_t* item = (Item_t*)malloc(sizeof(Item_t));
    if (!item)
    {
        return NULL;
    }
    item->x = x;
    item->y = y;
    item->next = NULL;
    tail->next = item;
    return item;
}

Item_t* RemoveItem(Item_t* head)
{
    Item_t* newHead = head->next;
    free(head);
    return newHead;
}

void DeleteQueue(Item_t* head)
{
    while (head)
    {
        Item_t* next = head->next;
        free(head);
        head = next;
    }
}
