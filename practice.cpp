
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
    // // Create a sample binary tree with hardcoded values
    // node* root = createSampleTree();
    // or 
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
