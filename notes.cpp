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
