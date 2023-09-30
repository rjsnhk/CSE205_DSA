#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Merge two subarrays into a single sorted subarray
void merge(vector<int>& arr, vector<pair<int, int>>& freq, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    vector<pair<int, int>> leftArray(n1);
    vector<pair<int, int>> rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++) {
        leftArray[i] = freq[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = freq[middle + 1 + i];
    }

    // Merge the temporary arrays back into freq[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i].second < rightArray[j].second || (leftArray[i].second == rightArray[j].second && leftArray[i].first < rightArray[j].first)) {
            freq[k] = leftArray[i];
            i++;
        } else {
            freq[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        freq[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        freq[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<int>& arr, vector<pair<int, int>>& freq, int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, freq, left, middle);
        mergeSort(arr, freq, middle + 1, right);

        // Merge the sorted halves
        merge(arr, freq, left, middle, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    unordered_map<int, int> frequency_map;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        frequency_map[arr[i]]++;
    }

    vector<pair<int, int>> freq;
    for (const auto& kv : frequency_map) {
        freq.push_back({kv.first, kv.second});
    }

    // Sort the frequencies using merge sort
    mergeSort(arr, freq, 0, freq.size() - 1);

    // Display the sorted integers based on frequencies and values
    for (const auto& p : freq) {
        for (int i = 0; i < p.second; i++) {
            cout << p.first << " ";
        }
    }

    return 0;
}

