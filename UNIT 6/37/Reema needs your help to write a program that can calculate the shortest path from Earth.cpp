// You are using GCC
#include <stdio.h>

#define INF 1e7
#define MAXN 100

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V, int graph[MAXN][MAXN]) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dis[i][j] = graph[i][j];
            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}

void floydWarshall(int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}


void printPath(int path[], int n) {
    for (int i = 0; i < n - 1; ++i)
        printf("%d -> ", path[i]);
    printf("%d", path[n - 1]);
}

int main() {
    int V;
    scanf("%d", &V);

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int source = 0; 

    int dest;
    scanf("%d", &dest);


    int path[MAXN];
    path[0] = source;
    int index = 1;
    while (source != dest) {
        source = Next[source][dest];
        path[index++] = source;
    }

    printf("Shortest path from Earth to planet %d: ", dest);
    printPath(path, index);

    return 0;
}
