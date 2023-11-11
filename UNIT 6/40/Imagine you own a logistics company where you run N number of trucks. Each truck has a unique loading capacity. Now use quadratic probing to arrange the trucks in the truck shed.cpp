#include <stdio.h>

#define tableSize 10

// Function to calculate the hash index using the modulo operation
int hashFunction(int key) {
    return key % tableSize;
}

int main() {
    int n;
    // printf("Enter the number of trucks: ");
    scanf("%d", &n);

    int truckCapacities[n];
    // printf("Enter the loading capacities of each truck: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &truckCapacities[i]);
    }

    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1; // Initialize the hash table with -1 to indicate empty slots
    }

    for (int i = 0; i < n; i++) {
        int capacity = truckCapacities[i];
        int index = hashFunction(capacity);

        int probe = 1;
        while (hashTable[index] != -1) {
            index = (index + probe * probe) % tableSize; // Quadratic probing
            probe++;
        }

        hashTable[index] = i;
    }

    int maxCapacity = -1;
    int maxCapacityIndex = -1;

    for (int i = 0; i < n; i++) {
        int capacity = truckCapacities[i];
        int index = hashFunction(capacity);

        int probe = 1;
        while (hashTable[index] != i) {
            index = (index + probe * probe) % tableSize; // Quadratic probing
            probe++;
        }

        if (capacity > maxCapacity) {
            maxCapacity = capacity;
            maxCapacityIndex = index;
        }
    }

    printf("The lorry that has high load capacity is in index %d.\n", maxCapacityIndex);

    return 0;
}

