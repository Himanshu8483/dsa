/*
Tree in Data Structures and Algorithms (DSA) - Complete Notes

1. Introduction to Trees
A Tree is a hierarchical non-linear data structure where nodes are connected by edges. It is used in databases, file systems, and artificial intelligence.

2. Basic Terminology

2.1 Node
A single element in a tree that contains data and references to child nodes.

2.2 Root Node
The topmost node in the tree (starting point).

2.3 Parent & Child Node
Parent: A node that has children(Parent node is predecessor of child node).
Child: A node connected under a parent(Child node is the successor of Parent node).

2.4 Sibling
Nodes that share the same parent.

2.5 Leaf Node (External Node)
A node that does not have any children.

2.6 Non-Leaf Node (Internal Node)
A node that has at least one child.

2.7 Degree of a Node
The number of children of that node.

2.8 Degree of a Tree
The maximum degree of any node in the tree.

2.9 Level of a Node
The distance from the root, starting at level 0.

2.10 Path
A sequence of edges connecting two nodes.

2.11 Edge
A link between two nodes.

2.12 Height of a Node
The number of edges in the longest path from that node to a leaf.

2.13 Height of a Tree
The height of the root node(Number of edges in the longest path from that node to leaf).

2.14 Depth of a Node
The number of edges from the root to that node.

2.15 Ancestor & Descendant
Ancestor: Any node on the path from the root to the node.
Descendant: Any node in the subtree of a given node.

3. Types of Trees

3.1 General Tree
A tree where each node can have any number of children.

3.2 Binary Tree
A tree where each node has at most two children (left and right).

3.3 Binary Search Tree (BST)
A binary tree where:
Left child < Parent
Right child > Parent

3.4 Strict (Proper) Binary Tree
A binary tree where every node has either 0 or 2 children.
E.g., Number of Leaf Node = Number of Internal Node +1.

3.5 Complete Binary Tree
A tree where all levels are completely filled, and node followed by left possible.

3.6 Perfect Binary Tree
A tree where all levels are fully filled, and all leaf nodes are at the same level.

3.7 Degenerate (Skewed) Tree
A tree that behaves like a linked list:
Left-Skewed: Each node has only a left child.
Right-Skewed: Each node has only a right child.

3.8 Balanced Binary Tree
A tree where the height difference between left and right subtrees is at most 1.

3.9 AVL Tree
A self-balancing BST where the height difference of left and right subtrees is at most 1.

3.10 Red-Black Tree
A self-balancing BST that follows color properties (Red & Black nodes) for balancing.

3.11 B-Tree
A generalized self-balancing search tree used in databases and file systems.

4. Tree Traversal Techniques

4.1 Depth-First Search (DFS)
DFS explores as far as possible before backtracking.

Types of DFS:
1. Preorder (Root → Left → Right)
2. Inorder (Left → Root → Right)
3. Postorder (Left → Right → Root)

Trick to Remember:
Preorder: Parent First (Root Left Right)
Inorder: In Between (Left Root Right)
Postorder: Parent Last (Left Right Root)
e.g.,
        A
       / \
      B   C
     / \   \
    D   E   F
🔹 Preorder Output: A → B → D → E → C → F
🔹 Inorder Output: D → B → E → A → C → F
🔹 Postorder Output: D → E → B → F → C → A

4.2 Breadth-First Search (BFS) (Level Order Traversal)
Visits all nodes at each level before going deeper.

5. Tree Example (Valid & Invalid)

Valid Tree
        A
       / \
      B   C
     / \   \
    D   E   F
A is the root.
Each node is connected properly.

Invalid Tree
        A
       / \
      B - C  (B and C are directly connected, breaking hierarchy)
A tree cannot have cycles.

6. Operations on Trees
Insertion: Add a node.
Deletion: Remove a node.
Searching: Find a node.
Traversal: Visit nodes.

7. Applications of Trees
Binary Search Tree (BST): Fast searching.
AVL Tree, Red-Black Tree: Balanced trees for efficiency.
B-Tree: Used in databases.
Trie: Used in autocomplete systems.
Heap (Binary Heap): Used in priority queues.
*/