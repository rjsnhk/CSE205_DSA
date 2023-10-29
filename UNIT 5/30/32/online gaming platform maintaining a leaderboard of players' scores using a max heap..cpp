#include <stdio.h>
#include <stdlib.h>

struct Player {
    int score;
};

void swap(struct Player* a, struct Player* b) {
    struct Player temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(struct Player heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].score > heap[largest].score)
        largest = left;

    if (right < n && heap[right].score > heap[largest].score)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        MaxHeapify(heap, n, largest);
    }
}

void insertPlayer(struct Player heap[], int* heapSize, struct Player newPlayer) {
    if (*heapSize == 100) {
        printf("Max heap is full. Cannot insert more players.\n");
        return;
    }

    int i = *heapSize;
    *heapSize = *heapSize + 1;
    heap[i] = newPlayer;

    while (i > 0 && heap[(i - 1) / 2].score < heap[i].score) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct Player heap[], int heapSize) {
    for (int i = 0; i < heapSize; ++i)
        printf("%d ", heap[i].score);
    printf("\n");
}

int main() {
    struct Player maxHeap[100];
    int heapSize = 0;

    while (1) {
        struct Player newPlayer;
        if (scanf("%d", &newPlayer.score) != 1) {
            break;
        }

        insertPlayer(maxHeap, &heapSize, newPlayer);
    }

    printHeap(maxHeap, heapSize);

    return 0;
}

