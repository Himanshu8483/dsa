**Data Structures and Algorithms with C++: Notes**

### 1. **Data Types**

#### **Primitive Data Types**
1. **int**: Stores integers (e.g., `int x = 10;`).
2. **float**: Stores decimals (e.g., `float y = 3.14;`).
3. **char**: Stores a single character (e.g., `char ch = 'A';`).
4. **double**: Stores large decimals (e.g., `double z = 9.87654;`).
5. **bool**: Stores `true` or `false` (e.g., `bool isTrue = true;`).

#### **Non-Primitive Data Types**
1. **Array**: Collection of same-type elements (e.g., `int arr[5] = {1, 2, 3, 4, 5};`).
2. **Structure**: Groups different types (e.g., `struct Student { int id; char name[20]; float marks; };`).
3. **Class**: Encapsulates data/functions (e.g., `class Car { public: string brand; int speed; };`).

---

### 2. **Types of Data Structures**

#### **Linear Structures**
- **Array**: Continuous memory (e.g., `int arr[5] = {10, 20, 30, 40, 50};`).
- **Queue**: FIFO (e.g., `queue<int> q; q.push(1); q.pop();`).
- **Stack**: LIFO (e.g., `stack<int> s; s.push(1); s.pop();`).
- **Linked List**: Nodes with data and pointers (e.g., `struct Node { int data; Node* next; };`).

#### **Non-Linear Structures**
- **Tree**: Hierarchical nodes (e.g., `struct Node { int data; Node* left; Node* right; };`).
- **Graph**: Nodes/edges (e.g., adjacency matrix/list).

---

### 3. **Collections**

#### **Homogeneous**: Same type (e.g., `int arr[5] = {1, 2, 3, 4, 5};`).
#### **Heterogeneous**: Mixed types (e.g., `struct Data { int id; char name[20]; };`).

---

### 4. **Linear vs Non-Linear**

| **Property**          | **Linear**              | **Non-Linear**        |
| --------------------- | ----------------------- | --------------------- |
| **Memory**            | Continuous              | Hierarchical          |
| **Traversal**         | Sequential              | Hierarchical          |
| **Examples**          | Array, Queue, Stack     | Tree, Graph           |

---

### 5. **Sorting Techniques**

#### Key Terms:
1. **Time Complexity**: Measures the time an algorithm takes based on input size (e.g., O(n), O(n^2)).
2. **Space Complexity**: Measures additional memory needed by the algorithm.
3. **Stable**: Maintains relative order of equal elements.
4. **In-place**: Does not use extra space apart from input array.
5. **Structure-Based**: Sorting depends on data structure.
6. **Element-Based**: Sorting depends on values of elements.

#### **Bubble Sort**
- **Approach**: Compares adjacent elements and swaps if out of order.
- **Time Complexity**: O(n^2).
- **Space Complexity**: O(1).
- **Stable** and **in-place**.
- Example:
  ```cpp
  for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
              swap(arr[j], arr[j + 1]);
          }
      }
  }
  ```

#### **Insertion Sort**
- **Approach**: Inserts elements one by one into the correct position.
- **Time Complexity**: O(n^2).
- **Space Complexity**: O(1).
- **Stable** and **in-place**.
- Example:
  ```cpp
  for (int i = 1; i < n; i++) {
      int key = arr[i];
      int j = i - 1;
      while (j >= 0 && arr[j] > key) {
          arr[j + 1] = arr[j];
          j--;
      }
      arr[j + 1] = key;
  }
  ```

#### **Selection Sort**
- **Approach**: Finds the smallest element and swaps it into place.
- **Time Complexity**: O(n^2).
- **Space Complexity**: O(1).
- **Not stable**, **in-place**.
- Example:
  ```cpp
  for (int i = 0; i < n - 1; i++) {
      int min_idx = i;
      for (int j = i + 1; j < n; j++) {
          if (arr[j] < arr[min_idx]) {
              min_idx = j;
          }
      }
      swap(arr[i], arr[min_idx]);
  }
  ```

#### **Quick Sort**
- **Approach**: Divides and conquers by selecting a pivot.
- **Time Complexity**: O(n log n) (average), O(n^2) (worst).
- **Space Complexity**: O(log n).
- **Not stable**, **in-place**.
- Example:
  ```cpp
  int partition(int arr[], int low, int high) {
      int pivot = arr[high];
      int i = (low - 1);
      for (int j = low; j < high; j++) {
          if (arr[j] <= pivot) {
              i++;
              swap(arr[i], arr[j]);
          }
      }
      swap(arr[i + 1], arr[high]);
      return (i + 1);
  }

  void quickSort(int arr[], int low, int high) {
      if (low < high) {
          int pi = partition(arr, low, high);
          quickSort(arr, low, pi - 1);
          quickSort(arr, pi + 1, high);
      }
  }
  ```

#### **Merge Sort**
- **Approach**: Divides the array into halves and merges sorted halves.
- **Time Complexity**: O(n log n).
- **Space Complexity**: O(n).
- **Stable** but **not in-place**.
- Example:
  ```cpp
  void merge(int arr[], int l, int m, int r) {
      int n1 = m - l + 1;
      int n2 = r - m;
      int L[n1], R[n2];
      for (int i = 0; i < n1; i++)
          L[i] = arr[l + i];
      for (int j = 0; j < n2; j++)
          R[j] = arr[m + 1 + j];
      int i = 0, j = 0, k = l;
      while (i < n1 && j < n2) {
          if (L[i] <= R[j]) {
              arr[k++] = L[i++];
          } else {
              arr[k++] = R[j++];
          }
      }
      while (i < n1)
          arr[k++] = L[i++];
      while (j < n2)
          arr[k++] = R[j++];
  }

  void mergeSort(int arr[], int l, int r) {
      if (l < r) {
          int m = l + (r - l) / 2;
          mergeSort(arr, l, m);
          mergeSort(arr, m + 1, r);
          merge(arr, l, m, r);
      }
  }
  ```

---

### 6. **Complexity and Asymptotic Notations**

- **Big O**: Worst-case.
- **Theta (\u03B8)**: Average-case.
- **Omega (\u03A9)**: Best-case.
- **Time Complexity**: Time taken as a function of input size.
- **Space Complexity**: Memory used as a function of input size.

---

### 7. **Conclusion**
- Sorting techniques vary in complexity, stability, and space.
- Asymptotic notations help measure algorithm performance.
- Choose algorithms based on input size and requirements.

