/*
Map (key, value): Associative container
- Types: Ordered Map, Unordered Map, Multimap
- Keys are always unique in Map

1. Ordered Map:
   - Keys are sorted using a self-balancing binary search tree (Red-Black Tree)
   - Time Complexity: O(log n) for insertion, deletion, and search

2. Unordered Map:
   - Keys are stored in an unordered manner using Hashing
   - Time Complexity: O(1) on average for insertion, deletion, and search

3. Multimap:
   - Allows duplicate keys

Set (key only):
- Similar to Map but only stores keys
- Can be Ordered, Unordered, or Multiset

Notes:
- Maps are discontinuous containers, so prefer i++ over i = i + 1
- String operations: O(s.size() * log n)
- Integer operations: O(log n)
*/
#include <iostream>
#include <map>
using namespace std;

int main() {

    // Example 1: Using map with int and string
    map<int, string> mp = {{100, "Himanshu"}, {102, "Jatin"}, {101, "Vijay"}};
    cout << "Using range-based for loop with map<int, string>:\n";
    for (const auto& p : mp) {
        cout << p.first << ": " << p.second << "\n";
    }

    cout << "\nUsing iterator with map<string, int>:\n";
    map<string, int> student = {{"Vijay", 10}, {"Jatin", 11}, {"Himanshu", 12}};
    for (auto it = student.begin(); it != student.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }

    // Example 2: Demonstrating map with integer keys and string values
    cout << "\nUsing map with integer keys and string values:\n";
    map<int, string> mapp;

    // Inserting values using insert()
    mapp.insert({101, "Jatin"});
    mapp.insert({103, "Vijay"});
    mapp.insert({102, "Himanshu"});

    // Attempting to insert a duplicate key (No effect)
    mapp.insert({102, "Yash"}); // Won't replace existing value

    // Using [] operator for insertion and update
    mapp[101] = "Yash"; // Update value for key 101
    mapp[104] = "New Entry"; // Insert new key-value pair

    // Accessing key that doesn't exist initializes it with empty string
    cout << "Accessing non-existent key 105: " << mapp[105] << endl;

    map<int, int> maps;
    // Demonstrating pre and post increment/decrement
    maps[105]--;            // output 105: -1
    // maps[105]++;

    cout << "\nFinal map contents:\n";
    for (const auto& p : maps) {
        cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}

Understanding C++ Map with Examples
1. What is a Map?
A map in C++ is a container that stores key-value pairs.
Keys are unique.
Values are stored using a key for quick access.
Implemented using a Red-Black Tree (Self-balancing Binary Search Tree).
Code Explanation
1. Declaration and Initialization
cpp
Copy code
map<int, string> mp;
map<int, string> → Stores an integer as a key (e.g., Roll Number) and a string as a value (e.g., Name).
mp → Map variable.
2. Inserting Data
cpp
Copy code
mp.insert({roll, name});
insert() → Inserts key-value pairs into the map.
{roll, name} → Roll number as key, name as value.
3. Searching Data
cpp
Copy code
auto t = mp.find(102);
find() → Searches for a key.
auto → Automatically determines the iterator type.
cpp
Copy code
if (t != mp.end()) {
    cout << t->first << ":" << t->second;
}
else {
    cout << "Not found";
}
mp.end() → Represents a pointer to past the last element.
If key is found → Prints t->first (key) and t->second (value).
If key is not found → Prints "Not found".
4. Deleting Data
cpp
Copy code
mp.erase(103);
erase() → Removes key-value pair using the key.
If key does not exist, nothing happens.
5. Displaying Data
cpp
Copy code
for (auto p : mp) {
    cout << p.first << ":" << p.second << "\n";
}
auto p → Extracts each key-value pair.
p.first → Key (Roll number).
p.second → Value (Name).
Key Notes to Remember
Dot (.) and Arrow (->) Operators

Dot (.) → Used with objects like map when accessing directly.
Arrow (->) → Used with pointers or iterators like auto t = mp.find().
Map Behavior

If the key exists, find() returns an iterator pointing to the element.
If the key does not exist, find() returns mp.end().

// Code: 
// Program to demonstrate map in C++ with insertion, search, deletion, and display
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mp; // Declare a map with int keys and string values
    int roll, n;
    string name;

    // Taking input for map entries
    cout << "Enter number of records: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
        mp.insert({roll, name}); // Insert into map using key-value pair
    }

    // Search for a specific roll number using find()
    int searchRoll = 102;
    auto it = mp.find(searchRoll);
  // or 
  //       auto it=mp.find(102);
    if (it != mp.end()) {
        cout << "\nFound: " << it->first << ": " << it->second;
    } else {
        cout << "\nRoll number " << searchRoll << " not found.";
    }

    // Delete record with roll number 103
    mp.erase(103);
    cout << "\nRecord with roll number 103 deleted (if existed).";

    // Display all records
    cout << "\n\nAll Records:\n";
    for (auto &p : mp) {
        cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}

