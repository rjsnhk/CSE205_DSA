#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

int negCyclefloydWarshall(int graph[][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            return 1; // Negative cycle found
        }
    }
    return 0; // No negative cycle found
}

int main() {
    int graph[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (negCyclefloydWarshall(graph))
        printf("Yes");
    else
        printf("No");

    return 0;
}

