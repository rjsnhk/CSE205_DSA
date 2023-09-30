#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Merge two subarrays into a single sorted subarray
void merge(vector<double>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    vector<double> leftArray(n1);
    vector<double> rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = arr[middle + 1 + i];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<double> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Sort the numbers using merge sort
    mergeSort(numbers, 0, n - 1);

    // Display the sorted numbers
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << numbers[i] << " ";
    }

    return 0;
}

