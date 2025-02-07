// Data Structures and Algorithms with C++: Notes

/*
1. **Data Types**

Primitive Data Types:
- int: Stores integers (e.g., int x = 10;).
- float: Stores decimals (e.g., float y = 3.14;).
- char: Stores a single character (e.g., char ch = 'A';).
- double: Stores large decimals (e.g., double z = 9.87654;).
- bool: Stores true or false (e.g., bool isTrue = true;).

Non-Primitive Data Types:
- Array: Collection of same-type elements (e.g., int arr[5] = {1, 2, 3, 4, 5};).
- Structure: Groups different types (e.g., struct Student { int id; char name[20]; float marks; };).
- Class: Encapsulates data/functions (e.g., class Car { public: string brand; int speed; };).

2. **Types of Data Structures**

Linear Structures:
- Array: Continuous memory (e.g., int arr[5] = {10, 20, 30, 40, 50};).
- Queue: FIFO (e.g., queue<int> q; q.push(1); q.pop();).
- Stack: LIFO (e.g., stack<int> s; s.push(1); s.pop();).
- Linked List: Nodes with data and pointers (e.g., struct Node { int data; Node* next; };).

Non-Linear Structures:
- Tree: Hierarchical nodes (e.g., struct Node { int data; Node* left; Node* right; };).
- Graph: Nodes/edges (e.g., adjacency matrix/list).


Linear vs Non-Linear**

| **Property**          | **Linear**              | **Non-Linear**        |
| --------------------- | ----------------------- | --------------------- |
| **Memory**            | Continuous              | Hierarchical          |
| **Traversal**         | Sequential              | Hierarchical          |
| **Examples**          | Array, Queue, Stack     | Tree, Graph           |

3. **Sorting Techniques**

Key Terms:
- Time Complexity: Measures the time an algorithm takes based on input size (e.g., O(n), O(n^2)).
- Space Complexity: Measures additional memory needed by the algorithm.
- Stable: Maintains relative order of equal(duplicate) elements.
- In-place: Does not use extra space apart from input array.

**Sorting Algorithms:**

**Bubble Sort:**
- Approach: Repeatedly compares adjacent elements and swaps if needed.
- Time Complexity: O(n^2).
- Space Complexity: O(1).
- Stable and In-place.
- Example Code:
  ```cpp
  void bubbleSort(int arr[], int s) {
      int temp;
      int count = 0;
      bool swapped;

      for (int i = 0; i < s; i++) {
          swapped = true;
          for (int j = 0; j < s - i - 1; j++) {
              count++;
              if (arr[j] > arr[j + 1]) {
                  temp = arr[j + 1];
                  arr[j + 1] = arr[j];
                  arr[j] = temp;
                  swapped = false;
              }
          }
          if (swapped == true) {
              break;
          }
      }
      for (int i = 0; i < s; i++) {
          cout << arr[i] << "\t";
      }
      cout << "\ncounter hit = " << count << endl;
  }

  int main() {
      int arr[] = {1, 2, 3, 4, 5};
      int s = sizeof(arr) / sizeof(arr[0]);

      cout << "Original Array: \n";
      for (int i = 0; i < s; i++) {
          cout << arr[i] << "\t";
      }

      cout << "\nAfter applying Bubble Sort:\n";
      bubbleSort(arr, s);
      return 0;
  }
  ```

**Insertion Sort:**
- Approach: Inserts elements one by one into the correct position.
- Time Complexity: O(n^2).
- Space Complexity: O(1).
- Stable and In-place.
- Example Code:
  ```cpp
  void insertionSort(int arr[], int s) {
      for (int i = 1; i < s; i++) {
          int mn = i;
          while (mn > 0 && arr[mn] < arr[mn - 1]) {
              int temp = arr[mn - 1];
              arr[mn - 1] = arr[mn];
              arr[mn] = temp;
              mn--;
          }
      }
      for (int i = 0; i < s; i++) {
          cout << arr[i] << "\t";
      }
      cout << endl;
  }

  int main() {
      int arr[] = {10, 5, 50, 2, 20};
      int s = sizeof(arr) / sizeof(arr[0]);

      cout << "Original Array: \n";
      for (int i = 0; i < s; i++) {
          cout << arr[i] << "\t";
      }

      cout << "\nAfter applying Insertion Sort:\n";
      insertionSort(arr, s);
      return 0;
  }
  ```

**Selection Sort:**
- Approach: Finds the smallest element and swaps it into place.
- Time Complexity: O(n^2).
- Space Complexity: O(1).
- Not Stable but In-place.
- Example Code:
  ```cpp
  void selectionSort(int arr[], int n) {
      for (int i = 0; i < n - 1; i++) {
          int minIndex = i; // Assume the first element of the unsorted part is the smallest

          // Find the actual minimum in the unsorted part
          for (int j = i + 1; j < n; j++) {
              if (arr[j] < arr[minIndex]) {
                  minIndex = j;
              }
          }

          // Swap the found minimum element with the first element of the unsorted part
          int temp = arr[i];
          arr[i] = arr[minIndex];
          arr[minIndex] = temp;
      }
  }

  void printArray(int arr[], int n) {
      for (int i = 0; i < n; i++) {
          cout << arr[i] << " ";
      }
      cout << endl;
  }

  int main() {
      int arr[] = {64, 25, 12, 22, 11};
      int n = sizeof(arr) / sizeof(arr[0]);

      cout << "Original Array: ";
      printArray(arr, n);

      selectionSort(arr, n);

      cout << "Sorted Array: ";
      printArray(arr, n);

      return 0;
  }
  ```

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
#include <iostream>
using namespace std;
void combine(int arr[], int low, int mid, int high){
    int i=low;
    int j= mid+1;
    int k=low;
    int bk[high+1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            bk[k]= arr[i];
            i++;
            k++;
        }
        else{
            bk[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        bk[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        bk[k]=arr[j];
        j++;
        k++;
    }
    for(int i=low;i<k;i++){
        arr[i]=bk[i];
    }
}
void mergesrt(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesrt(arr, low, mid);
        mergesrt(arr, mid+1, high);
        combine(arr,low, mid, high);
    }
}
int main(){
    int arr[]={9,2,3,1,6,5};
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<s;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\nAfter merge sort\n";
    mergesrt(arr,0,s-1);
    for(int i=0;i<s;i++){
        cout<<arr[i]<<"\t";
    }
}

   
// 🔥 Key Takeaways:
// Merge Sort has O(n log n) time complexity – good for large datasets.
// It’s a stable sorting algorithm, meaning it maintains relative order of equal elements.
// It uses extra space (O(n)) for merging.
