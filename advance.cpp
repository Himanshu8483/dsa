C++ Templates, Namespaces, Arrays, Vectors & Pairs
1. Function Template
A function template allows writing a generic function that works with any data type.
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
Explanation:
•	template <typename T>: Declares a template for a generic type T.
•	The sum() function works with any data type, like int, float, etc.
________________________________________
2. Class Template
A class template allows creating a generic class that works with different data types.
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
Explanation:
•	template<typename T>: Declares a template class.
•	The constructor assigns x to a.
•	show() function returns a + 1.
________________________________________
3. Class Template Without Constructor
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
Explanation:
•	Template with two different types (T1, T2).
•	sum() function adds two numbers.
________________________________________
4. Namespaces in C++
Namespaces help organize code and prevent naming conflicts.
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
Explanation:
•	Declares a custom namespace custom.
•	using namespace custom; allows using its variables/functions without prefix.
Multiple Namespaces
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
________________________________________
5. Standard Template Library (STL) in C++
STL (Standard Template Library) provides a collection of pre-defined templates for efficient data structures and algorithms. It is divided into:
1.	Containers: Store and manage data (array, vector, list, map, etc.).
2.	Algorithms: Predefined functions (sort(), binary_search(), etc.).
3.	Iterators: Used to traverse elements in containers.
4.	Function Objects: Special functions acting like function pointers.
Example:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 1, 8, 3, 7};
    sort(v.begin(), v.end());  // Sorting using STL

    for (int num : v) {
        cout << num << " ";  // Output: 1 3 5 7 8
    }
}

How to Identify STL Components?
•	Algorithms (<algorithm>): sort(), reverse(), binary_search().
•	Arrays (<array>): array<int, 5>.
•	Vectors (<vector>): vector<int>.
•	Pairs (<utility>): pair<int, string>.
Note: The <utility> header is not always explicitly needed because many of its features, like pair, are also available through other headers like <iostream>. However, it's still the standard header for utility functions like std::pair, std::move, std::swap, and tuple utilities.

________________________________________

6. Array in C++ (STL Array)
C++ STL provides an array container with built-in functions.
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 6> arr = {34, 5, 12, 87, 5, 3};
    sort(arr.begin(), arr.end());       // array sorted

 for (int i=0; i<arr.size();i++) {
  cout << arr.at(i) << "\t";
}
 
 cout<<"\n first value of array = "<<arr.front();	
 cout<<"\n last value of array = "<<arr.back();
 cout<<"\n second (with pointer)last value = "<<*(arr.end()-2);   //   it gives second highest value (not perfect in  duplicate)
 cout<<"\n fourth (with pointer) value from start = "<<*(arr.begin()+3);   // output= 12:  (not perfect in  duplicate)
 cout<<"\n third (with arr )last value = "<<arr[arr.size()-3];   // another method (not perfect in  duplicate)
}
Key Functions:
•	sort(): Sorts the array.
•	front(), back(): Get first and last elements.
•	size(): Returns size of array.
•	at(index): Access element at a specific index.
Example of In Case of Duplicate find Second Largest Number: 
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
int main() {
    array<int, 6> numbers{5, 5, 2, 3, 4, 1};

    // Sort the array in ascending order
    sort(numbers.begin(), numbers.end());

    int largest = numbers.back(); // Get the largest element

    // Find the second largest element
    for (int i = numbers.size() - 2; i >= 0; i--) {
        if (numbers[i] < largest) {
            cout << "Second largest element: " << numbers[i];
            break;
        }
    }
    return 0;
}
________________________________________
7. Vector in C++ (STL Vector)
Vectors are dynamic arrays that can resize automatically.
Declaring a Vector & Iterating
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Vector with predefined values
    vector<int> numbers{2, 3, 4, 5, 6};
    cout << "Vector 1 (numbers): ";
    for (auto num : numbers) {
        cout << num << "\t";
    }
    cout << "\n";

    // Vector of strings
    vector<string> days{"Sun", "Mon", "Tuesday"};
    cout << "Vector 2 (days): ";
    for (auto day : days) {
        cout << day << "\t";
    }
    cout << "\n";

    // Vector with default values (initialized with size 5, default = 0)
    vector<int> defaultValues(5);
    cout << "Vector 3 (default values): ";
    for (auto val : defaultValues) {
        cout << val << "\t";
    }
    cout << "\n";

    // Vector initialized with 5 elements, all set to 10
    vector<int> customValues(5, 10);
    customValues[3] = 1000; // Modify one element

    cout << "Vector 4 (custom values): ";
    for (auto val : customValues) {
        cout << val << "\t";
    }
    cout << "\n";

    return 0;
}

