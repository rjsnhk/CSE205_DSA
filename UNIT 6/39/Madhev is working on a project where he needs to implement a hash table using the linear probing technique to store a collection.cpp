#include <iostream>
using namespace std;

#define SIZE 100

int calHash(int key, int size) {
    return key % size;
}

int main() {
    int size, numKeys;
    cin >> size;
    cin >> numKeys;

    int keys[numKeys];
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < numKeys; ++i) {
        cin >> keys[i];
    }

    int minIndices[numKeys];

    for (int i = 0; i < numKeys; ++i) {
        int index = calHash(keys[i], size);

        while (hashTable[index] != -1) {
            index = (index + 1) % size; // Linear probing to find the next available slot
        }

        hashTable[index] = keys[i];
        minIndices[i] = index;
    }

    for (int i = 0; i < numKeys; ++i) {
        for (int j = i + 1; j < numKeys; ++j) {
            if (minIndices[i] > minIndices[j]) {
                int temp = minIndices[i];
                minIndices[i] = minIndices[j];
                minIndices[j] = temp;
                temp = keys[i];
                keys[i] = keys[j];
                keys[j] = temp;
            }
        }

        cout << "index: " << minIndices[i] << ", value: " << keys[i] << endl;
    }

    return 0;
}

