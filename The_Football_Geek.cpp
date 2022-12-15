/* Language : C++ */
#include <iostream>
using namespace std;
 
#define MAXV 100 /* maximum number of vertices */
 
/* defining a structure called edgenode */
typedef struct edgenode {
    int y; /* the index of the node to which given node is connected to */
    long long int weight; /* edge weight*/
    struct edgenode *next; /* next edge in list */
} edgenode;
 
/* defining a structure called graph */
typedef struct {
    edgenode *edges[MAXV+1]; /* adjacency info */
    int degree[MAXV+1]; /* outdegree of each vertex */
    int nedges; /* number of edges in the graph */
} graph;
 
void initialize_graph(graph *g){
    /* Initializing the values of the graph */
    g->nedges = 0;
    for (int i = 0; i <= MAXV; i++) {
        g->degree[i] = 0;
    }
    for (int i = 0; i <= MAXV; i++) {
        g->edges[i] = NULL;
    }
}
 
void insert_edge(graph *g, int x, int y, long long int distance) {
    edgenode *p; /* temporary pointer */
    /* adding edge from x to y */
    p = (edgenode*)malloc(sizeof(edgenode)); /* allocate edgenode storage */
    p->weight = distance;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p; /* insert at head of list */
    g->degree[x]++;
 
    /* adding edge from y to x */
    p = (edgenode*)malloc(sizeof(edgenode)); /* allocate edgenode storage */
    p->weight = distance;
    p->y = x;
    p->next = g->edges[y];
    g->edges[y] = p; /* insert at head of list */
    g->degree[y]++;
 
    g->nedges++;
}
 
void insertStadiumEdges(graph *g){
    /*
    0-Mangalore
 
    Stadiums (Graph Nodes):
    1- Al Bayt Stadium
    2-Khalifa International Stadium
    3-Al Thumama Stadium
    4-Ahmed Bin Ali Stadium
    5-Lusail Stadium
    6-Stadium 974
    7-Education City Stadium
    8-Al Janoub Stadium
    */
 
    /* Inserting edges in the graph */
 
    insert_edge(g, 0, 1, 2823246391);
 
    insert_edge(g, 1, 0, 2823246391);
    insert_edge(g, 1, 2, 15598039);
    insert_edge(g, 1, 3, 28403812);
    insert_edge(g, 1, 4, 24197704);
    insert_edge(g, 1, 5, 17202197);
    insert_edge(g, 1, 6, 25868766);
    insert_edge(g, 1, 7, 31003300);
    insert_edge(g, 1, 8, 64159482);
 
    insert_edge(g, 2, 3, 12531667);
    insert_edge(g, 2, 4, 26579213);
    insert_edge(g, 2, 5, 20028955);
    insert_edge(g, 2, 6, 19069890);
    insert_edge(g, 2, 7, 24878893);
    insert_edge(g, 2, 8, 19841857);
 
    insert_edge(g, 3, 4, 27611924);
    insert_edge(g, 3, 5, 19528622);
    insert_edge(g, 3, 6, 11563834);
    insert_edge(g, 3, 7, 17417308);
    insert_edge(g, 3, 8, 24664284);
 
    insert_edge(g, 4, 5, 21931564);
    insert_edge(g, 4, 6, 21560636);
    insert_edge(g, 4, 7, 17634717);
    insert_edge(g, 4, 8, 24061999);
 
    insert_edge(g, 5, 6, 22051346);
    insert_edge(g, 5, 7, 26924541);
    insert_edge(g, 5, 8, 23643843);
 
    insert_edge(g, 6, 7, 16649573);
    insert_edge(g, 6, 8, 26147510);
 
    insert_edge(g, 7, 8, 27764295);
}
 
bool visited[MAXV+1]; /* maintaining a record of vertices that have already been visited */
 
void initialize_search(graph *g){
    /* Initializing the search */
    int nvertices = 8;
    for (int i = 0; i <= nvertices; i++) {
        visited[i] = false;
    }
}
 
void find_path(graph *g, int start) {
    int v; /* current vertex */
    int y; /* successor vertex */
    int total_distance_covered = 0;
 
    edgenode *p, *temp; /* temporary pointer */
    /* staring from node "start", we visit a node only if it hasn't been visited yet, and generate a path */
    visited[start] = true;
    temp = g->edges[start];
    while (true) {
        while(temp!=NULL && visited[temp->y]==true){
            temp=temp->next;
        }
        if(temp==NULL) break;
 
        total_distance_covered = total_distance_covered + temp->weight;
 
        visited[temp->y]=true;
        temp = g->edges[temp->y];
    }
 
    printf("\n");
    printf("The total travel distance is %d", total_distance_covered);
    printf("\n");
}
 
 
int main(){
    graph* g=new graph();
    initialize_graph(g);
    insertStadiumEdges(g);
 
    initialize_search(g);
    find_path(g, 0);
}
