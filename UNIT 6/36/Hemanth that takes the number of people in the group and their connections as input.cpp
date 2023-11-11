#include <stdio.h>

#define MAX_N 10

// Function to find a prominent figure using Warshall's Algorithm
int findProminentFigure(int acquaintances[MAX_N][MAX_N], int n) {
    int inDegree[MAX_N] = {0};
    int outDegree[MAX_N] = {0};

    // Calculate in-degrees and out-degrees for each person
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inDegree[i] += acquaintances[j][i];
            outDegree[i] += acquaintances[i][j];
        }
    }

    // Check if there is a prominent figure
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == n - 1 && outDegree[i] == 0) {
            return i;
        }
    }

    return -1; // No prominent figure found
}

int main() {
    int n;
    scanf("%d", &n);
    
    int acquaintances[MAX_N][MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &acquaintances[i][j]);
        }
    }

    int prominentFigureIndex = findProminentFigure(acquaintances, n);

    if (prominentFigureIndex != -1) {
        printf("A prominent figure is present at index %d.", prominentFigureIndex);
    } else {
        printf("There is no prominent figure in the group.");
    }

    return 0;
}