Expected Output:
Vector 1 (numbers): 2    3    4    5    6    
Vector 2 (days): Sun    Mon    Tuesday    
Vector 3 (default values): 0    0    0    0    0    
Vector 4 (custom values): 10    10    10    1000    10    

Inserting Elements Dynamically

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
    vector<int> vec;
    int n, a;

    // Insert dynamic data into vector
    cout << "Enter The Size of Vector = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter digit = ";
        cin >> a;
        vec.push_back(a);
    }

    // Display vector data
    cout << "\nData of vector:\n";
    for (auto p : vec) {
        cout << p << "\t";
    }
    cout << "\n";

    // Delete last element using pop_back()
    vec.pop_back();
    cout << "\nAfter deletion:\n";
    for (auto p : vec) {
        cout << p << "\t";
    }
    cout << "\n";

Inserting at a Specific Position
    // Insert using iterator at second position
    vector<int>::iterator it = vec.begin();
    vec.insert(it + 1, 100);
    cout << "\nAfter inserting 100 at second position:\n";
    for (auto j : vec) {
        cout << j << "\t";
    }
    cout << "\n";

    // Insert using iterator before the last element
    vector<int>::iterator it_end = vec.end();
    vec.insert(it_end - 1, 100);
    cout << "\nAfter inserting 100 before last element:\n";
    for (auto j : vec) {
        cout << j << "\t";
    }
    cout << "\n";
    return 0;
}
    
Short Summary for Revision:
Insert dynamic data → vec.push_back(a);
Display vector → for(auto p : vec) cout << p << "\t";
Delete last element → vec.pop_back();
Insert at second position → vec.insert(vec.begin() + 1, 100);
Insert before last element → vec.insert(vec.end() - 1, 100);
________________________________________
8. Pairs in C++
Pairs store two values together, which can be of different types.
•  A pair in C++ is a container that holds two values together.
•  The first value is accessed using .first and the second value is accessed using .second.

#include <iostream>
using namespace std;

int main() {
    pair<int, string> p = make_pair(101, "Himanshu");
    cout << p.first << "\n" << p.second;
}
Vector of Pairs
vector<pair<int, string>> v;
v.push_back({101, "John"});
v.push_back({102, "Alice"});

