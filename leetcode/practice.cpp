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