#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Function to check if an array represents an inorder traversal of a BST
bool isValidInorder(int arr[], int n) {
    // Initialize the minimum value to negative infinity
    int minVal = INT_MIN;
    
    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If the current element is less than the minimum value, it's not a valid BST
        if (arr[i] < minVal) {
            return false;
        }
        
        // Update the minimum value to the current element
        minVal = arr[i];
    }
    
    // If the loop completes without any violations, it's a valid BST
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isValidInorder(arr, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

