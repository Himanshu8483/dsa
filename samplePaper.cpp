Sample Paper of DSA

Q.1 Swapping two numbers,factorial,max value between two and many more function program using template function .
Q.2 Simple Calculator like +,-,* & / Using Class Template.
Q.3 Class Templates With Multiple Parameters.
Q.4 Check the given string is palindrome or not.
Q.5 Find min value using stack.
Q.6 Display values of stack in reverse order.
Q.7 Valid Parenthesis.
Q.8 Print unique strings in lexicography order with their frequency:
Example 1:
 Input: a=[“pen”,”copy”,”pen”,”copy”,”eraser”]
Output:copy=2,eraser=1,pen=2

Input: a=[“mon”,”tue”,”mon”,”sun”]
Output:mon=2,sun=1,tue=1



Q.9 Two pair Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Q.10  Find missing numbers
Input s1={1,2,3,5,6,8}
Output={4, 7}  


Q.11  Find Maximum depth of binary tree?

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 
Q.12  Count the leaf node?

Q.13 Write a program for all three traversing order of tree?

Q.14  Write a program to sum of two array. 
Input: A1 = [2, 3, 1, 4]   &  A2= [6] 
Output: 2320
Input: A1 = [2, 3, 1, 4]   & A2=[2,3] 
Output: 2337

Q.15  Write a C++ program to separate even and odd numbers in a array of integers. Put all even numbers first, and then odd numbers.
 Input: 14,21,6,7,8,3,9
 Output:14,6,8,21,7,3,9

Q.16 Write a C++ program to sort a given array of 0s, 1s and 2s. In the final array put all 0s first, then all 1s and all 2s last. 
Input:0,1,0,1,0,2,1,2 
Output:0,0,0,1,1,1,2,2

Q.17 Given a sorted array of n elements, find the number of occurrences of each element.
Input: arr = [4, 4, 8, 8, 8, 15, 16, 23, 23, 53]
Output: 4=2
               8=3
              15=1
              23=2
              53=1

Q.18  Delete the specific position from an array.
Input: arr = [9,3,2,1,5,23,10,4],position=3
Output: [9,3,2,5,23,10,4]

Q.19 Find Array is Subset of Another Array

Q.20 Check if two Array are equal or not.

Q.21 Given   String is anagram or not.

Q.22  Isomorphic String:
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
 Example 1:
Input: s = "egg", t = "add"
Output: true
Example 2:
Input: s = "gun", t = "bar"
Output: false


Q.23  Convert Roman to Integer.

Q.24 Convert Integer to Roman.

Q.25 Create Binary tree.
-----------------------------------------------------------------------------------
Solution:

// Q.1 Swapping, Factorial, Max using Template Function
#include<iostream>
using namespace std;

// Swap Function
template <typename T>
void swapNumbers(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Factorial Function using Recursion
template <typename T>
T factorial(T n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Max Function
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 5, b = 10;
    swapNumbers(a, b);
    cout << "Swapped: " << a << " " << b << endl;

    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Max of 3 and 7: " << findMax(3, 7) << endl;
    return 0;
}

// Q.2 Simple Calculator using Class Template
template <typename T>
class Calculator {
public:
    T add(T a, T b) { return a + b; }
    T subtract(T a, T b) { return a - b; }
    T multiply(T a, T b) { return a * b; }
    T divide(T a, T b) { return (b != 0) ? a / b : 0; }
};

int main() {
    Calculator<double> calc;
    cout << "Add: " << calc.add(10.5, 5.5) << endl;
    cout << "Subtract: " << calc.subtract(10.5, 5.5) << endl;
    cout << "Multiply: " << calc.multiply(10.5, 5.5) << endl;
    cout << "Divide: " << calc.divide(10.5, 5.5) << endl;
    return 0;
}

// Q.3 Class Templates with Multiple Parameters
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(T1 a, T2 b){
        first = a;
        second = b;
    }
    void display() { 
        cout << first << ", " << second << endl; 
    }
};

int main() {
    Pair<string, int> p("Age", 24);
    p.display();
    return 0;
}

// Q.4 Check Palindrome
bool isPalindrome(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left++] != str[right--]) return false;
    }
    return true;
}

int main() {
    cout << "Palindrome: " << (isPalindrome("level") ? "Yes" : "No") << endl;
    return 0;
}

// Q.5 Find Min using Stack
#include<stack>
int findMin(stack<int> s) {
    int minVal = s.top();
    while (!s.empty()) {
        if (s.top() < minVal) minVal = s.top();
        s.pop();
    }
    return minVal;
}

int main() {
    stack<int> s;
    s.push(3); s.push(1); s.push(4);
    cout << "Min in Stack: " << findMin(s) << endl;
    return 0;
}

// Q.6 Display Stack in Reverse Order
#include<stack>
void displayReverse(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    stack<int> s;
    s.push(10); s.push(20); s.push(30);
    cout << "Stack in Reverse: "; displayReverse(s); cout << endl;
    return 0;
}
// Output: 
// Stack in Reverse: 30 20 10

