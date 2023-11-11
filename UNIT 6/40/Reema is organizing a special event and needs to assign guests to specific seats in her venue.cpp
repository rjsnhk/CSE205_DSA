#include <stdio.h>

#define tableSize 10

int hashTable[tableSize];

void assignSeat(int ticketID) {
    int seat = ticketID % tableSize;
    while (hashTable[seat] != 0) {
        seat = (seat + 1) % tableSize;
    }
    hashTable[seat] = ticketID;
}

int main() {
    int n, ticketID;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ticketID);
        assignSeat(ticketID);
    }

    int lowestFee = -1;
    int lowestIndex = -1;

    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != 0) {
            printf("Seat Number %d: Ticket ID %d\n", i, hashTable[i]);
            if (lowestFee == -1 || hashTable[i] < lowestFee) {
                lowestFee = hashTable[i];
                lowestIndex = i;
            }
        }
    }

    // printf("Lowest Fee: %d Index %d\n", lowestFee, lowestIndex);

    return 0;
}

