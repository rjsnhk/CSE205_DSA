#include <stdio.h>
#include <stdlib.h>

struct PrintJob {
    int importance;
};

void swap(struct PrintJob* a, struct PrintJob* b) {
    struct PrintJob temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new print job into the binary heap
void insertPrintJob(struct PrintJob heap[], int* heapSize, struct PrintJob newPrintJob) {
    if (*heapSize == 100) {
        printf("Heap is full. Cannot insert more print jobs.\n");
        return;
    }

    int i = *heapSize;
    *heapSize = *heapSize + 1;
    heap[i] = newPrintJob;

    while (i > 0 && heap[(i - 1) / 2].importance > heap[i].importance) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeapify(struct PrintJob heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].importance < heap[smallest].importance)
        smallest = left;

    if (right < n && heap[right].importance < heap[smallest].importance)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        MinHeapify(heap, n, smallest);
    }
}

void buildMinHeap(struct PrintJob heap[], int heapSize) {
    for (int i = (heapSize - 2) / 2; i >= 0; i--)
        MinHeapify(heap, heapSize, i);
}

void printHeap(struct PrintJob heap[], int heapSize) {
    buildMinHeap(heap, heapSize);
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].importance);
    }
    printf("\n");
}

int main() {
    struct PrintJob binaryHeap[100];
    int heapSize = 0;

    while (1) {
        struct PrintJob newPrintJob;
        if (scanf("%d", &newPrintJob.importance) != 1) {
            break;
        }
        insertPrintJob(binaryHeap, &heapSize, newPrintJob);
    }

    printHeap(binaryHeap, heapSize);

    return 0;
}

