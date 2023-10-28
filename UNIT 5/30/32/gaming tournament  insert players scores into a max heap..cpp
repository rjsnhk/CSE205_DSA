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

void insertScore(struct Player heap[], int* heapSize, struct Player newPlayer) {
  // Increase the heap size by 1.
  *heapSize += 1;

  // Add the new player to the last position in the heap.
  heap[*heapSize - 1] = newPlayer;

  // Percolate the new player up the heap until it is in the correct position.
  int childIndex = *heapSize - 1;
  while (childIndex > 0 && heap[childIndex].score > heap[(childIndex - 1) / 2].score) {
    swap(&heap[childIndex], &heap[(childIndex - 1) / 2]);
    childIndex = (childIndex - 1) / 2;
  }
}

void printHeap(struct Player heap[], int heapSize) {
  for (int i = 0; i < heapSize; i++) {
    printf("%d ", heap[i].score);
  }
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

    insertScore(maxHeap, &heapSize, newPlayer);
  }

  printHeap(maxHeap, heapSize);

  return 0;
}

