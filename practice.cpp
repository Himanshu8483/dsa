// Quick Sort is a sorting algorithm that works by:
// Choosing a pivot element (usually the first or last element).
// Placing the pivot in its correct position (smaller elements on the left, larger on the right).
// Recursively sorting the left and right parts.

#include <iostream>
using namespace std;

// Function to partition the array
int part(int arr[], int low, int high) {
    int pivot = arr[low]; // Choosing first element as pivot
    int i = low + 1;
    int j = high;

    do {
        while (arr[i] < pivot) { // Move i to the right until finding a larger element
            i++;
        }
        while (arr[j] > pivot) { // Move j to the left until finding a smaller element
            j--;
        }
        if (i < j) { // Swap elements to keep smaller elements on left and larger on right
            swap(arr[i], arr[j]);
        }
    } while (i < j);

    // Swap pivot with the correct position
    swap(arr[low], arr[j]);

    return j; // ✅ We use return j; to get the correct pivot position so that Quick Sort can divide and sort the array properly.
}

// Function to perform Quick Sort
void qksrt(int arr[], int low, int high) {
    if (low < high) {
        int pv = part(arr, low, high); // Get pivot index
        qksrt(arr, low, pv - 1);  // Sort left part
        qksrt(arr, pv + 1, high); // Sort right part
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}                     
// Main function
int main() {
    int arr[] = {5, 9, 5, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, size);

    qksrt(arr, 0, size - 1);

    cout << "After Quick Sort:\n"; 
    printArray(arr, size);

    return 0;
}
