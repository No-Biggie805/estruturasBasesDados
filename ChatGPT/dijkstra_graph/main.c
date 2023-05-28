#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Edge
{
    int dest;
    float weight;
    struct Edge *next;
} Edge;

typedef struct Vertex // doubly linked list
{
    int numVertices;
    char name[100];
    Edge *edges;
    struct Vertex *next;
    float distance;
    struct Vertex *previous;
} Vertex;

typedef struct Graph
{
    Vertex *vertices;
    int numVertices;
} Graph;

Vertex *createVertex(char name[])
{
    Vertex *newVertex = (Vertex *)malloc(sizeof(Vertex));
    if (newVertex != NULL)
    {
        strcpy(newVertex->name, name);
        newVertex->edges = NULL;
        newVertex->next = NULL;
        newVertex->distance = FLT_MAX;
        newVertex->previous = NULL;
    }
    return newVertex;
}

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

void addVertex(Graph *graph, char name[])
{
    Vertex *newVertex = createVertex(name);
    if (newVertex == NULL)
    {
        printf("Error: Unable to create a new vertex\n");
        return;
    }

    newVertex->next = graph->vertices;
    graph->vertices = newVertex;
    graph->numVertices++;
}

void addEdge(Graph *graph, char source[], char dest[], float weight)
{
    Vertex *srcVertex = graph->vertices;
    Vertex *destVertex = graph->vertices;

    while (srcVertex != NULL && strcmp(srcVertex->name, source) != 0)
        srcVertex = srcVertex->next;

    while (destVertex != NULL && strcmp(destVertex->name, dest) != 0)
        destVertex = destVertex->next;

    if (srcVertex == NULL || destVertex == NULL)
    {
        printf("Error: Source or destination vertex not found\n");
        return;
    }

    Edge *newEdge = createEdge(destVertex->numVertices, weight);
    if (newEdge == NULL)
    {
        printf("Error: Unable to create a new edge\n");
        return;
    }

    newEdge->next = srcVertex->edges;
    srcVertex->edges = newEdge;
}

Vertex *getMinDistanceVertex(Graph *graph, bool visited[]) // Importante?
{
    float minDistance = FLT_MAX;
    Vertex *minVertex = NULL;

    Vertex *vertex = graph->vertices;
    while (vertex != NULL)
    {
        if (!visited[vertex->numVertices] && vertex->distance <= minDistance)
        {
            minDistance = vertex->distance;
            minVertex = vertex;
        }
        vertex = vertex->next;
    }

    return minVertex;
}

void printPath(Vertex *vertex) // Funcao caminho
{
    if (vertex->previous != NULL)
    {
        printPath(vertex->previous);
        printf(" -> ");
    }
    printf("%s", vertex->name);
}

void printShortestPaths(Graph *graph, char source[])
{
    Vertex *sourceVertex = graph->vertices;
    while (sourceVertex != NULL && strcmp(sourceVertex->name, source) != 0)
        sourceVertex = sourceVertex->next;

    if (sourceVertex == NULL)
    {
        printf("Error: Source vertex not found\n");
        return;
    }

    bool visited[MAX_VERTICES] = {false};
    sourceVertex->distance = 0;

    for (int i = 0; i < graph->numVertices; i++)
    {
        Vertex *minVertex = getMinDistanceVertex(graph, visited);
        if (minVertex == NULL)
            break;

        visited[minVertex->numVertices] = true;

        Edge *edge = minVertex->edges;
        while (edge != NULL)
        {
            Vertex *destVertex = graph->vertices;
            while (destVertex != NULL && destVertex->numVertices != edge->dest)
                destVertex = destVertex->next;

            if (destVertex != NULL)
            {
                float distance = minVertex->distance + edge->weight;
                if (distance < destVertex->distance)
                {
                    destVertex->distance = distance;
                    destVertex->previous = minVertex;
                }
            }

            edge = edge->next;
        }
    }

    Vertex *vertex = graph->vertices;
    while (vertex != NULL)
    {
        printf("Shortest path from %s to %s: ", source, vertex->name);
        if (vertex->distance == FLT_MAX)
        {
            printf("No path found\n");
        }
        else
        {
            printPath(vertex);
            printf("\n");
        }
        vertex = vertex->next;
    }
}

void freeGraph(Graph *graph)
{
    Vertex *vertex = graph->vertices;
    while (vertex != NULL)
    {
        Edge *edge = vertex->edges;
        while (edge != NULL)
        {
            Edge *nextEdge = edge->next;
            free(edge);
            edge = nextEdge;
        }
        Vertex *nextVertex = vertex->next;
        free(vertex);
        vertex = nextVertex;
    }
}

int main()
{
    Graph graph;
    graph.vertices = NULL;
    graph.numVertices = 0;

    /*Feito supostamente*/
    // Add vertices to the graph
    addVertex(&graph, "A");
    addVertex(&graph, "B");
    addVertex(&graph, "C");
    addVertex(&graph, "D");

    /*Feito supostamente*/
    // Add edges to the graph
    addEdge(&graph, "A", "B", 5.0);
    addEdge(&graph, "B", "C", 3.0);
    addEdge(&graph, "C", "D", 2.0);
    addEdge(&graph, "D", "A", 4.0);

    // Find the shortest paths from vertex "A"
    printShortestPaths(&graph, "A");

    // Free the graph memory
    freeGraph(&graph);

    return 0;
}
