#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 100

int minimum_cost(int graph[MAX_CITIES][MAX_CITIES], int num_cities) {
    bool visited[MAX_CITIES] = { false };
    int MST[MAX_CITIES];
    int start_city = 0;
int min_cost = 0;

    visited[start_city] = true;
    int edges[MAX_CITIES];
    int num_edges = 0;

    for (int i = 0; i < num_cities; i++) {
        if (graph[start_city][i] != 0) {
            edges[num_edges++] = i;
        }
    }

    while (num_edges > 0) {
        int min_cost_edge = INT_MAX;
        int min_cost_dest = -1;

        for (int i = 0; i < num_edges; i++) {
            int dest = edges[i];

            if (!visited[dest] && graph[start_city][dest] < min_cost_edge) {
                min_cost_edge = graph[start_city][dest];
                min_cost_dest = dest;
            }
        }

        if (min_cost_dest != -1) {
            visited[min_cost_dest] = true;
            MST[min_cost_dest] = min_cost_edge;
            min_cost += min_cost_edge;

            for (int i = 0; i < num_cities; i++) {
                if (graph[min_cost_dest][i] != 0 && !visited[i]) {
                    edges[num_edges++] = i;
                       num_edges--;
        edges[min_cost_dest] = edges[num_edges];
    }

    return min_cost;
}

int main() {
    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    int graph[MAX_CITIES][MAX_CITIES];
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_cities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int min_cost = minimum_cost(graph, num_cities);
    printf("Minimum cost: %d\n", min_cost);
    return 0;
}
