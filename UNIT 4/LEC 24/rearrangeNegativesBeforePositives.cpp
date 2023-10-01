#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void rearrangeNegativesBeforePositives(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        if (arr[left] < 0 && arr[right] >= 0) {
            // Swap negative from the left with positive from the right
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        } else {
            if (arr[left] >= 0) left++;
            if (arr[right] < 0) right--;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    rearrangeNegativesBeforePositives(arr, n);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

