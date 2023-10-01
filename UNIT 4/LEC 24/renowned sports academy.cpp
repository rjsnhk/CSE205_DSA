#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap two athlete names and their corresponding heights
void swap(char **names, int *heights, int i, int j) {
    char *temp_name = names[i];
    names[i] = names[j];
    names[j] = temp_name;

    int temp_height = heights[i];
    heights[i] = heights[j];
    heights[j] = temp_height;
}

// Partition function to select a pivot and rearrange elements
int partition(char **names, int *heights, int low, int high) {
    int pivot = heights[high]; // Choose the pivot as the height
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (heights[j] >= pivot) {
            i++;
            swap(names, heights, i, j);
        }
    }
    swap(names, heights, i + 1, high);
    return i + 1;
}

// Quick-Sort algorithm to sort athletes by height in descending order
void quickSort(char **names, int *heights, int low, int high) {
    if (low < high) {
        int pi = partition(names, heights, low, high);
        quickSort(names, heights, low, pi - 1);
        quickSort(names, heights, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char **names = (char **)malloc(n * sizeof(char *));
    int *heights = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        names[i] = (char *)malloc(100 * sizeof(char)); // Assuming max name length is 100
        scanf("%s %d", names[i], &heights[i]);
    }

    quickSort(names, heights, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
        free(names[i]);
    }

    free(names);
    free(heights);
    return 0;
}

