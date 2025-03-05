# C++ Templates, Namespaces, Arrays, Vectors & Pairs

## **1. Function Template**

A function template allows writing a generic function that works with any data type.

```cpp
#include <iostream>
using namespace std;

// Function Template
template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    cout << sum(3, 5); // Output: 8
}
```

### **Explanation:**

- `template <typename T>`: Declares a template for a generic type `T`.
- The `sum()` function works with any data type, like `int`, `float`, etc.

---

## **2. Class Template**

A class template allows creating a generic class that works with different data types.

```cpp
#include <iostream>
using namespace std;

// Class Template
template<typename T>
class Example {
    T a;
public:
    Example(T x) { a = x; }
    T show() { return a + 1; }
};

int main() {
    Example<int> obj(10);
    cout << obj.show(); // Output: 11
}
```

### **Explanation:**

- `template<typename T>`: Declares a template class.
- The constructor assigns `x` to `a`.
- `show()` function returns `a + 1`.

---

## **3. Class Template Without Constructor**

```cpp
#include <iostream>
using namespace std;

// Class Template without Constructor
template<typename T1, typename T2>
class Example2 {
public:
    void sum(T1 a, T2 b) {
        cout << a + b;
    }
};

int main() {
    Example2<int, float> obj;
    obj.sum(5, 4.5); // Output: 9.5
}
```

### **Explanation:**

- Template with two different types (`T1`, `T2`).
- `sum()` function adds two numbers.

---

## **4. Namespaces in C++**

Namespaces help organize code and prevent naming conflicts.

```cpp
#include <iostream>
using namespace std;

// Custom Namespace
namespace custom {
    int a = 50;
    void show() {
        cout << "Sum = " << a + 10;
    }
}

using namespace custom;
int main() {
    cout << a << "\n"; // Output: 50
    show();            // Output: Sum = 60
}
```

### **Explanation:**

- Declares a custom namespace `custom`.
- `using namespace custom;` allows using its variables/functions without prefix.

### **Multiple Namespaces**

```cpp
namespace A {
    void display() { cout << "Namespace A"; }
    namespace B {
        void display() { cout << "Namespace B"; }
    }
}

int main() {
    A::display(); // Output: Namespace A
    A::B::display(); // Output: Namespace B
}
```

---

## **5. Array Template (STL Array)**

C++ STL provides an array container with built-in functions.

```cpp
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 6> arr = {34, 5, 12, 87, 5, 3};
      sort(arr.begin(), arr.end());

    cout << "Min = " << arr.front() << "\n";
    cout << "Max = " << arr.back() << "\n";
    cout << "Size = " << arr.size() << "\n";

    for (int i : arr) {
        cout << i << "\t";
    }
}
```

### **Key Functions:**

- `sort()`: Sorts the array.
- `front()`, `back()`: Get first and last elements.
- `size()`: Returns size of array.
- `at(index)`: Access element at a specific index.

---

## **6. Vector in C++ (STL Vector)**

Vectors are dynamic arrays that can resize automatically.

### **Declaring a Vector & Iterating**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v{2, 3, 4, 5, 6};
    for (auto p : v) {
        cout << p << "\t";
    }
}
```

### **Inserting Elements Dynamically**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int n, a;
    cout << "Enter size: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> a;
        vec.push_back(a);
    }
}
```

### **Removing Last Element (**\`\`**\*\*\*\*)**

```cpp
vec.pop_back();
```

### **Inserting at a Specific Position**

```cpp
vector<int>::iterator it = vec.begin();
vec.insert(it + 1, 100);
```

---

## **7. Pairs in C++**

Pairs store two values together, which can be of different types.

```cpp
#include <iostream>
using namespace std;

int main() {
    pair<int, string> p = make_pair(101, "Jatin");
    cout << p.first << "\n" << p.second;
}
```

### **Vector of Pairs**

```cpp
vector<pair<int, string>> v;
v.push_back({101, "John"});
v.push_back({102, "Alice"});
```

---

## **8. Nested Vectors (2D Vectors)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v1;
    int row, col, val;
    cout << "Enter Rows: ";
    cin >> row;
    cout << "Enter Columns: ";
    cin >> col;

    for (int i = 0; i < row; i++) {
        vector<int> v2;
        for (int j = 0; j < col; j++) {
            cout << "Enter value: ";
            cin >> val;
            v2.push_back(val);
        }
        v1.push_back(v2);
    }

    cout << "Stored Values: \n";
    for (auto &row : v1) {
        for (auto &num : row) {
            cout << num << "\t";
        }
        cout << "\n";
    // or
      for(int i=0;i<v1.size();i++){
        for(int j=0; j<v1[i].size();j++){
            cout<<v1[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
```

### **Explanation:**

- Stores 2D data dynamically.
- Uses nested loops to accept & display data.

---

### **Conclusion**

These concepts are essential in C++ for efficient coding:

- **Templates**: Generic programming.
- **Namespaces**: Avoid naming conflicts.
- **STL Arrays & Vectors**: Efficient storage & manipulation.
- **Pairs & Nested Vectors**: Useful for structured data.

Understanding these will help in competitive programming and software development.

