/*
Tree in Data Structures and Algorithms (DSA) - Complete Notes

Introduction to Trees
A Tree is a hierarchical non-linear data structure where nodes are connected by edges. It is used in databases, file systems, and artificial intelligence.

Basic Terminology

Node
A single element in a tree that contains data and references to child nodes.

Root Node
The topmost node in the tree (starting point).

Parent & Child Node
Parent: A node that has children(Parent node is predecessor of child node).
Child: A node connected under a parent(Child node is the successor of Parent node).

Sibling
Nodes that share the same parent.

Leaf Node (External Node)
A node that does not have any children.

Non-Leaf Node (Internal Node)
A node that has at least one child.

Degree of a Node
The number of children of that node.

Degree of a Tree
The maximum degree of any node in the tree.

Level of a Node
The distance from the root, starting at level 0.

Path
A sequence of edges connecting two nodes.

Edge
A link between two nodes.

Height of a Node
The number of edges in the longest path from that node to a leaf.

Height of a Tree
The height of the root node(Number of edges in the longest path from that node to leaf).

Depth of a Node
The number of edges from the root to that node.

Ancestor & Descendant
Ancestor: Any node on the path from the root to the node.
Descendant: Any node in the subtree of a given node.

Types of Trees
General Tree
A tree where each node can have any number of children.

Binary Tree
A tree where each node has at most two children (left and right).

Types of Binary Tree:
Strict (Proper) Binary Tree
A binary tree where every node has either 0 or 2 children.
E.g., Number of Leaf Node = Number of Internal Node +1.

Complete Binary Tree
A tree where all levels are completely filled, and node followed by left possible.

Perfect/Full Binary Tree
All internal nodes should contain 2 children and all leaf node at same source level. 

Degenerate (Skewed) Tree
A tree that behaves like a linked list:
Left-Skewed: Each node has only a left child.
Right-Skewed: Each node has only a right child.


Binary Search Tree (BST)
A binary tree where:
Left child < Parent
Right child > Parent

Tree Traversal Techniques
Depth-First Search (DFS)
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

Breadth-First Search (BFS) (Level Order Traversal)
Visits all nodes at each level before going deeper.

AVL Tree Rotations 
An **AVL tree** is a self-balancing binary search tree where the height difference (balance factor) between the left and right subtrees is at most 1. If the tree becomes unbalanced, **rotations** are used to restore balance.
steps: i) Always BST.
ii) Balance Factor (-1, 0,1)
iii) Rotation: LL, RR, LR, RL

## **Types of Rotations in AVL Tree**

There are **four types of rotations** used in AVL trees:

1. **LL (Left-Left) Rotation** → Right Rotation
2. **RR (Right-Right) Rotation** → Left Rotation
3. **LR (Left-Right) Rotation** → Left Rotate + Right Rotate
4. **RL (Right-Left) Rotation** → Right Rotate + Left Rotate

---

## **1. LL (Left-Left) Rotation → Right Rotation (Single Rotation)**

**When?** A node is inserted in the **left subtree** of the **left child**, making the tree left-heavy.

### **Example:** Insert 10, 5, 2

```
    10
   /
  5
 /
2
HERE 2-0(Unbalanced)
```

**Unbalanced → Right Rotate on 10**

```
   5
  / \
 2   10
```

✅ **LL → Rotate Right** (opposite direction)

---

## **2. RR (Right-Right) Rotation → Left Rotation (Single Rotation)**

**When?** A node is inserted in the **right subtree** of the **right child**, making the tree right-heavy.

### **Example:** Insert 10, 15, 20

```
   10
     \
     15
       \
       20
       Here 0-2 (imbalanced)
```

**Unbalanced → Left Rotate on 10**

```
     15
    /  \
  10    20
```

✅ **RR → Rotate Left** (opposite direction)

---

## **3. LR (Left-Right) Rotation → Left Rotate + Right Rotate (Double Rotation)**

**When?** A node is inserted in the **right subtree** of the **left child**.

### **Example:** Insert 10, 5, 8

```
    10
   /
  5
   \
    8
    Here 2-0 (imbalanced)
```

✅ **Step 1: Left Rotate on 5**

```
    10
   /
  8
 /
5
```

✅ **Step 2: Right Rotate on 10**

```
    8
   / \
  5   10
```

✅ **LR → Left Rotate (child) + Right Rotate (parent)**

---

## **4. RL (Right-Left) Rotation → Right Rotate + Left Rotate (Double Rotation)**

**When?** A node is inserted in the **left subtree** of the **right child**.

### **Example:** Insert 10, 15, 12

```
   10
     \
     15
    /
   12
   Here 0-2 (imbalanced)
```

✅ **Step 1: Right Rotate on 15**

```
   10
     \
     12
       \
       15
```

✅ **Step 2: Left Rotate on 10**

```
     12
    /  \
  10    15
```

✅ **RL → Right Rotate (child) + Left Rotate (parent)**

---

## **Trick to Remember Rotations**

- **LL (Left-Left) → Rotate Right**
- **RR (Right-Right) → Rotate Left**
- **LR (Left-Right) → Left Rotate (child) + Right Rotate (parent)**
- **RL (Right-Left) → Right Rotate (child) + Left Rotate (parent)**

**Single Rotations (LL, RR) move in the opposite direction.**
**Double Rotations (LR, RL) involve two-step adjustments.**


*/
