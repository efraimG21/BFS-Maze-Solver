//
//  Graph.h
//  BFS_maze
//
//  Created by efraim g on 12/08/2023.
//

#ifndef Graph_h
#define Graph_h

#define MAX_ROOTS 3

typedef struct Node Node_t;

struct Node{
    int y;
    int x;
    Node_t* father;
    Node_t* roots[MAX_ROOTS];
};

Node_t* AddNode(Node_t* father, int x, int y);
void DelteGraph(Node_t* haed);

#endif /* Graph_h */