Example:
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, string>> records;
    int roll, n;
    string name;

    // Input number of records
    cout << "Enter Number of Records = ";
    cin >> n;

    // Input roll numbers and names
    for (int i = 1; i <= n; i++) {
        cout << "Enter roll number = ";
        cin >> roll;
        cout << "Enter Name = ";
        cin >> name;
        records.push_back({roll, name});  // Insert roll number and name as a pair
    }

    // Display stored records
    cout << "\nResults are:\n";
    for (auto record : records) {
        cout << record.first << " : " << record.second << "\n";
    }

    return 0;
}
________________________________________
9. Nested Vectors (2D Vectors)
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> matrix;
    int row, col, val;

    cout << "Enter Rows: ";
    cin >> row;
    cout << "Enter Columns: ";
    cin >> col;

    for (int i = 0; i < row; i++) {
        vector<int> temp;
        for (int j = 0; j < col; j++) {
            cout << "Enter value: ";
            cin >> val;
            temp.push_back(val);
        }
        matrix.push_back(temp);
    }

    cout << "Stored 2D Vector:\n";
    for (auto row : matrix) {
        for (auto num : row) {
            cout << num << "\t";
        }
        cout << "\n";

        // or (by Sir)
      for(int i=0;i<matrix.size();i++){
        for(int j=0; j<matrix[i].size();j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";

    }
}

Explanation:
•	Stores 2D data dynamically.
•	Uses nested loops to accept & display data.
________________________________________
Conclusion
These concepts are essential in C++ for efficient coding:
•	Templates: Generic programming.
•	Namespaces: Avoid naming conflicts.
•	STL Arrays & Vectors: Efficient storage & manipulation.
•	Pairs & Nested Vectors: Useful for structured data.

Understanding these STL concepts will help in competitive programming and software development. STL provides efficient tools for handling data and solving problems faster.

 
Questions Solve:
Sum of Two Vectors (Element-wise)
cpp
CopyEdit
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1{3, 1, 2, 5};
    vector<int> v2{7, 2, 3, 4};

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] + v2[i] << "\t";
    }
}
📌 Output: 10 3 5 9
________________________________________
Sum of Two Vectors (Store in Third Vector)
cpp
CopyEdit
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1{3, 1, 2, 5};
    vector<int> v2{7, 2, 3, 4};
    vector<int> v3;

    for (int i = 0; i < v1.size(); i++) {
        v3.push_back(v1[i] + v2[i]);
    }

    for (auto num : v3) {
        cout << num << "\t";
    }
}
📌 Output: 10 3 5 9
________________________________________
Sum of Two Vectors (Using Single Variable)
cpp
CopyEdit
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int sum = 0;
    vector<int> v1{3, 1, 2, 5};
    vector<int> v2{7, 2, 3, 4};

    for (int i = 0; i < v1.size(); i++) {
        sum += v1[i] + v2[i];
    }
    cout << sum;
}
📌 Output: 27
________________________________________
Sum of Two Vectors (Using Two Variables)
cpp
CopyEdit
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int sum1 = 0, sum2 = 0;
    vector<int> v1{3, 1, 2, 5};
    vector<int> v2{7, 2, 3, 4};

    for (int i = 0; i < v1.size(); i++) {
        sum1 += v1[i];
        sum2 += v2[i];
    }

    cout << sum1 + sum2;
}
📌 Output: 27
________________________________________
Find the Bigger Vector (Sum Comparison)
cpp
CopyEdit
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int sum1 = 0, sum2 = 0;
    vector<int> v1{3, 1, 2, 5};
    vector<int> v2{7, 2, 3, 4};

    for (int i = 0; i < v1.size(); i++) {
        sum1 += v1[i];
        sum2 += v2[i];
    }

    if (sum1 > sum2)
        cout << "Vector 1 is Bigger = " << sum1;
    else
        cout << "Vector 2 is Bigger = " << sum2;
}
📌 Output: Vector 2 is Bigger = 16
________________________________________
Add Two Vectors of Different Sizes
cpp
CopyEdit
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1{3, 1, 2, 5};   // 3125
    vector<int> v2{7, 2, 3};      // 723
    int x = 0, y = 0;

    for (int num : v1) x = x * 10 + num;
    for (int num : v2) y = y * 10 + num;

    cout << "Result = " << x + y;
}
📌 Output: Result = 3848
________________________________________
Remove Duplicates and Print in Ascending Order
cpp
CopyEdit
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{3, 2, 1, 5, 4, 1, 9, 6, 5};
    sort(v.begin(), v.end());

    int x = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[x - 1] != v[i]) {
            v[x] = v[i];
            x++;
        }
    }

    for (int i = 0; i < x; i++) {
        cout << v[i] << "\t";
    }
}
📌 Output: 1 2 3 4 5 6 9
________________________________________
Find the Second Minimum Value
cpp
CopyEdit
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{3, 2, 1, 5, 4, 1, 9, 6, 5};
    sort(v.begin(), v.end());

    int min_val = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > min_val) {
            cout << "Second Minimum: " << v[i];
            break;
        }
    }
}
📌 Output: Second Minimum: 2________________________________________
🔹 Lambda Functions in C++
•	A lambda function is an anonymous function (has no name).
•	It is represented using [].
•	Syntax:
cpp
CopyEdit
[] (parameter_list) -> return_type { function_body }
Example: [](int a, int b) { return a > b; }(4, 20);
________________________________________
✅ Example 1: Sorting a Vector
cpp
CopyEdit
#include<iostream>
#include<vector>
#include<algorithm> // For sort(), all_of(), any_of(), none_of()

