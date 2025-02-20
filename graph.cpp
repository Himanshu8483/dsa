/* 
Graph in Data Structures
1. What is a Graph?
A Graph is a non-linear data structure consisting of a collection of vertices (nodes) and edges (connections).
It is used to represent networks like Google Maps, social networks, and the internet.

2. Components of a Graph
Vertex (V) – A node in a graph.
Edge (E) – A connection between two vertices.
Graph = (V, E)
3. Types of Graphs
(i) Based on Edge Weight
Weighted Graph – Edges have weights (cost, distance, etc.).
Unweighted Graph – All edges have the same weight.
✅ Example of Weighted & Unweighted Graphs

Weighted Graph (Directed & Undirected)
    (A)---    2-- B)      (A)→2→(B)
     | \         / |      |       |
    5|  3      4|  1      5↓       ↓4
     |   \    /  |      (C)→1→(D)
    (C)---6---(D)
Unweighted Graph (Directed & Undirected)
    (A)---    (B)       (A)→(B)
     | \      / |      |      |
     |  \    /  |      ↓      ↓
    (C)---(D)       (C)→(D)
(ii) Based on Cycles
Cyclic Graph – Contains at least one cycle.
Acyclic Graph – No cycles are present.
✅ Example of Cyclic & Acyclic Graphs
    Cyclic: A → B → C → A  
    Acyclic: A → B → C → D
(iii) Other Special Graphs
Self-loop Graph – A vertex has an edge to itself.
Adjacent Vertices – Two vertices connected by an edge.
Multi-Edge Graph – Multiple edges between two vertices.
Simple Graph – No loops, no multiple edges.
Multi-Graph – Multiple edges allowed.
PseudoGraph – A graph with self-loops and multiple edges.

4. Graph Representation
(i) Adjacency Matrix (2D Array)
Uses N × N matrix where 1 represents an edge and 0 represents no edge.
✅ Example of Adjacency Matrix (for Weighted Graph)
    A	B	C	D
A	0	2	5	3
B	2	0	4	1
C	5	4	0	6
D	3	1	6	0
0 means no edge.
Numbers represent edge weights.
(ii) Adjacency List (Linked List)
Each vertex has a list of connected vertices.
✅ Example of Adjacency List (Weighted Graph)
A → (B,2) → (C,5) → (D,3)  
B → (A,2) → (C,4) → (D,1)  
C → (A,5) → (B,4) → (D,6)  
D → (A,3) → (B,1) → (C,6)  

5. Graph Traversal Algorithms
(i) BFS (Breadth-First Search)
Uses Queue (FIFO).
Explores neighbors first, then moves to the next level.
Example: Finding the shortest path in an unweighted graph.
Graph:
    (A)
   /   \
 (B)   (C)
  |     |
 (D)   (E)

✅ Example BFS Traversal
📌 Steps:
Visit A, add neighbors B, C to the queue.
Visit B, add D to the queue.
Visit C, add E to the queue.
Visit D (No new neighbors).
Visit E (No new neighbors).

✅ BFS Order (starting from A):
A → B → C → D → E

(ii) DFS (Depth-First Search)
Uses Stack (LIFO).
Explores deep into the graph before backtracking.
Example: Solving mazes and puzzles.
✅ Example DFS Traversal
📌 Steps:

Visit A, move to B.
Visit B, move to D.
Visit D (No new neighbors, backtrack).
Back to A, move to C.
Visit C, move to E.
Visit E (No new neighbors, backtrack).

✅ DFS Order (starting from A):
A → B → D → C → E
*/