///topological sorting
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int indeg[5];
int toposort[5];

struct listNode {
int data;
struct listNode* next;
};

struct adjList{
struct listNode* head;
};

struct graph{
int V;
struct adjList* arr;
};

struct graph* createGraph(int v){
struct graph*  g=(struct graph*)malloc(sizeof(struct graph));
g->V=v;
g->arr=(struct adjList*)malloc(v*sizeof(struct adjList));
for(int i=0;i<v;i++)
    g->arr[i].head=NULL;
return g;
};

void addEdge(struct graph *g,int s, int d){
struct listNode *nnode=(struct listNode*)malloc(sizeof(struct listNode));
nnode->data=d;
nnode->next=g->arr[s].head;
g->arr[s].head=nnode;
}

void printGraph(struct graph* gp){
    printf("adjacency list of vertex :\n");
for (int vtx=0;vtx<gp->V;vtx++){
    struct listNode* p=gp->arr[vtx].head;  ///need to remember
    printf("%d:",vtx);
    while (p){
        printf("->%d",p->data);
        p=p->next;
        }
    printf("\n");
    }
}

void inDegree(struct graph* g){
struct listNode *p;
for(int i=0;i<g->V;i++){
    p=g->arr[i].head;
    while(p){
        ++indeg[p->data];
        p=p->next;
        }
    }
}

void topsort(struct graph *g){
int i,cyc=0;
for(i=0;i<g->V;i++){
    if(indeg[i]==0) q.push(i);
    }
while(!q.empty()){
    toposort[cyc++]=q.front();
    struct listNode* p=g->arr[q.front()].head;
    q.pop();
    while(p){
        if(--indeg[p->data]==0) q.push(p->data);
        p=p->next;
    }
}
if(cyc!=g->V) {printf("graph has cycle\n");}
}
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 1);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);
    inDegree(graph);
    topsort(graph);
    for(int i=0;i<5;i++) printf("%d ",toposort[i]);

    return 0;
}
