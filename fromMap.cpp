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
