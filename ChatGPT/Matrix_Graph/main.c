#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100

// Structure for the graph
typedef struct Graph {
    int numVertices;
    char vertices[MAX_VERTICES][100]; // Array to store vertex names
    float edges[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to store edge weights
} Graph;

// Function to initialize the graph
void initializeGraph(Graph* graph) {
    graph->numVertices = 0;
    memset(graph->vertices, 0, sizeof(graph->vertices));
    memset(graph->edges, 0, sizeof(graph->edges));
}

// Function to add a vertex to the graph
void addVertex(Graph* graph, char name[]) {
    if (graph->numVertices >= MAX_VERTICES) {
        printf("Error: Exceeded the maximum number of vertices\n");
        return;
    }

    strcpy(graph->vertices[graph->numVertices], name);
    graph->numVertices++;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int srcVertex, int destVertex, float weight) {
    if (srcVertex >= graph->numVertices || destVertex >= graph->numVertices) {
        printf("Error: Invalid source or destination vertex\n");
        return;
    }

    graph->edges[srcVertex][destVertex] = weight;
    graph->edges[destVertex][srcVertex] = weight; // Assuming an undirected graph
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %s:\n", graph->vertices[i]);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->edges[i][j] != 0) {
                printf("  --> Destination: %s, Weight: %.2f\n", graph->vertices[j], graph->edges[i][j]);
            }
        }
    }
}

int main() {
    // Create a new graph
    Graph graph;
    initializeGraph(&graph);

    // Add vertices to the graph
    addVertex(&graph, "A");
    addVertex(&graph, "B");
    addVertex(&graph, "C");
    addVertex(&graph, "D");

    // Add edges to the graph
    addEdge(&graph, 0, 1, 5.0);
    addEdge(&graph, 1, 2, 3.0);
    addEdge(&graph, 2, 3, 2.0);
    addEdge(&graph, 3, 0, 4.0);

    // Print the graph
    printGraph(&graph);

    return 0;
}
