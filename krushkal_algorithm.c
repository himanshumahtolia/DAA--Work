#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CITIES 100

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int maximum_budget(struct Edge edges[], int num_edges, int num_vertices) {
    struct Subset* subsets = (struct Subset*)malloc(num_vertices * sizeof(struct Subset));
    int max_spanning_weight = 0;

    for (int i = 0; i < num_vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, num_edges, sizeof(struct Edge), compare);

    for (int i = 0; i < num_edges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int src_parent = find(subsets, src);
        int dest_parent = find(subsets, dest);

        if (src_parent != dest_parent) {
            max_spanning_weight += edges[i].weight;
            unionSets(subsets, src_parent, dest_parent);
        }
    }

    free(subsets);

    return max_spanning_weight;
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    int num_edges = num_vertices * (num_vertices - 1) / 2;
    struct Edge edges[num_edges];

    int edge_index = 0;

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < i; j++) {
            int weight;
            scanf("%d",&weight);
        }
    }
}

