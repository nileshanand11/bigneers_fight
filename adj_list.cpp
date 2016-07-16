/// graph with adj list
//http://www.geeksforgeeks.org/graph-and-its-representations/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct listNode{
int data;
struct listNode* next;
};

struct adjList{
struct listNode* head;
};

struct graph{
int v;
struct adjList* arr;
};

struct graph* createGraph(int V){
struct graph* g=(struct graph*)malloc(sizeof(struct graph));
g->v=V;
g->arr=(struct adjList*)malloc(V*sizeof(struct adjList));

for (int i=0;i<V;i++)
    g->arr[i].head=NULL;
return g;
};

void addEdge(struct graph *g, int src, int dest){
struct listNode* nnode=(struct listNode*)malloc(sizeof(struct listNode));
nnode->data=dest;
nnode->next=g->arr[src].head;
g->arr[src].head=nnode;
}

void printGraph(struct graph* gp){
    printf("adjacency list of vertex :\n");
for (int vtx=0;vtx<gp->v;vtx++){
    struct listNode* p=gp->arr[vtx].head;  ///need to remember
    printf("%d:",vtx);
    while (p){
        printf("->%d",p->data);
        p=p->next;
        }
    printf("\n");
    }
}
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}
