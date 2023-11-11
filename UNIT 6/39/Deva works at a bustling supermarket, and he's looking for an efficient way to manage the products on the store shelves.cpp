#include <stdio.h>

#define SIZE 100

int calHash(int key, int size) {
    return key % size;
}

int main() {
    int size, numKeys;
    scanf("%d", &size);
    scanf("%d", &numKeys);

    int keys[numKeys];
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < numKeys; ++i) {
        scanf("%d", &keys[i]);
    }

    for (int i = 0; i < numKeys; ++i) {
        int index = calHash(keys[i], size);
        int originalIndex = index;

        while (hashTable[index] != -1) {
            index = (index + 1) % size; // Linear probing to find the next available slot
            if (index == originalIndex) {
                // If we have cycled through the entire table, exit (shouldn't happen with the given constraints)
                break;
            }
        }

        hashTable[index] = keys[i];
        if (i != 0) {
            printf(" ");
        }
        printf("%d", index);
    }
    printf("\n");

    return 0;
}

