#include <stdio.h>

#define MAX_V 10

void enqueue(int* queue, int* rear, int vertex) {
    queue[++(*rear)] = vertex;
}

int dequeue(int* queue, int* front) {
    return queue[++(*front)];
}

void bfsOfGraph(int V, int adjList[MAX_V][MAX_V]) {
    int visited[MAX_V] = {0};
    int queue[MAX_V];
    int front = -1, rear = -1;
    
    int entrance = 0; // Start from the entrance (cell 0)
    int exit = V - 1; // Exit is the last cell

    enqueue(queue, &rear, entrance);
    visited[entrance] = 1;

    while (front != rear) {
        int currentCell = dequeue(queue, &front);
        printf("%d ", currentCell);

        if (currentCell == exit) {
            break; // Reached the exit
        }

        for (int i = 0; i < V; i++) {
            if (adjList[currentCell][i] && !visited[i]) {
                enqueue(queue, &rear, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adjList[MAX_V][MAX_V] = {0};

    for (int i = 0; i < E; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjList[u][v] = 1;
    }

    bfsOfGraph(V, adjList);

    return 0;
}