using namespace std;

int main() {
    vector<int> v{2, 1, 5, 4, 6};

    // Sorting in ascending order (default)
    sort(v.begin(), v.end());
    
    // Printing sorted vector
    for (auto p : v) {
        cout << p << " ";
    }
    cout << "\n";

    // Lambda function example
    cout << [](int a, int b) { return a > b; }(4, 20) << "\n"; // Output: 0 (false)

    // Sorting using built-in comparators
    sort(v.begin(), v.end(), less<int>());   // Ascending order
    sort(v.begin(), v.end(), greater<int>()); // Descending order

    // Sorting using a Lambda function
    sort(v.begin(), v.end(), [] (int a, int b) { return a > b; });   // Descending order

    // Printing sorted vector
    for (auto p : v) {
        cout << p << "\t";
    }
}
________________________________________
✅ Example 2: Lambda Function with Different Use Cases
cpp
CopyEdit
#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int main() {
    // Lambda with a single parameter
    cout << [](int a) { return a + 2; }(4) << endl; // Output: 6

    // Lambda stored in a variable
    auto p = [] (int a, int b) { return a + b; }; 
    cout << p(45, 6) << endl; // Output: 51

    vector<int> v = {23, 100, 59};
    vector<int> v2 = {2, 1, 5};

    // Using STL algorithms with Lambda functions
    cout << all_of(v.begin(), v.end(), [](int x) { return x > 0; }) << endl;  // Checks if all elements are > 0
    cout << any_of(v.begin(), v.end(), [](int x) { return x > 50; }) << endl; // Checks if any element > 50
    cout << none_of(v.begin(), v.end(), [](int x) { return x < 0; }) << endl; // Checks if no element < 0
}
________________________________________
🎯 Why Use Lambda Functions?
✔ Compact and Readable – Reduces the need for writing separate functions.
✔ Useful for Sorting and Comparisons – Directly define custom sorting logic.
✔ Works Well with STL Algorithms – sort(), all_of(), any_of(), etc.
✔ No Need for Separate Function Definitions – Makes code cleaner.




🔹 Understanding Stack in C++
•	A Stack is a LIFO (Last In, First Out) data structure.
•	Elements are added (pushed) to the top and removed (popped) from the top.
•	 A stack is a temporary data structure used for searching, not for storing data permanently.
•	•  It cannot be directly iterated using a loop because it doesn't support indexing.
•	Elements are accessed only through the top of the stack.
•	Operations:
o	push(x) → Adds an element x to the top.
o	pop() → Removes the top element.
o	top() → Returns the top element.
o	empty() → Returns true if the stack is empty.
________________________________________
✅ Stack Implementation in C++
#include <iostream>
#include <stack>  // Include stack library
using namespace std;
int main() {
    stack<int> st;  // Declare a stack of integers

    // 🔹 Pushing elements onto the stack
    st.push(10);
    st.push(4);
    st.push(5);
    st.push(11);
    st.push(3);

    // 🔹 Checking if the stack is empty
    cout << "Is stack empty? " << st.empty() << endl;  // Output: 0 (false)

    // 🔹 Pop elements and print them (LIFO order)
    cout << "\nStack elements (LIFO order): ";
    while (!st.empty()) {
        cout << st.top() << "\t";  // Print the top element
        st.pop();  // Remove the top element
    }

    // 🔹 Checking if the stack is empty after popping all elements
    cout << "\n\nIs stack empty now? " << st.empty() << endl;  // Output: 1 (true)

    return 0;
}________________________________________
📌 Expected Output
Is stack empty? 0
Stack elements (LIFO order): 3		11	5	4	10	
Is stack empty now? 1
________________________________________
🎯 Quick Revision Notes
Operation	Description	Example
push(x)	Inserts x at the top of the stack	st.push(10);
pop()	Removes the top element	st.pop();
top()	Returns the top element	cout << st.top();
empty()	Checks if the stack is empty	st.empty() → Returns true/false
________________________________________
🔥 Key Takeaways
✔ Stack follows LIFO (Last In, First Out)
✔ Stack does not support direct iteration using a loop
✔ Used for temporary data storage (stored in RAM)
✔ Used in recursion, backtracking, and undo operations
🚀 Master stacks, and you'll be ready to solve many coding problems efficiently! 💪

