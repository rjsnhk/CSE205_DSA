#include <stdio.h>

void min_heap(int *a, int m, int n) {
    int j, temp;
    temp = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j+1] < a[j]) {
            j = j + 1;
        }
        if (temp <= a[j]) {
            break;
        } else if (temp > a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void build_minheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heap(a, k, n);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n + 1]; // Adjusted array size to start from index 1
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build_minheap(a, n);
    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