// Q.7 Valid Parenthesis
#include <stack>         

bool isValid(string s) {
    stack<char> st; 

    for (char ch : s) 
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch); 
        } else {  
            if (st.empty()) return false;  // No matching opening bracket
            
            // Directly check if the top element is matching
            if ((ch == ')' && st.top() != '(') || 
                (ch == '}' && st.top() != '{') || 
                (ch == ']' && st.top() != '[')) {
                return false;
            }
            st.pop(); 
        }
    return st.empty(); 
}

int main() {
    cout << "Valid Parenthesis: " << (isValid("{[()]}") ? "Yes" : "No") << endl;
    return 0;
}

// Q.8 Print unique strings in lexicography order with their frequency
#include<map>
#include<vector>
#include<algorithm>

void printFrequency(vector<string>& a) {
    map<string, int> freq;
    for(auto &word : a) {
        freq[word]++;
    }
    for(auto &pair : freq) {
        cout << pair.first << "=" << pair.second << endl;
    }
}

int main() {
    vector<string> a1 = {"pen","copy","pen","copy","eraser"};
    vector<string> a2 = {"mon","tue","mon","sun"};
    
    cout << "Output 1:" << endl;
    printFrequency(a1);
    cout << "\nOutput 2:" << endl;
    printFrequency(a2);
    
    return 0;
}

// Q.9 Two Pair Sum
#include<vector>
#include<unordered_map>

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
// Example Walkthrough:
// nums = [2, 7, 11, 15], target = 9

// 1. i = 0 → nums[0] = 2
//    complement = 9 - 2 = 7
//    numMap = {}
//    Not found. Store → {2: 0}

// 2. i = 1 → nums[1] = 7
//    complement = 9 - 7 = 2
//    numMap = {2: 0}
//    Found! Return {0, 1}

// Q.10 Find Missing Numbers
#include<vector>

vector<int> findMissingNumbers(vector<int>& s1) {
    vector<int> missing;
    int n = s1.back();
    int index = 0;

    for (int i = 1; i <= n; i++) {
        if (index < s1.size() && s1[index] == i) {
            index++;
        } else {
            missing.push_back(i);
        }
    }
    return missing;
}

int main() {
    vector<int> s1 = {1,2,3,5,6,8};
    vector<int> result = findMissingNumbers(s1);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]<<"\t";
    }
    return 0;
}

// Q.11: Find Maximum Depth of Binary Tree
You can solve it using recursion. The maximum depth can be calculated using this simple logic:
The depth of an empty tree is 0.
The depth of a single node is 1.
The depth of a tree is 1 + max(left_depth, right_depth).

#include<iostream>
using namespace std;

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

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    return 0;
}

Output:

Maximum Depth: 3

// Q.12 Count the Leaf Nodes
A leaf node is a node that has no children (both left and right pointers are NULL).

#include<iostream>
using namespace std;

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

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Number of Leaf Nodes: " << countLeafNodes(root) << endl;
    return 0;
}

Output:

Number of Leaf Nodes: 3
Leaf Nodes: 9, 15, 7

// Q.13 Binary Tree Traversal 
#include<iostream>
using namespace std;

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

class BinaryTree {
public:
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    BinaryTree tree;
    cout << "Inorder: "; tree.inorder(root); cout << endl;
    cout << "Preorder: "; tree.preorder(root); cout << endl;
    cout << "Postorder: "; tree.postorder(root); cout << endl;
    
    return 0;
}

// Q.14 Sum of Two Arrays
#include<iostream>
#include<vector>
using namespace std;

int sumArrays(vector<int>& a1, vector<int>& a2) {
    long long num1 = 0, num2 = 0;
    for (int n : a1) num1 = num1 * 10 + n;
    for (int n : a2) num2 = num2 * 10 + n;
    return num1 + num2;
}
    
int main() {
    vector<int> A1 = {2, 3, 1, 4};
    vector<int> A2 = {6};
    cout << "Sum: " << sumArrays(A1, A2) << endl;

    vector<int> B1 = {2, 3, 1, 4};
    vector<int> B2 = {2, 3};
    cout << "Sum: " << sumArrays(B1, B2) << endl;
    
    return 0;
}

// Q.15 Separate Even and Odd Numbers
#include<iostream>
#include<vector>
using namespace std;

void separateEvenOdd(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = 0;
    while (right < n) {
        if (arr[right] % 2 == 0) {
            swap(arr[left], arr[right]);
            left++;
        }
        right++;
    }
}

