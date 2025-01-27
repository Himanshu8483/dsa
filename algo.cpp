

#include <iostream>
#include <vector>

using namespace std;

// -------------------- Time Complexity --------------------
// Time Complexity refers to how the execution time of an algorithm grows as the input size increases.
// Common Time Complexities:
// O(1) - Constant time
// O(n) - Linear time
// O(n^2) - Quadratic time
// O(log n) - Logarithmic time
// O(n log n) - Log-linear time (Common in efficient sorting algorithms)

// -------------------- Big O, Theta, Omega --------------------
// Big O (O): Describes the upper bound (worst-case scenario).
// Example: O(n^2) - In the worst case, the algorithm runs in quadratic time.

// Theta (Θ): Describes the exact bound (average-case scenario).
// Example: Θ(n log n) - The algorithm runs in log-linear time on average.

// Omega (Ω): Describes the lower bound (best-case scenario).
// Example: Ω(n) - The algorithm will take at least linear time in the best case.

// -------------------- Space Complexity --------------------
// Space Complexity refers to the amount of memory an algorithm uses as the input size grows.
// Example: O(1) - Constant space (doesn't require extra memory).
// Example: O(n) - Linear space (requires memory proportional to the input size).

// -------------------- In-place and Out-of-place --------------------
// In-place algorithms don't require extra memory (except for a small constant).
// Example: BubbleSort (In-place)
// Out-of-place algorithms require additional memory for extra data storage.
// Example: MergeSort (Not in-place) - Uses extra memory for merging subarrays.

// -------------------- Stable vs Unstable --------------------
// Stable Sort: If two equal elements appear in the input, their relative order remains the same after sorting.
// Example: MergeSort (Stable) and BubbleSort (Stable).
// Unstable Sort: The relative order of equal elements may change.
// Example: QuickSort (Unstable in some cases).

// -------------------- Subtraction-based Approach --------------------
// Subtraction-based approach reduces the problem size by eliminating a portion of the problem.
// Example: Binary Search (Halves the search space each time).

// -------------------- Divide and Conquer --------------------
// Divide and Conquer breaks down a problem into smaller sub-problems, solves them independently, and combines results.
// Steps: 
// 1. Divide: Break the problem into smaller sub-problems.
// 2. Conquer: Solve each sub-problem recursively.
// 3. Combine: Combine the solutions of sub-problems.


// -------------------- Example 1: Binary Search (Subtraction-based) --------------------
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x)
            return mid;  // Found the element
        
        if (arr[mid] > x)  // Search in left half
            return binarySearch(arr, left, mid - 1, x);
        
        return binarySearch(arr, mid + 1, right, x);  // Search in right half
    }
    return -1;  // Element is not present in array
}

// -------------------- Example 2: MergeSort (Divide and Conquer) --------------------
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);  // Temporary arrays to hold data
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);    // Recursively sort the first half
        mergeSort(arr, mid + 1, right); // Recursively sort the second half
        
        merge(arr, left, mid, right);   // Merge the sorted halves
    }
}

// -------------------- Main Function --------------------
int main() {
    // Example 1: Binary Search
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
        cout << "Element is present at index " << result << endl;
    else
        cout << "Element is not present in array" << endl;

    // Example 2: MergeSort
    vector<int> arr2 = {12, 11, 13, 5, 6, 7};
    cout << "Given array: ";
    for (int i : arr2) cout << i << " ";
    cout << endl;

    mergeSort(arr2, 0, arr2.size() - 1);  // Calling MergeSort

    cout << "Sorted array: ";
    for (int i : arr2) cout << i << " ";
    cout << endl;

    return 0;
}

// -------------------- Key Concepts Summary --------------------
// 1. **Time Complexity**: Describes how an algorithm's run-time grows with input size.
// 2. **Big O**: Upper bound (worst-case).
// 3. **Theta**: Exact bound (avg-case).
// 4. **Omega**: Lower bound (best-case).
// 5. **Space Complexity**: Describes how memory usage grows with input size.
// 6. **In-place**: Algorithm does not require extra space.
// 7. **Out-of-place**: Requires additional memory (e.g., MergeSort).
// 8. **Stable Sorting**: Maintains relative order of equal elements.
// 9. **Subtraction-based**: Halves the problem size (e.g., Binary Search).
// 10. **Divide and Conquer**: Divides the problem into sub-problems, solves them, and combines the results.