This code covers:

Insertion using insert()
Search using find()
Deletion using erase()
Display using a for loop

Note: 
calling erase() on a non-existent key will not give an error.
Explanation-> You can safely call erase() without checking if the key exists.

Roman to Integer Conversion (Simple Approach)
Problem: Convert a Roman numeral (e.g., "IX") to its integer form.

Roman Numerals and Values
Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Approach
Use a map<char, int> to store Roman symbols and their values.
Traverse the string from left to right.
If the current symbol is smaller than the next symbol, subtract it.
Example: IV = 5 - 1 = 4
Otherwise, add the current symbol's value.
Simple Code for Roman to Integer Conversion
cpp
Copy code
#include <iostream>
#include <map>
using namespace std;

int romanToInt(string s) {
    map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                              {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }
    return result;
}

int main() {
    string romanNumber;
    cout << "Enter Roman Numeral: ";
    cin >> romanNumber;
    cout << "Integer Value: " << romanToInt(romanNumber);
    return 0;
}
Explanation
"IX" → I is smaller than X, so subtract: 10 - 1 = 9
"LVIII" → 50 + 5 + 3 = 58
"MCMXCIV" → 1000 + 900 + 90 + 4 = 1994

push_front(x)   O(1)
push_back(x)    O(1)
pop_front() O(1)
pop_back()  O(1)
insert(pos, x)  O(1) (if iterator is given)
erase(pos)  O(1)
remove(x)   O(n)
sort()  O(n log n)
merge(l2)   O(n + m)
reverse()   O(n)



Unordered Map and Multimap in C++
Unordered Map
•	Definition: Similar to map, but the elements are stored in an unordered manner using hashing.
•	Header File: #include <unordered_map>
•	Key Points: 
o	Time Complexity: O(1) for insertion, deletion, and search due to hashing.
o	No duplicate keys allowed.
o	Does not support complex data types like pair because of the lack of a hashing function.
•	Example:
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

int main() {
    unordered_map<int, string> up;
    up.insert({103, "Jatin"});
    up.insert({101, "Vijay"});
    up.insert({102, "Himanshu"});

    // Display the elements (unordered)
    cout << "Unordered Map Data:" << endl;
    for (auto p : up) {
        cout << p.first << ", " << p.second << "\n";
    }

    // Perform list operations
    list<int> lst = {103, 101, 102};
    lst.push_front(100);
    lst.push_back(104);
    cout << "After push_front and push_back:" << endl;
    for (auto i : lst) cout << i << " ";
    cout << endl;

    lst.pop_front();
    lst.pop_back();
    cout << "After pop_front and pop_back:" << endl;
    for (auto i : lst) cout << i << " ";
    cout << endl;

    auto it = lst.begin();
    advance(it, 1);
    lst.insert(it, 105);
    cout << "After insert at position 1:" << endl;
    for (auto i : lst) cout << i << " ";
    cout << endl;

    lst.erase(it);
    cout << "After erase at position 1:" << endl;
    for (auto i : lst) cout << i << " ";
    cout << endl;

    lst.remove(102);
    cout << "After remove value 102:" << endl;
    for (auto i : lst) cout << i << " ";
    cout << endl;

    lst.sort();
    cout << "After sort:" << endl;
    for (auto i : lst) cout << i << " ";
    cout << endl;

    lst.reverse();
    cout << "After reverse:" << endl;
    for (auto i : lst) cout << i << " ";
    cout << endl;
}________________________________________
Map vs Unordered Map
Feature	                Map	                   Unordered Map
Header File	        #include <map>	        #include <unordered_map>
Implementation	Implemented using Red-Black Tree	Implemented using Hash Table
Speed   	Slower compared to unordered_map	Faster due to hashing
Time Complexity	    for insertion, deletion, search	    for insertion, deletion, search on average, in worst case
Ordering	    Stores elements in sorted order by key	    Stores elements in unordered form
________________________________________