int main() {
    vector<int> arr = {14, 21, 6, 7, 8, 3, 9};
    separateEvenOdd(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

// Q.16 Sort 0s, 1s, and 2s
#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 0, 2, 1, 2};
    sort012(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

// Q.17 Find Number of Occurrences of Each Element
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void findOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    for (auto& pair : freq) {
        cout << pair.first << "=" << pair.second << endl;
    }
}

int main() {
    vector<int> arr = {4, 4, 8, 8, 8, 15, 16, 23, 23, 53};
    findOccurrences(arr);
    return 0;
}

// Q.18 Delete Specific Position from an Array (Simple Way)
#include<iostream>
using namespace std;

void deleteAtPosition(int arr[], int &size, int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int arr[] = {9, 3, 2, 1, 5, 23, 10, 4};
    int size = 8;
    int position = 3;
    deleteAtPosition(arr, size, position);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// Q.19 Find if Array is a Subset of Another Array
#include<iostream>
#include<unordered_set>
using namespace std;

bool isSubset(int arr1[], int size1, int arr2[], int size2) {
    unordered_set<int> set;
    for (int i = 0; i < size1; i++) {
        set.insert(arr1[i]);
    }
    for (int i = 0; i < size2; i++) {
        if (set.find(arr2[i]) == set.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {9, 3, 2, 1, 5, 23, 10, 4};
    int arr2[] = {3, 1, 5};
    int size1 = 8, size2 = 3;
    
    if (isSubset(arr1, size1, arr2, size2)) {
        cout << "arr2 is a subset of arr1" << endl;
    } else {
        cout << "arr2 is not a subset of arr1" << endl;
    }
    
    return 0;
}

// Q.20 Check if Two Arrays are Equal
#include<iostream>
#include<unordered_map>
using namespace std;

bool areArraysEqual(int arr1[], int size1, int arr2[], int size2) {
    if (size1 != size2) return false;
    unordered_map<int, int> freq;

    for (int i = 0; i < size1; i++) {
        freq[arr1[i]]++;
    }

    for (int i = 0; i < size2; i++) {
        if (freq[arr2[i]] == 0) return false;
        freq[arr2[i]]--;
    }

    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int size1 = 5, size2 = 5;
    
    if (areArraysEqual(arr1, size1, arr2, size2)) {
        cout << "Arrays are equal" << endl;
    } else {
        cout << "Arrays are not equal" << endl;
    }
    
    return 0;
}

// Q.21 Check if Given String is an Anagram
#include<iostream>
#include<algorithm>
using namespace std;

bool isAnagram(string str1, string str2) {
    if (str1.length() != str2.length()) return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    string str1 = "listen", str2 = "silent";
    if (isAnagram(str1, str2)) {
        cout << "The strings are anagrams" << endl;
    } else {
        cout << "The strings are not anagrams" << endl;
    }
    return 0;
}

// Q.22 Isomorphic String
#include<iostream>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, char> mapST, mapTS;
    
    for (int i = 0; i < s.length(); i++) {
        char ch1 = s[i], ch2 = t[i];
        if ((mapST.count(ch1) && mapST[ch1] != ch2) || (mapTS.count(ch2) && mapTS[ch2] != ch1)) {
            return false;
        }
        mapST[ch1] = ch2;
        mapTS[ch2] = ch1;
    }
    return true;
}

int main() {
    string s = "egg", t = "add";
    if (isIsomorphic(s, t)) {
        cout << "The strings are isomorphic" << endl;
    } else {
        cout << "The strings are not isomorphic" << endl;
    }

    s = "gun", t = "bar";
    if (isIsomorphic(s, t)) {
        cout << "The strings are isomorphic" << endl;
    } else {
        cout << "The strings are not isomorphic" << endl;
    }

    return 0;
}

// Q.23 Convert Roman to Integer
#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                       {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }
    return result;
}

int main() {
    string roman1 = "XIV";
    cout << "Integer of " << roman1 << " is " << romanToInt(roman1) << endl;

    string roman2 = "MCMXCIV";
    cout << "Integer of " << roman2 << " is " << romanToInt(roman2) << endl;

    return 0;
}

// Q.24 Convert Integer to Roman (Simple Version)
#include<iostream>
using namespace std;

string intToRoman(int num) {
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result = "";

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            result += roman[i];
            num -= values[i];
        }
    }
    return result;
}

int main() {
    int num1 = 14;
    cout << "Roman of " << num1 << " is " << intToRoman(num1) << endl;

    int num2 = 1994;
    cout << "Roman of " << num2 << " is " << intToRoman(num2) << endl;

    return 0;
}
// or (By Using Map)
#include<iostream>
#include<map>
using namespace std;

string intToRoman(int num) {
    map<int, string, greater<int>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result = "";
    for (auto& pair : roman) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }
    return result;
}

int main() {
    int num1 = 14;
    cout << "Roman of " << num1 << " is " << intToRoman(num1) << endl;

    int num2 = 1994;
    cout << "Roman of " << num2 << " is " << intToRoman(num2) << endl;

    return 0;
}

// Q.25 Create Binary Tree
#include<iostream>
using namespace std;

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

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Creating tree nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
------------------------------------------------------------------ 
