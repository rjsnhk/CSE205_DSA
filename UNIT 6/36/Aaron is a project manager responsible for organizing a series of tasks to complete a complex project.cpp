// You are using GCC
#include <iostream>
using namespace std;

#define MAX_TASKS 100

bool canCompleteAllTasks(int n, int dependencies[][2]) {
    // Create the adjacency matrix
    int adjacency_matrix[MAX_TASKS][MAX_TASKS] = {0};
    for (int i = 0; i < n; ++i) {
        adjacency_matrix[dependencies[i][1]][dependencies[i][0]] = 1;
    }

    // Apply Warshall's Algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adjacency_matrix[i][j] = adjacency_matrix[i][j] || (adjacency_matrix[i][k] && adjacency_matrix[k][j]);
            }
        }
    }

    // Check if there is a cycle in the graph
    for (int i = 0; i < n; ++i) {
        if (adjacency_matrix[i][i]) {
            return false;
        }
    }

    return true;
}


int main() {
    int n;
    cin >> n;

    int dependencies[MAX_TASKS][2];
    for (int i = 0; i < n; ++i) {
        cin >> dependencies[i][0] >> dependencies[i][1];
    }

    if (canCompleteAllTasks(n, dependencies)) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }

    return 0;
}
