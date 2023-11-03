#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void heapifyDown(int *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void deleteTallestFlower(int *heap, int &n) {
    if (n <= 0) {
        return; // Empty heap, nothing to delete
    }

    // Swap the tallest flower (root) with the last flower
    swap(heap[0], heap[n - 1]);
    n--;

    // Re-heapify to maintain the max-heap property
    heapifyDown(heap, n, 0);
}

int main() {
    int *heap;
    int n;
    cin >> n;
    heap = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, n, i);
    }

    deleteTallestFlower(heap, n);

    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    delete[] heap;
    return 0;
}

