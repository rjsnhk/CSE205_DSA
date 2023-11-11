#include <stdio.h>

#define TABLE_SIZE 100

// Function to perform Mid-Square Hashing
int midSquareHash(int key) {
    int squared = key * key;
    int middleDigit = (squared / 100) % 100;
    return middleDigit % TABLE_SIZE;
}

int main() {
    int n, keys[10];
    int table[TABLE_SIZE];

    // Initialize the hash table to -1, indicating empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }

    // Input the number of keys
    scanf("%d", &n);

    // Input the keys
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    // Insert the keys into the hash table
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = midSquareHash(key);

        // Linear probing to handle collisions
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = key;
    }

    // Output the non-empty slots in the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != -1) {
            printf("Index %d: Key %d\n", i, table[i]);
        }
    }

    return 0;
}

