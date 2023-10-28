#include <iostream>
using namespace std;

struct Task {
    int priority;
};

void swap(Task& a, Task& b) {
    Task temp = a;
    a = b;
    b = temp;
}

// Function to insert a new task priority into the min heap
void insertTaskPriority(Task heap[], int& heapSize, Task newTask) {
    if (heapSize == 100) {
        cout << "Heap is full. Cannot insert more task priorities." << endl;
        return;
    }

    int i = heapSize;
    heap[heapSize] = newTask;
    heapSize++;

    while (i > 0 && heap[(i - 1) / 2].priority > heap[i].priority) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeapify(Task heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].priority < heap[smallest].priority)
        smallest = left;

    if (right < n && heap[right].priority < heap[smallest].priority)
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        MinHeapify(heap, n, smallest);
    }
}

void buildMinHeap(Task heap[], int heapSize) {
    for (int i = (heapSize - 2) / 2; i >= 0; i--)
        MinHeapify(heap, heapSize, i);
}

void printHeap(Task heap[], int heapSize) {
    buildMinHeap(heap, heapSize);
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].priority << " ";
    }
    cout << endl;
}

int main() {
    Task minHeap[100];
    int heapSize = 0;

    while (true) {
        Task newTask;
        if (!(cin >> newTask.priority)) {
            break;
        }
        insertTaskPriority(minHeap, heapSize, newTask);
    }

    printHeap(minHeap, heapSize);

    return 0;
}

