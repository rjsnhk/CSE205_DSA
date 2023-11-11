#include <stdio.h>

int divisionMethod(int key, int tableSize) {
    return key % tableSize;
}

int main() {
    int tableSize = 10;
    int numKeys;
    scanf("%d", &numKeys);
    int keys[numKeys];
    for (int i = 0; i < numKeys; i++) {
        scanf("%d", &keys[i]);
    }
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int index = divisionMethod(key, tableSize);

        while (hashTable[index] != -1) {
            // Linear probing: Move to the next slot
            index = (index + 1) % tableSize;
        }

        // Store the customer ID in the hash table
        hashTable[index] = key;
    }

    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            printf("Table number %d: Customer ID %d\n", i, hashTable[i]);
        }
    }
    return 0;
}

