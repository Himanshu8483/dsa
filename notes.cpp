// Data Structures and Algorithms with C++: Notes

/*
=========================
Data Types in C++
=========================

Data types define the type of value a variable can hold.

Primitive Data Types:
- int → Stores whole numbers (Example: int x = 10;)
- float → Stores decimal numbers (Example: float y = 3.14;)
- char → Stores single characters (Example: char ch = 'A';)
- double → Stores large decimal numbers (Example: double z = 9.87654;)
- bool → Stores true or false values (Example: bool isTrue = true;)

Non-Primitive Data Types:
- Array → A collection of elements of the same type.
  int arr[5] = {1, 2, 3, 4, 5};
- Structure (struct) → Groups different data types together.
  struct Student {
      int id;
      char name[20];
      float marks;
  };
- Class → A blueprint for creating objects that encapsulate data and functions.
  class Car {
      public:
          string brand;
          int speed;
  };

- Linear Data Structures → Data elements are arranged sequentially.
  Examples: Array, Queue, Stack, Linked List.
- Non-Linear Data Structures → Data elements are arranged in a hierarchical manner.
  Examples: Tree, Graph.

  Homogeneous Data Structures:
- Contain elements of the same type.
- Example: Arrays, Stacks, Queues, Linked Lists.
  int arr[5] = {1, 2, 3, 4, 5};

Heterogeneous Data Structures:
- Contain elements of different types.
- Example: Structures, Classes, Graphs.
  struct Student {
      int id;
      char name[20];
      float marks;
  };
============================
Types of Data Structures
============================

Data structures help in organizing and managing data efficiently.

Linear Data Structures (Stored in a sequence):
1. Array → Stores elements in contiguous memory locations.
   int arr[5] = {10, 20, 30, 40, 50};
2. Queue → Follows FIFO (First In, First Out) order.
   queue<int> q;
   q.push(1);  // Insert element
   q.pop();    // Remove element
3. Stack → Follows LIFO (Last In, First Out) order.
   stack<int> s;
   s.push(1);  // Insert element
   s.pop();    // Remove element
4. Linked List → A collection of nodes with pointers.
   struct Node {
       int data;
       Node* next;
   };

Non-Linear Data Structures (Hierarchical relationships):
1. Tree → A hierarchical structure where each node has child nodes.
   struct Node {
       int data;
       Node* left;
       Node* right;
   };
2. Graph → A set of nodes (vertices) connected by edges.
   - Can be represented using an adjacency matrix or adjacency list.

================================
Linear vs Non-Linear Structures
================================

|   Property            |   Linear Structures         | Non-Linear Structures  |
| --------------------- | -------------------------- | ---------------------  |
|   Memory Allocation  | Continuous (Array) or Dynamic (LL) | Hierarchical (Tree, Graph) |
|   Traversal         | Sequential (One by One)    | Hierarchical (Parent-Child) |
|   Examples          | Array, Queue, Stack, Linked List | Tree, Graph |

*/

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
    for (int i = 0; i < n - 1; i++) { // Outer loop runs (n-1) times
        bool swapped = false; // To check if swapping happened
        
        for (int j = 0; j < n - i - 1; j++) { // Inner loop for comparison
            if (arr[j] > arr[j + 1]) { // If current element is greater than next
                swap(arr[j], arr[j + 1]); // Swap elements
                swapped = true; // Mark swapped as true
            }
        }
        
        if (!swapped) break; // If no swaps, array is already sorted
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
    for (int i = 1; i < n; i++) { // Start from the second element
        int key = arr[i]; // Store the key element
        int j = i - 1;
        
        // Shift elements to the right instead of swapping
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the element
            j--;
        }
        
        arr[j + 1] = key; // Place the key in its correct position
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
    for (int i = 0; i < n - 1; i++) { // Traverse the array
        int minIndex = i; // Assume the first element is the smallest
        for (int j = i + 1; j < n; j++) { // Find the minimum element in remaining array
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
         // Swap only if a smaller element is found
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
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
// Function to merge two subarrays
void combine(int arr[], int low, int mid, int high) {
    int i = low;      // Starting index for left subarray
    int j = mid + 1;  // Starting index for right subarray
    int k = 0;        // Index for temporary array
    int temp[high - low + 1]; // Corrected size allocation
    
    // Merge the two subarrays
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) { // Ensures stability
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of right subarray, if any
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    // Copy the sorted elements back to the original array
    for (int x = 0; x < k; x++) {
        arr[low + x] = temp[x]; // Correct index mapping
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        
        // Recursively sort first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        
        // Merge the sorted halves
        combine(arr, low, mid, high);
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
// Function to partition the array (Lomuto's Partitioning)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Pointer for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(arr[i], arr[j]); // Swap elements
        }
    }
    swap(arr[i + 1], arr[high]); // Move pivot to correct position
    return i + 1; // Return partition index
}
// or ===============
/*
// Function to partition the array (Hoare's Partitioning)
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as pivot
    int i = low - 1, j = high + 1; // Correct initialization for Hoare’s scheme

    while (true) {
        // Move `i` to the right until an element >= pivot is found
        do {
            i++;
        } while (arr[i] < pivot);

        // Move `j` to the left until an element < pivot is found
        do {
            j--;
        } while (arr[j] > pivot);

        // If `i` and `j` cross, return partition index
        if (i >= j) return j;

        // Swap elements to maintain partitioning condition
        swap(arr[i], arr[j]);
    }
}
*/
// Hoare’s Partitioning: Uses two pointers moving toward each other. Fewer swaps (better performance). Best for large datasets.
// Lomuto’s Partitioning: Moves elements smaller than pivot to one side. More swaps (less efficient). Simpler to understand & implement.

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);  // Sort left partition
        quickSort(arr, pi + 1, high); // Sort right partition
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
