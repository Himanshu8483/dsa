#include<iostream>
#include<algorithm> // For find function
#include<list> // Include the list header file
using namespace std;

int main(){
    // Creating a doubly linked list using std::list
    list<int> l1;

    // Insert elements at the front of the list
    l1.push_front(10);
    l1.push_front(5);
    l1.push_front(40);
    
    // Insert element at the back of the list
    l1.push_back(50);

    // Display the list
    cout << "Initial list: \n";
    for(auto p : l1){
        cout << p << "\t";
    }
    
    // Uncomment below lines if you want to remove front and back elements
    // l1.pop_front(); // Remove first element
    // l1.pop_back(); // Remove last element
    
    cout << "\nAfter delete (if pop_front/pop_back used):\n";
    for(auto p : l1){
        cout << p << "\t";
    }
    
    // Insert an element at a specific position
    auto t = l1.begin(); // Iterator pointing to the first element
    advance(t, 2); // Move iterator to the 3rd position (0-based index)
    l1.insert(t, 1000); // Insert 1000 at the 3rd position
    
    cout << "\nAfter inserting 1000 at position 3:\n";
    for(auto p : l1){
        cout << p << "\t";
    }
    
    // Remove an element at a specific position
    auto t1 = l1.begin();
    advance(t1, 3); // Move iterator to the 4th element (0-based index)
    l1.erase(t1); // Remove the element at this position
    
    cout << "\nAfter removing element at position 4:\n";
    for(auto p : l1){
        cout << p << "\t";
    }
    
    // Update an element at a specific position
    auto t3 = l1.begin();
    advance(t3, 1); // Move iterator to the 2nd element (0-based index)
    *t3 = 900; // Update the value at this position
    
    cout << "\nAfter updating the 2nd element to 900:\n";
    for(auto p : l1){
        cout << p << "\t";
    }
    
    // Searching for an element in the list
    auto g = find(l1.begin(), l1.end(), 900); // Find 900 in the list
    if(g != l1.end()){
        cout << "\nElement found: " << *g;
    }
    else{
        cout << "\nElement not found";
    }
    
    return 0;
}
