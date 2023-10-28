#include <stdio.h>
#include <stdlib.h>

struct Job {
    int priority;
};

void swap(struct Job* a, struct Job* b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a new job into the min heap
void insertJob(struct Job heap[], int* heapSize, int newJobPriority) {
    if (*heapSize == 100) {
        printf("Heap is full. Cannot insert more jobs.\n");
        return;
    }

    int i = *heapSize;
    *heapSize = *heapSize + 1;
    heap[i].priority = newJobPriority;

    while (i > 0 && heap[(i - 1) / 2].priority > heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeapify(struct Job heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].priority < heap[smallest].priority)
        smallest = left;

    if (right < n && heap[right].priority < heap[smallest].priority)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        MinHeapify(heap, n, smallest);
    }
}

void buildMinHeap(struct Job heap[], int heapSize) {
    for (int i = (heapSize - 2) / 2; i >= 0; i--)
        MinHeapify(heap, heapSize, i);
}

void printHeap(struct Job heap[], int heapSize) {
    buildMinHeap(heap, heapSize);
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].priority);
    }
    printf("\n");
}

int main() {
    struct Job minHeap[100];
    int heapSize = 0;

    while (1) {
        int newJobPriority;
        if (scanf("%d", &newJobPriority) != 1) {
            break;
        }
        insertJob(minHeap, &heapSize, newJobPriority);
    }

    printHeap(minHeap, heapSize);

    return 0;
}