Multimap
•	Definition: Allows duplicate keys, unlike map or unordered_map.
•	Header File: #include <map>
•	Key Points: 
o	Time Complexity: O(log n) for insertion, deletion, and search due to the use of balanced trees.
o	Supports multiple values for the same key.
•	Example:
#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> mp;
    mp.insert({103, "Jatin"});
    mp.insert({101, "Vijay"});
    mp.insert({102, "Himanshu"});
    mp.insert({102, "Himanshu"});

    // Display all elements
    cout << "Initial Data:" << endl;
    for (auto p : mp) {
        cout << p.first << ", " << p.second << "\n";
    }

    // Delete first found using iterator
    auto t = mp.find(102);
    if (t != mp.end()) {
        mp.erase(t);
    }
    cout << "After Deleting First Matched Entry:" << endl;
    for (auto p : mp) {
        cout << p.first << ", " << p.second << "\n";
    }

    // Delete all entries with key 102
    mp.erase(102);
    cout << "After Deleting All Entries with Key 102:" << endl;
    for (auto p : mp) {
        cout << p.first << ", " << p.second << "\n";
    }
}
________________________________________
Two Sum Problem
Problem: Find indices of two numbers in the array such that they add up to the target sum.
•	Example: 
•	Input: a = [1, 0, 5, 2, 4]
•	Target Sum: 6
•	Output: Indices: (2, 4)
Approach Using Unordered Map
•	Store elements in an unordered_map with the value as key and index as value.
•	For each element, calculate the complement (target - element).
•	Check if the complement exists in the map.
Code:
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap; // Store value and index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in map
        if (umap.find(complement) != umap.end()) {
            return {umap[complement], i};
        }
        umap[nums[i]] = i;
    }
    return {}; // Return empty if no solution
}

int main() {
    vector<int> a = {1, 0, 5, 2, 4};
    int target = 6;

    vector<int> result = twoSum(a, target);
    if (!result.empty()) {
        cout << "Indices: (" << result[0] << ", " << result[1] << ")\n";
    } else {
        cout << "No valid pair found\n";
    }
}
Explanation:
1.	unordered_map provides O(1)O(1) time complexity for searching and inserting.
2.	Complement of each element is checked.
3.	If complement is found, return both indices.
4.	Efficient for large datasets.
________________________________________
These notes provide a clear understanding of unordered_map, multimap, and how to solve the two-sum problem using an efficient hashing-based approach. 



# C++ Sets and Multisets

### **1. Set**
- **Definition:** A set is an ordered, unique collection of elements.
- **Data Structure Used:** Red-Black Tree (Balanced Binary Search Tree)
- **Properties:**
  - Stores unique values
  - Maintains ascending order
  - Insertion, deletion, and search - **O(log n)**
- **Use Case:** Ideal for storing sorted data without duplicates.

#### **Example:**
```cpp
#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s{10, 20, 1, 2, 6};
    for (auto p : s) cout << p << "\t";

    cout << endl;
    s.insert(35);
    for (auto p : s) cout << p << "\t";

    s.erase(20);
    cout << "\n";

    auto t = s.find(2);
    if (t != s.end()) cout << "Found = " << *t;
    else cout << "Not found";
}
```

---

### **2. Unordered Set**
- **Definition:** A set with no specific order.
- **Data Structure Used:** Hash Table
- **Properties:**
  - Stores unique values
  - Provides faster insertion, deletion, and search - **O(1)** on average
  - Not sorted
- **Use Case:** Best for quick look-ups without order requirements.

#### **Example:**
```cpp
#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s{10, 20, 1, 2, 6};
    for (auto p : s) cout << p << "\t";

    cout << endl;
    s.insert(35);
    for (auto p : s) cout << p << "\t";

    s.erase(20);
    cout << "\n";

    auto t = s.find(2);
    if (t != s.end()) cout << "Found = " << *t;
    else cout << "Not found";
}
```

---

### **3. Multiset**
- **Definition:** A multiset allows duplicate values and maintains order.
- **Data Structure Used:** Red-Black Tree
- **Properties:**
  - Stores duplicate values
  - Maintains ascending order
  - Insertion, deletion, and search - **O(log n)**
