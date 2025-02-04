/*
Sorting Algorithms Summary Notes
================================

1️⃣ Bubble Sort
--------------
- Approach: Subtraction (Swapping)
- Best: O(n) | Average: O(n²) | Worst: O(n²)
- Space Complexity: O(1)
- Stable: ✅ Yes
- In-Place: ✅ Yes
- Type: Element-Based

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
2️⃣ Insertion Sort
-----------------
- Approach: Subtraction (Shifting)
- Best: O(n) | Average: O(n²) | Worst: O(n²)
- Space Complexity: O(1)
- Stable: ✅ Yes
- In-Place: ✅ Yes
- Type: Element-Based

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
3️⃣ Selection Sort
-----------------
- Approach: Subtraction (Swapping)
- Best: O(n²) | Average: O(n²) | Worst: O(n²)
- Space Complexity: O(1)
- Stable: ❌ No
- In-Place: ✅ Yes
- Type: Element-Based

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
4️⃣ Merge Sort
-------------
- Approach: Divide & Conquer
- Best: O(n log n) | Average: O(n log n) | Worst: O(n log n)
- Space Complexity: O(n)
- Stable: ✅ Yes
- In-Place: ❌ No
- Type: Structure-Based

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
5️⃣ Quick Sort
-------------
- Approach: Divide & Conquer
- Best: O(n log n) | Average: O(n log n) | Worst: O(n²)
- Space Complexity: O(log n) (avg case)
- Stable: ❌ No
- In-Place: ✅ Yes
- Type: Element-Based

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

/*
📌 Summary Table
---------------
| Algorithm      | Best Case  | Avg Case  | Worst Case | Space  | Approach          | Stable | In-Place | Type  |
|--------------|----------|---------|----------|-------|----------------|-------|---------|------|
| Bubble Sort  | O(n)     | O(n²)   | O(n²)    | O(1)  | Subtraction    | ✅    | ✅       | Element-Based |
| Insertion Sort | O(n)    | O(n²)   | O(n²)    | O(1)  | Subtraction    | ✅    | ✅       | Element-Based |
| Selection Sort | O(n²)   | O(n²)   | O(n²)    | O(1)  | Subtraction    | ❌    | ✅       | Element-Based |
| Merge Sort    | O(n log n) | O(n log n) | O(n log n) | O(n)  | Divide & Conquer | ✅    | ❌       | Structure-Based |
| Quick Sort    | O(n log n) | O(n log n) | O(n²)    | O(log n) | Divide & Conquer | ❌    | ✅       | Element-Based |
*/
