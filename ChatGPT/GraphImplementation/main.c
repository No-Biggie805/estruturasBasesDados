#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure for an edge
typedef struct Edge
{
    int dest;     // Destination vertex
    float weight; // Weight of the edge
    struct Edge *next;
} Edge;

// Structure for a vertex
typedef struct Vertex
{
    int numVertices;
    char name[100]; // Name of the vertex
    Edge *edges;    // Linked list of edges
    struct Vertex *next;
} Vertex;

// Structure for the graph
typedef struct Graph
{
    Vertex *vertices; // Linked list of vertices
} Graph;

// Function to create a new vertex
Vertex *createVertex(char name[])
{
    Vertex *newVertex = (Vertex *)malloc(sizeof(Vertex));
    if (newVertex != NULL)
    {
        strcpy(newVertex->name, name);
        newVertex->edges = NULL;
        newVertex->next = NULL;
    }
    return newVertex;
}

// Function to create a new edge
Edge *createEdge(int dest, float weight)
{
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    if (newEdge != NULL)
    {
        newEdge->dest = dest;
        newEdge->weight = weight;
        newEdge->next = NULL;
    }
    return newEdge;
}

// Function to add a vertex to the graph
void addVertex(Graph *graph, char name[])
{
    Vertex *newVertex = createVertex(name);
    if (newVertex == NULL)
    {
        printf("Error: Unable to create a new vertex\n");
        return;
    }

    // Add the new vertex to the beginning of the linked list
    newVertex->next = graph->vertices;
    graph->vertices = newVertex;
}

// Function to add an edge between two vertices
void addEdge(Graph *graph, char source[], char dest[], float weight)
{
    Vertex *srcVertex = graph->vertices;
    Vertex *destVertex = graph->vertices;

    // Find the source and destination vertices
    while (srcVertex != NULL && strcmp(srcVertex->name, source) != 0)
        srcVertex = srcVertex->next;

    while (destVertex != NULL && strcmp(destVertex->name, dest) != 0)
        destVertex = destVertex->next;

    if (srcVertex == NULL || destVertex == NULL)
    {
        printf("Error: Source or destination vertex not found\n");
        return;
    }

    // Create a new edge
    Edge *newEdge = createEdge(destVertex->numVertices, weight);
    if (newEdge == NULL)
    {
        printf("Error: Unable to create a new edge\n");
        return;
    }

    // Add the new edge to the beginning of the source vertex's edge list
    newEdge->next = srcVertex->edges;
    srcVertex->edges = newEdge;
}

const char *getVertexName(Graph *graph, int vertexNum)
{
    Vertex *vertex = graph->vertices;
    while (vertex != NULL)
    {
        if (vertex->numVertices == vertexNum)
        {
            return vertex->name;
        }
        vertex = vertex->next;
    }
    return NULL; // Vertex not found
}

// Function to print the graph
void printGraph(Graph *graph)
{
    Vertex *vertex = graph->vertices;
    while (vertex != NULL)
    {
        printf("Vertex: %s\n", vertex->name);
        Edge *edge = vertex->edges;
        while (edge != NULL)
        {
            printf("  --> Destination: %s, Weight: %.2f\n", getVertexName(graph, edge->dest), edge->weight);
            edge = edge->next;
        }
        vertex = vertex->next;
    }
}

int main()
{
    // Create a new graph
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL)
    {
        printf("Error: Unable to create a new graph\n");
        return 1;
    }

    graph->vertices = NULL;

    // Add vertices to the graph
    addVertex(graph, "A");
    addVertex(graph, "B");
    addVertex(graph, "C");
    addVertex(graph, "D");

    // Add edges to the graph
    addEdge(graph, "A", "B", 5.0);
    addEdge(graph, "B", "C", 3.0);
    addEdge(graph, "C", "D", 2.0);
    addEdge(graph, "D", "A", 4.0);

    // Print the graph
    printGraph(graph);

    return 0;
}