- **Use Case:** Best for frequency counting or scenarios where duplicates are allowed.

#### **Example:**
```cpp
#include<iostream>
#include<set>
using namespace std;

int main(){
    multiset<int> s{10, 10, 20, 1, 2, 6};
    for (auto p : s) cout << p << "\t";

    cout << endl;
    s.insert(35);
    for (auto p : s) cout << p << "\t";

    s.erase(20);
    cout << "\n";

    auto t = s.find(2);
    if (t != s.end()) cout << "Found = " << *t;
    else cout << "Not found";

    cout << "\nAfter delete\n";
    auto p = s.find(10);
    if (p != s.end()) s.erase(p); // Deletes only one occurrence

    for (auto p : s) cout << p << "\t";
}
```

---

## **Pangram Check in C++**
- **Definition:** A Pangram is a sentence that contains every letter of the alphabet at least once.
- **Example:** "The quick brown fox jumps over the lazy dog"

### **Approach:**
- Use a set to store unique lowercase letters.
- If the size of the set becomes **26**, it is a Pangram.

#### **Example Code:**
#include <iostream>
#include <map>
using namespace std;

// Function to check if a string is a pangram using map (Method 1)
bool isPangramUsingMap1(const string &s) {
    map<char, bool> alpha; // Map to track presence of each alphabet

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Convert to lowercase for uniformity
        if (isalpha(ch)) {
            alpha[tolower(ch)] = true; // Mark alphabet as seen
        }
    }

    // Check if all 26 letters are present
    return (alpha.size() == 26);
}


// Function to check if a string is a pangram using map (Method 2)
bool isPangramUsingMap2(const string &s) {
    map<char, bool> alpha;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A'); // Convert to lowercase without using tolower
        }
        if (ch >= 'a' && ch <= 'z') {
            alpha[ch] = true;
        }
    }
    return (alpha.size() == 26);
}

#include <set>

// Function to check if a string is a pangram using set
bool isPangramUsingSet(const string &s) {
    set<char> uniqueChars; // Using set to store unique characters

    for (int i = 0; i < s.length(); i++) {
        char ch = tolower(s[i]); // Convert to lowercase

        // Check if the character is an alphabet
        if (ch >= 'a' && ch <= 'z') {
            uniqueChars.insert(ch);
        }
    }

    return uniqueChars.size() == 26;
}

int main() {
    string s = "The quick brown fox jumps over the lazy dog";

    // Using Map method 1
    if (isPangramUsingMap1(s)) {
        cout << "It is a Pangram String using Map Method 1." << endl;
    } else {
        cout << "It is not a Pangram String using Map Method 1." << endl;
    }

    // Using Map method 2
    if (isPangramUsingMap2(s)) {
        cout << "It is a Pangram String using Map Method 2." << endl;
    } else {
        cout << "It is not a Pangram String using Map Method 2." << endl;
    }

    // Using Set method
    if (isPangramUsingSet(s)) {
        cout << "It is a Pangram String using Set." << endl;
    } else {
        cout << "It is not a Pangram String using Set." << endl;
    }
}
Output:
It is a Pangram String using Map Method 1.
It is a Pangram String using Map Method 2.
It is a Pangram String using Set.

---
✅ Why Use const? (not used by Vikash Sir)
Prevents Modification:
const ensures that the function will not accidentally modify the original string.
Improves Code Clarity:
It indicates that the input is only for reading, not writing.

Efficient for Large Strings:
Using & (reference) prevents making a copy of the string, saving memory and improving performance.

Avoids Unintended Side Effects:
Protects the input from changes, which is essential in functions like these.
🚀 When Can You Skip const?
If the string is small and performance isn’t a concern.
If the function is designed to modify the string intentionally.
---

## **Summary**
| Type          | Unique Values | Sorted | Allows Duplicates | Time Complexity (Insert/Delete/Search) |
|----------------|---------------|--------|--------------------|----------------------------------------|
| Set            | Yes           | Yes    | No                 | O(log n)                               |
| Unordered Set  | Yes           | No     | No                 | O(1) on average                       |
| Multiset       | No            | Yes    | Yes                | O(log n)                               |

---
This version is simplified for better understanding and revision. Let me know if you'd like further adjustments!



