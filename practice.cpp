#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Outer loop runs (n-1) times
        bool swapped = false; // To check if swapping happened
        
        for (int j = 0; j < n - i - 1; j++) { // Inner loop for comparison
            if (arr[j] > arr[j + 1]) { // If current element is greater than next
                swap(arr[j], arr[j + 1]); // Swap elements
                swapped = true; // Mark swapped as true
            }
        }
        
        if (!swapped) break; 
    }
}