
            SET(single key)
        set, unordered, multi 
    
in map<int, string>
set: <int>
unique, sorted, red black tree 
unordered:
random, hashing technique, 
insertion time complexity O(1) 
Multi:
sorted, duplicate 
set use in graph and map use in tree  

#include<iostream>
using namespace std;
#include<set>
int main(){
    set<int>s{10, 20, 1, 2, 6};
    for (auto p:s){
        cout<<p<<"\t";
    }
    cout<<endl;
    s.insert(35);
    for (auto p:s){
        cout<<p<<"\t";
    }
    s.erase(20);
    cout<<"\n";
    auto t=s.find(2);
    if(t!=s.end()){
        cout<<"found = "<< *t;
    }
    else{
        cout<<"not found";
    }
} 
// unordered   
#include<iostream>
using namespace std;
#include<unordered_set>
int main(){
    unordered_set<int>s{10, 20, 1, 2, 6};
    for (auto p:s){
        cout<<p<<"\t";
    }
    cout<<endl;
    s.insert(35);
    for (auto p:s){
        cout<<p<<"\t";
    }
    s.erase(20);
    cout<<"\n";
    auto t=s.find(2);
    if(t!=s.end()){
        cout<<"found = "<< *t;
    }
    else{
        cout<<"not found";
    }
}   
// multi set   
#include<iostream>
using namespace std;
#include<set>
int main(){
    multiset<int>s{10,10, 20, 1, 2, 6};
    for (auto p:s){
        cout<<p<<"\t";
    }
    cout<<endl;
    s.insert(35);
    for (auto p:s){
        cout<<p<<"\t";
    }
    s.erase(20);
    cout<<"\n";
    auto t=s.find(2);
    if(t!=s.end()){
        cout<<"found = "<< *t;
    }
    else{
        cout<<"not found";
    }
    cout<<"\n";
    for(auto p:s){
        cout<<p<<"\t";
    }
    auto p=s.find(10);      // also delete all exist
    if(p!=s.end()){
        s.erase(p);
    }
    cout<<"\n after delete\n";
    for(auto p:s){
        cout<<p<<"\t";
    }
    
}   
WAP to search given string is panagram or not 
#include<iostream>
using namespace std;    
int panagram(string &s){
    if(auto a)
    for(auto p:s){
        cout<<p<<"\t";
    }
}    

int main(){
    string s="The quick brown fox jumps over the lazy dog";
    if(panagram(s)){
        cout<<"it is panagram string";
    }
    else{
        cout<<"not panagram";
    }
}


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

