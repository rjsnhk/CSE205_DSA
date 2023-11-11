#include <stdio.h>

int main() {
    int tableSize = 10;
    int numKeys, i;
    scanf("%d", &numKeys);
    int keys[numKeys];
    for (i = 0; i < numKeys; i++) {
        scanf("%d", &keys[i]);
    }

    // Initialize the hash table and initialize bestMark and bestIndex
    int hashTable[tableSize];
    int bestMark = -1;
    int bestIndex = -1;

    for (i = 0; i < tableSize; i++) {
        hashTable[i] = -1; // Initialize the hash table with -1 indicating empty slots
    }

    // Hash and probe using quadratic probing
    for (i = 0; i < numKeys; i++) {
        int mark = keys[i];
        int index = mark % tableSize;
        int probe = 1;

        while (hashTable[index] != -1) {
            // Collision, use quadratic probing
            index = (index + probe * probe) % tableSize;
            probe++;
        }

        // Store the mark in the hash table
        hashTable[index] = mark;

        // Update bestMark and bestIndex if necessary
        if (mark > bestMark) {
            bestMark = mark;
            bestIndex = index;
        }
    }

    printf("Best Mark: %d, Index: %d\n", bestMark, bestIndex);
    return 0;
}

