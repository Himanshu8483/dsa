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

### 5. **Code Examples**

#### **Array**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
```

#### **Queue**
```cpp
queue<int> q;
q.push(10);
q.push(20);
while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
```

#### **Stack**
```cpp
stack<int> s;
s.push(100);
s.push(200);
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```

#### **Linked List**
```cpp
struct Node {
    int data;
    Node* next;
};
Node* head = new Node();
Node* second = new Node();
head->data = 1;
head->next = second;
second->data = 2;
second->next = nullptr;
Node* temp = head;
while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
}
```

---

### 6. **Conclusion**
- Efficient data organization depends on choosing the right structure.
- Linear structures are simpler, while non-linear ones suit complex relationships.

