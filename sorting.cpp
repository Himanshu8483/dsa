/*
-------------------- Time Complexity --------------------
Time Complexity tells how fast an algorithm runs as input grows.
Common Time Complexities:
O(1) - Constant time (Same time always)
O(n) - Linear time (Time increases with input)
O(n^2) - Quadratic time (Time grows very fast, e.g., nested loops)
O(log n) - Logarithmic time (Grows slowly, e.g., Binary Search)
O(n log n) - Log-linear time (Used in efficient sorting like MergeSort)

-------------------- Big O, Theta, Omega --------------------
Big O (O) - Worst case (Max time taken)
Example: O(n^2) → May take quadratic time in worst case

Theta (Θ) - Average case (Expected time)
Example: Θ(n log n) → Usually runs in log-linear time

Omega (Ω) - Best case (Minimum time needed)
Example: Ω(n) → At best, runs in linear time

-------------------- Space Complexity --------------------
Space Complexity tells how much memory an algorithm uses.
O(1) - Constant space (Uses fixed memory)
O(n) - Linear space (Memory grows with input size)

-------------------- In-place and Out-of-place --------------------
In-place: Works without extra memory
Example: BubbleSort (Sorts within same array)

Out-of-place: Needs extra memory
Example: MergeSort (Uses extra space for merging)

-------------------- Stable vs Unstable --------------------
Stable Sort: Keeps order of equal elements
Example: MergeSort, BubbleSort (Order stays same)

Unstable Sort: Order of equal elements may change
Example: QuickSort (Order may change in some cases)

-------------------- Subtraction-based Approach --------------------
Problem reduces by removing a portion each time
Example: Binary Search (Cuts search space in half each step)

-------------------- Divide and Conquer --------------------
Breaks problem into smaller parts, solves separately, and combines.
Steps:
1. Divide → Split problem into smaller parts
2. Conquer → Solve each smaller part
3. Combine → Put solutions together
Example: MergeSort follows this approach

-------------------- Key Concepts Summary --------------------
1. Time Complexity - Measures how fast an algorithm runs
2. Big O - Worst-case time
3. Theta (Θ) - Average-case time
4. Omega (Ω) - Best-case time
5. Space Complexity - Measures memory usage
6. In-place - Works without extra memory
7. Out-of-place - Needs extra space (like MergeSort)
8. Stable Sorting - Keeps equal elements in order
9. Subtraction-based - Reduces problem step by step (Binary Search)
10. Divide and Conquer - Breaks, solves, and combines
*/

/*
Sorting Algorithms Summary Notes
================================

1️⃣ Bubble Sort 🫧
Compares adjacent elements and swaps them if they are in the wrong order.
The largest elements "bubble up" to the end of the list.
Best case: O(n) (when already sorted).
Worst case: O(n²) (when sorted in reverse).
Stable: ✅ (preserves order of duplicate elements).
In-Place: ✅ (doesn't use extra space).

Code:
*/
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

/*
2️⃣ Insertion Sort ✍️
Takes one element at a time and places it in the correct position in the sorted part of the array.
Works like sorting playing cards in your hand.
Best case: O(n) (when already sorted).
Worst case: O(n²) (when sorted in reverse).
Stable: ✅ (keeps order of duplicates).
In-Place: ✅ (modifies the array directly).


Code:
*/
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*
3️⃣ Selection Sort 🎯
Selects the smallest element and places it at the correct position by swapping.
Repeats this process for the entire array.
Best case & Worst case: O(n²) (always same steps).
Stable: ❌ (may change order of duplicates).
In-Place: ✅ (swaps elements directly).

Code:
*/
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

/*
4️⃣ Merge Sort 🧩
Divides the array into two halves, sorts them, and merges them back.
Uses recursion (function calling itself).
Best & Worst case: O(n log n) (efficient for large data).
Stable: ✅ (preserves order of duplicates means it maintains relative order of equal elements.).
In-Place: ❌ (needs extra space for merging).

Code:
*/
void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    for (int i = low, k = 0; i <= high; i++, k++) arr[i] = temp[k];
}
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

/*
5️⃣ Quick Sort ⚡
Picks a pivot, moves smaller elements to the left and larger ones to the right, then repeats.
Uses recursion like Merge Sort.
Best case: O(n log n) (when pivot divides well).
Worst case: O(n²) (if always picking bad pivots).
Stable: ❌ (does not guarantee order of duplicates).
In-Place: ✅ (works in the same array).

Code:
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    cout << "Sorted array using Bubble Sort: ";
    printArray(arr, n);
    
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr2, n);
    cout << "Sorted array using Insertion Sort: ";
    printArray(arr2, n);
    
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr3, n);
    cout << "Sorted array using Selection Sort: ";
    printArray(arr3, n);
    
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr4, 0, n - 1);
    cout << "Sorted array using Merge Sort: ";
    printArray(arr4, n);
    
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr5, 0, n - 1);
    cout << "Sorted array using Quick Sort: ";
    printArray(arr5, n);
    
    return 0;
}

/*
📌 Summary Table
---------------
| Algorithm      | Best Case  | Avg Case  | Worst Case | Space  | Approach          | Stable | In-Place | Type  |
|--------------|----------|---------|----------|-------|----------------|-------|---------|------|
| Bubble Sort  | O(n)     | O(n²)   | O(n²)    | O(1)  | Subtraction (Swapping)    | ✅    | ✅       | Element-Based |
| Insertion Sort | O(n)    | O(n²)   | O(n²)    | O(1)  | Subtraction (Shifting)   | ✅    | ✅       | Element-Based |
| Selection Sort | O(n²)   | O(n²)   | O(n²)    | O(1)  | Subtraction (Swapping)    | ❌    | ✅       | Element-Based |
| Merge Sort    | O(n log n) | O(n log n) | O(n log n) | O(n)  | Divide & Conquer | ✅    | ❌       | Structure-Based |
| Quick Sort    | O(n log n) | O(n log n) | O(n²)    | O(log n) | Divide & Conquer | ❌    | ✅       | Element-Based |
*/
/*
🔥 Which Sorting Algorithm is Best?
For small data: Insertion Sort (fastest for nearly sorted data).
For large data: Merge Sort or Quick Sort (efficient for big inputs).
For simplicity: Bubble Sort and Selection Sort are easy to learn.
*/
