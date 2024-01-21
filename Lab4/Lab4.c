#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int Source;
    int Destination;
    int Weight;
};

// Structure to represent the graph
struct Graph {
    int VerticesCount;
    int EdgesCount;
    struct Edge* Edge; //array of edges
};

// Structure to represent subsets for the union-find algorithm
struct Subset {
    int Parent; //representative of the set
    int Rank;  //optimizing union operation.
};

// Function to create a graph
// Allocates memory for a graph and its edges.
struct Graph* CreateGraph(int verticesCount, int edgesCount) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->VerticesCount = verticesCount;
    graph->EdgesCount = edgesCount;
    graph->Edge = (struct Edge*)malloc(graph->EdgesCount * sizeof(struct Edge));
    return graph;
}

// Find operation of the union-find algorithm
//Finds the representative of the set to which the element i belongs using path compression.
int Find(struct Subset subsets[], int i) {
    if (subsets[i].Parent != i)
        subsets[i].Parent = Find(subsets, subsets[i].Parent);
    return subsets[i].Parent;
}

// Union operation of the union-find algorithm
//Performs union of two sets (with representatives x and y), considering rank to optimize the operation.
void Union(struct Subset subsets[], int x, int y) {
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);

    if (subsets[xroot].Rank < subsets[yroot].Rank)
        subsets[xroot].Parent = yroot;
    else if (subsets[xroot].Rank > subsets[yroot].Rank)
        subsets[yroot].Parent = xroot;
    else {
        subsets[yroot].Parent = xroot;
        ++subsets[xroot].Rank;
    }
}

// Comparison function for qsort to sort edges by weight
// Comparison function for qsort to sort edges by weight in non - decreasing order.
int CompareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->Weight > b1->Weight;
}

// Print the edges of the MST
void Print(struct Edge* result, int e) {
    for (int i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].Source, result[i].Destination, result[i].Weight);
}

// Kruskal's algorithm to find the Minimum Spanning Tree
// Sorts edges by weight, initializes subsets, and iterates through sorted edges to add to the MST if they don't form a cycle.
void Kruskal(struct Graph* graph) {
    int verticesCount = graph->VerticesCount;
    struct Edge* result = (struct Edge*)malloc(sizeof(struct Edge) * verticesCount);
    int i = 0;
    int e = 0;

    // Sort edges in non-decreasing order by weight
    qsort(graph->Edge, graph->EdgesCount, sizeof(graph->Edge[0]), CompareEdges);

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(verticesCount * sizeof(struct Subset));

    // Initialize subsets with single elements
    for (int v = 0; v < verticesCount; ++v) {
        subsets[v].Parent = v;
        subsets[v].Rank = 0;
    }

    // Iterate through all sorted edges
    while (e < verticesCount - 1) {
        struct Edge nextEdge = graph->Edge[i++];
        int x = Find(subsets, nextEdge.Source);
        int y = Find(subsets, nextEdge.Destination);

        // If including this edge does not cause a cycle, add it to the result
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the edges of the Minimum Spanning Tree
    Print(result, e);
}

// Main function
int main() {

    /*
    Kruskal's Algorithm:
    Edges are sorted using qsort.
    Disjoint sets are initialized, and Kruskal's algorithm is applied to find the Minimum Spanning Tree.
    Edges forming cycles are skipped, and the algorithm continues until the MST is complete.
    */
    int verticesCount = 4;
    int edgesCount = 5;
    struct Graph* graph = CreateGraph(verticesCount, edgesCount);

    // Define edges of the graph
    // Edge 0-1
    graph->Edge[0].Source = 0;
    graph->Edge[0].Destination = 1;
    graph->Edge[0].Weight = 10;

    // Edge 0-2
    graph->Edge[1].Source = 0;
    graph->Edge[1].Destination = 2;
    graph->Edge[1].Weight = 6;

    // Edge 0-3
    graph->Edge[2].Source = 0;
    graph->Edge[2].Destination = 3;
    graph->Edge[2].Weight = 5;

    // Edge 1-3
    graph->Edge[3].Source = 1;
    graph->Edge[3].Destination = 3;
    graph->Edge[3].Weight = 15;

    // Edge 2-3
    graph->Edge[4].Source = 2;
    graph->Edge[4].Destination = 3;
    graph->Edge[4].Weight = 4;

    // Run Kruskal's algorithm and print the Minimum Spanning Tree
    Kruskal(graph);

    // Return 0 to indicate successful execution
    return 0;
}