Example use of Stack (Basic Used in Compiler to Fetch and give error)

Balanced Parentheses Using Stack in C++
Concept Used:
Stack Data Structure (LIFO - Last In, First Out)
Conditions to check balance:
Every opening bracket {, [, ( must have a corresponding closing bracket }, ], ).
The brackets must be nested correctly.

Explanation:
#include <stack> → Used to implement stack.
using namespace std; → Avoids writing std:: every time.
 
// By Google 
#include <iostream>       // For input/output operations
#include <stack>          // For using stack data structure
using namespace std;

bool isValid(string s) {
    stack<char> st;  // Stack to store opening brackets

    for (char ch : s) {  // Loop through each character in string
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);  // Push opening brackets onto stack
        } else {  
            if (st.empty()) return false;  // No matching opening bracket
            
            // Directly check if the top element is matching
            if ((ch == ')' && st.top() != '(') || 
                (ch == '}' && st.top() != '{') || 
                (ch == ']' && st.top() != '[')) {
                return false;
            }
            st.pop();  // Remove matched bracket
        }
    }
    return st.empty();  // If stack is empty, the string is valid
}


int main() {
    string s;
    cout << "Enter Combination of Brackets: ";
    cin >> s;

    if (isValid(s)) {
        cout << "Valid Bracket Combination" << endl;
    } else {
        cout << "Invalid Bracket Combination" << endl;
    }

    return 0;
}
    
// or by Vikash Sir 
#include <iostream>
using namespace std;
#include<stack>

bool valid(string s) {
    stack<char> st;
    bool r = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            st.push(s[i]); // Push opening brackets to stack
        }
        else if (s[i] == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop(); // Correct match, remove from stack
            } else {
                r = false;
                break; // Mismatch found, stop checking
            }
        }
        else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                r = false;
                break;
            }
        }
        else if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                r = false;
                break;
            }
        }
    }

    // Move return statement outside the loop
    return st.empty() && r;
    // or 
    if(!st.empty()){
        return false;
    }
    else{
        return r;
    }
}
int main() {
    string s = "{([])}"; // Input string
    if (valid(s)) {
        cout << "valid";
    } else {
        cout << "invalid";
    }
}
    
Understanding #include <bits/stdc++.h> in C++
What is #include <bits/stdc++.h>?
•	It is a single header file that includes all standard C++ libraries (like iostream, vector, map, algorithm, etc.).
•	This is commonly used in competitive programming to save time by avoiding multiple #include statements.
________________________________________
Why Does It Waste Memory?
1.	Unnecessary Header Files:
o	When you use #include <bits/stdc++.h>, it includes many libraries even if your program does not need them.
o	Example: If your program only uses iostream, you don’t need vector, map, or cmath, but they still get included.
2.	Slower Compilation Time:
o	The compiler has to process a large number of unnecessary libraries, increasing compilation time.
3.	More Memory Consumption:
o	Extra libraries mean more memory usage at compile time and runtime.
o	If you use only iostream, including hundreds of unnecessary functions is a waste.
________________________________________
Example:
❌ Bad Practice (Wastes Memory)
cpp
CopyEdit
#include <bits/stdc++.h>   // Includes everything (unnecessary)
using namespace std;

int main() {
    cout << "Hello, World!" << endl;  // Only needs iostream
    return 0;
}
🔴 Problem:
Even though this program only uses iostream, it also includes unnecessary headers like vector, map, and set, wasting memory.
________________________________________
✅ Good Practice (Optimized)
cpp
CopyEdit
#include <iostream>  // Only includes necessary header
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
✅ Solution:
•	Only include the libraries you actually use to save memory and reduce compilation time.
________________________________________
When to Use #include <bits/stdc++.h>?
✔️ Use it in Competitive Programming (fast coding, not worried about memory).
❌ Avoid it in Real-World Projects (wastes memory and slows down compilation).