### Self-Balancing Tree (Basic Concept)
A **Self-Balancing Binary Search Tree (BST)** is a binary tree that maintains a balanced structure to ensure operations like insertion, deletion, and search are efficient.

### Node Class Definition
```cpp
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
        // left = NULL;     // Used by Vikash Sir
    }
};
```
- `Node* left` and `Node* right` are pointers to the left and right child nodes.
- `nullptr` is used instead of `null` for pointer initialization in C++.

### Creating a Tree and Initializing Nodes
```cpp
#include<iostream>
using namespace std;

int main() {
    // Creating root node
    Node* root = new Node(10);

    // Inserting nodes
    root->left = new Node(20);
    root->right = new Node(30);

    cout << "Root Node: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;

    cout << "Preorder: ";
    cout << root->data << " ";
    cout << root->left->data << " ";
    cout << root->right->data << endl;

    cout << "Inorder: ";
    cout << root->left->data << " ";
    cout << root->data << " ";
    cout << root->right->data << endl;

    cout << "Postorder: ";
    cout << root->left->data << " ";
    cout << root->right->data << " ";
    cout << root->data << endl;

    return 0;
}
```
- `root->left` accesses the left child using the arrow operator (`->`) since `root` is a pointer.
- Similarly, `root->right` accesses the right child.

### Explanation
- **Preorder**: Visit the root, then the left subtree, and finally the right subtree.
- **Inorder**: Visit the left subtree, then the root, and then the right subtree.
- **Postorder**: Visit the left subtree, then the right subtree, and finally the root.

This simplified version should help you revise and understand the concept of self-balancing trees and basic operations on them.

"Binary Tree Implementation and Traversal in C++"
#include<iostream>
using namespace std;

// Node structure for Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node with value
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// // Function to create a sample binary tree (if uncomment the main section part)
// node* createSampleTree() {
//     node* root = new node(10);
//     root->left = new node(20);
//     root->right = new node(30);
//     return root;
// }

// Preorder traversal: Root -> Left -> Right
void preorder(Node* n) {
    if (n == NULL)
        return;
    cout << n->data << "\t";
    preorder(n->left);
    preorder(n->right);
}

// Inorder traversal: Left -> Root -> Right
void inorder(Node* n) {
    if (n == NULL)
        return;
    inorder(n->left);
    cout << n->data << "\t";
    inorder(n->right);
}

// Postorder traversal: Left -> Right -> Root
void postorder(Node* n) {
    if (n == NULL)
        return;
    postorder(n->left);
    postorder(n->right);
    cout << n->data << "\t";
}

int main() {
    // // Create a sample binary tree with hardcoded values(call function)
    // node* root = createSampleTree();
    // or this way by sir:

    // Creating root node
    Node* root = new Node(10);

    // Inserting nodes
    root->left = new Node(20);
    root->right = new Node(30);

    // Performing traversals
    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}

// Binary Tree Implementation with Preorder, Inorder, and Postorder Traversals
#include<iostream>
using namespace std;

// Node structure for binary tree
class node {
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize node with a value
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to create a binary tree recursively
node* create(node *root) {
    int d;
    cout << "Enter value (-1 for NULL): ";
    cin >> d;

    if (d == -1) {
        return NULL; // -1 represents no node (NULL)
    }

    root = new node(d);

    cout << "Enter value for left of " << d << endl;
    root->left = create(root->left);

    cout << "Enter value for right of " << d << endl;
    root->right = create(root->right);

    return root;
}

// Preorder traversal (Root -> Left -> Right)
void preorder(node *n) {
    if (n == NULL) return;
    cout << n->data << "\t";
    preorder(n->left);
    preorder(n->right);
}

// Inorder traversal (Left -> Root -> Right)
void inorder(node *n) {
    if (n == NULL) return;
    inorder(n->left);
    cout << n->data << "\t";
    inorder(n->right);
}

// Postorder traversal (Left -> Right -> Root)
void postorder(node *n) {
    if (n == NULL) return;
    postorder(n->left);
    postorder(n->right);
    cout << n->data << "\t";
}

// Main function
int main() {
    node *root = NULL;

    // Create the binary tree
    root = create(root);

    // Perform tree traversals
    cout << "\nPreorder Traversal: \n";
    preorder(root);

    cout << "\nInorder Traversal: \n";
    inorder(root);

    cout << "\nPostorder Traversal: \n";
    postorder(root);

    return 0;
} 
