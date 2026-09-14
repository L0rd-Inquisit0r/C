# Data Structures & Algorithms in C

A organized collection of fundamental data structures and algorithmic implementations written in C.

---

## Data Structures Checklist

### Linear Data Structures
- [x] **Array List** — Sequential memory implementation (`O(1)` access, `O(N)` insertion/deletion)
- [x] **Linked List** — Pointer-based dynamic list (`O(N)` access, `O(1)` head insert/delete)
- [x] **Cursor List** — Array-based simulate-pointer linked list (`O(N)` access)
- [x] **Array Stack** — LIFO array-backed stack (`O(1)` push/pop)
- [x] **Linked Stack** — LIFO pointer-backed stack (`O(1)` push/pop)
- [x] **Cursor Stack** — LIFO cursor-backed stack (`O(1)` push/pop)
- [x] **Array Queue** — FIFO circular array queue (`O(1)` enqueue/dequeue)
- [x] **Linked Queue** — FIFO pointer-backed queue (`O(1)` enqueue/dequeue)
- [x] **Cursor Queue** — FIFO cursor-backed queue (`O(1)` enqueue/dequeue)

### Sets & Dictionaries
- [x] **Bit Vector Set** — Fast set operations via bitwise operations (`O(1)` lookups)
- [x] **Computer Word Set** — Set encoding in standard machine word formats
- [x] **Open Hashing Dictionary** — Separate chaining hash table (`O(1)` avg lookup)
- [X] **Closed Hashing Dictionary** — Open addressing / linear or quadratic probing (`O(1)` avg lookup)

### Trees & Priority Queues
- [X] **Binary Tree** — Basic tree node traversals (Pre-order, In-order, Post-order)
- [X] **Max Heap** — Array-based Max Priority Queue (`O(log N)` insert/deleteMax, `O(N)` heapify)
- [ ] **Min Heap** — Array-based Min Priority Queue (`O(log N)` insert/deleteMin)
- [ ] **Binary Search Tree (BST)** — Search tree supporting dynamic updates (`O(log N)` avg search)
- [ ] **AVL Tree** — Self-balancing BST with LL/RR/LR/RL rotations (`O(log N)` worst-case search)
- [ ] **Trie (Prefix Tree)** — Fast retrieval for dictionary strings (`O(L)` lookup where L = key length)
- [ ] **Disjoint Set Union (DSU)** — Disjoint sets with path compression (`O(α(N))` operations)

### Graphs
- [ ] **Adjacency Matrix** — Dense graph representation (`O(1)` edge lookup, `O(V²)` space)
- [ ] **Adjacency List** — Sparse graph representation (`O(V + E)` space)

### Multiway & External Storage Trees (B-Trees)
- [ ] **B-Tree** — Self-balancing $m$-way tree for disk storage (`O(log N)` search/insert)
- [ ] **B+ Tree** — Data-in-leaves variant with linked leaf nodes for range queries (`O(log N)` search, fast range scan)
- [ ] **B\* Tree** — High-density variant requiring 2/3 node fill factor (`O(log N)` search, higher space efficiency)

---

## Algorithms Checklist

### Sorting Algorithms
#### Core
- [ ] **Bubble Sort** — `O(N²)` time | `O(1)` space
- [ ] **Insertion Sort** — `O(N²)` time | `O(1)` space
- [ ] **Selection Sort** — `O(N²)` time | `O(1)` space
- [ ] **Merge Sort** — `O(N log N)` time | `O(N)` space
- [ ] **Quick Sort** — `O(N log N)` avg time | `O(log N)` space
- [ ] **Heap Sort** — `O(N log N)` time | `O(1)` space
- [ ] **Counting Sort** — `O(N + K)` non-comparison sort
- [ ] **Radix Sort** — `O(N · K)` digit-by-digit distribution sort

#### Niche & Specialized
- [ ] **Shell Sort** — `O(N^1.5)` gap sequence optimization
- [ ] **Bucket Sort** — `O(N + K)` uniform distribution sort
- [ ] **Comb Sort** — Variant of bubble sort using variable gaps
- [ ] **Gnome Sort** — Single-loop sorting algorithm
- [ ] **Strand Sort** — Linked-list sublist merging sort
- [ ] **Tournament Sort** — Tree-selection based sort

### Searching & Matching
- [ ] **Linear Search** — Unsorted search (`O(N)`)
- [ ] **Binary Search** — Iterative & recursive divide-and-conquer (`O(log N)`)
- [ ] **Interpolation Search** — Uniformly distributed sorted data search (`O(log log N)`)
- [ ] **KMP Algorithm** — Knuth-Morris-Pratt pattern matching (`O(N + M)`)

### Graph Algorithms
- [ ] **Breadth-First Search (BFS)** — Queue-based level traversal (`O(V + E)`)
- [ ] **Depth-First Search (DFS)** — Stack/recursive path traversal (`O(V + E)`)
- [ ] **Dijkstra’s Algorithm** — Single-source shortest path with Min-Heap (`O((V + E) log V)`)
- [ ] **Bellman-Ford Algorithm** — Shortest path handling negative weight edges (`O(V · E)`)
- [ ] **Floyd-Warshall Algorithm** — All-pairs shortest path dynamic programming (`O(V³)`)
- [ ] **Kruskal’s Algorithm** — Minimum Spanning Tree using DSU (`O(E log E)`)
- [ ] **Prim’s Algorithm** — Minimum Spanning Tree using Priority Queue (`O(E log V)`)
- [ ] **Topological Sort** — Directed Acyclic Graph (DAG) ordering (`O(V + E)`)

### Dynamic Programming & Greedy
- [ ] **0/1 Knapsack Problem** — Dynamic programming state space optimization
- [ ] **Longest Common Subsequence (LCS)** — Sequence matching
- [ ] **Huffman Coding** — Greedy greedy-choice greedy compression tree construction