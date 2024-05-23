//
//  Queue.h
//  BFS_maze
//
//  Created by efraim g on 12/08/2023.
//

#ifndef Queue_h
#define Queue_h

typedef struct Item Item_t;

struct Item{
    int x;
    int y;
    Item_t* next;
};

typedef struct Queue{
    Item_t* head;
    Item_t* tail;
}Queue_t;

Item_t* AddItem(Item_t* tail, int x, int y);
Item_t* RemoveItem(Item_t* haed);
void DeleteQueue(Item_t* head);

#endif /* Queue_h */
