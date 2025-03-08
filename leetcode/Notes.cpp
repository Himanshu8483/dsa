📌 1. Map in C++ (std::map)
A map in C++ is an associative container that stores key-value pairs in sorted order.

✅ Properties of std::map:
Stores unique key-value pairs.
Ordered (sorted by keys).
Implemented using Red-Black Tree (Self-balancing BST).
Search, insertion, and deletion take O(log N) time.
✅ Basic Operations:
cpp
Copy
Edit
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mp;  // Declaring a map (Key: int, Value: string)

    // Inserting elements
    mp[1] = "Apple";
    mp[3] = "Mango";
    mp[2] = "Banana";

    // Accessing values
    cout << mp[2] << endl;  // Output: Banana

    // Iterating through the map
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // Searching
    if (mp.find(3) != mp.end())
        cout << "Key 3 Found!" << endl;

    return 0;
}
✅ Time Complexity:
Operation	Time Complexity
Insertion	O(log N)
Deletion	O(log N)
Search	O(log N)
📌 2. Binary Search
Binary Search is an efficient search algorithm that works on a sorted array.

✅ How it Works?
Find the middle element.
If the middle element is the target, return its index.
If the target is smaller, search the left half.
If the target is greater, search the right half.
Repeat until the element is found or the range is exhausted.
✅ Code Implementation:
cpp
Copy
Edit
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;  // Element found

        if (arr[mid] < key)
            left = mid + 1;  // Search in right half
        else
            right = mid - 1;  // Search in left half
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

✅ Time Complexity:
Case	Time Complexity
Best Case	O(1)
Average Case	O(log N)
Worst Case	O(log N)
⚠ Binary Search only works on sorted arrays!

📌 3. Linear Search
Linear search checks each element one by one until the target element is found.

✅ How it Works?
Start from the first element.
Compare each element with the target.
If found, return its index.
If not found, return -1.
✅ Code Implementation:
cpp
Copy
Edit
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;  // Not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    
    int result = linearSearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
✅ Time Complexity:
Case	Time Complexity
Best Case	O(1)
Average Case	O(N)
Worst Case	O(N)
⚠ Linear search works on both sorted and unsorted arrays!

📌 Summary Table:
Algorithm	Best Case	Average Case	Worst Case	Used For
Map (std::map)	O(1) (for access)	O(log N)	O(log N)	Key-value storage (Ordered)
Binary Search	O(1)	O(log N)	O(log N)	Searching in sorted arrays
Linear Search	O(1)	O(N)	O(N)	Searching in any array