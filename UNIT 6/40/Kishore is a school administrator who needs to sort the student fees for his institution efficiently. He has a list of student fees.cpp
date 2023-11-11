#include <stdio.h>

#define tableSize 10

// Function to calculate the mid-square hash value
int hashFunction(int key, int size) {
    int square = key * key;
    int digits = 0;
    int temp = square;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    int mid = digits / 2;
    int midSquare = square;
    for (int i = 0; i < mid; i++) {
        midSquare /= 10;
    }

    int hash = midSquare % size;
    return hash;
}

int main() {
    int n;
    // printf("Enter the number of student fees: ");
    scanf("%d", &n);

    int studentFees[n];
    // printf("Enter the student fees: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &studentFees[i]);
    }

    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1; // Initialize the hash table with -1 to indicate empty slots
    }

    for (int i = 0; i < n; i++) {
        int fee = studentFees[i];
        int index = hashFunction(fee, tableSize);

        while (hashTable[index] != -1) {
            index = (index + 1) % tableSize; // Handle collisions by linear probing
        }

        hashTable[index] = fee;
    }

    int lowestFee = -1;
    int lowestIndex = -1;

    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            printf("Index: %d, Value: %d\n", i, hashTable[i]);
            if (lowestFee == -1 || hashTable[i] < lowestFee) {
                lowestFee = hashTable[i];
                lowestIndex = i;
            }
        }
    }

    printf("Lowest Fee: %d Index %d\n", lowestFee, lowestIndex);

    return 0;
}

