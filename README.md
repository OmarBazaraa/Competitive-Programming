# Competitive Programming

C++ Code library contains useful algorithms for competitive programming.

## Content

### Data Structures
- [Disjoint-Sets Union (DSU)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/data_structures/disjoint_sets_union)
- [Monotonic Queue](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/data_structures/monotonic_queue)
	- [Implemented with two stacks](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/monotonic_queue/monotonic_queue_using_stacks.cpp)
	- [Implemented with double ended queue](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/monotonic_queue/monotonic_queue.cpp)
- [Sparse Table](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/data_structures/sparse_table)
- Trees
	- [Fenwick Tree (Binary Indexed Tree)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/data_structures/fenwick_tree)
		- [Basic Fenwick Tree](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/fenwick_tree/fenwick_tree.cpp)
		- [Fenwick Tree with Range Update](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/fenwick_tree/fenwick_tree_range.cpp)
		- [Fenwick Tree as Multiset](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/fenwick_tree/multiset.cpp)
	- Segment Tree **<i>(comming soon)</i>**
		- Basic Segment Tree (static memory allocation)
		- Basic Segment Tree (dynamic memory allocation)
		- Persistent Segment Tree
	- [Treap](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/data_structures/treap)
	- Splay Tree **<i>(comming soon)</i>**
- [SQRT Decomposition](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/data_structures/sqrt_decomposition)
	- [Mo's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/sqrt_decomposition/mo_algorithm.cpp)

### Strings
- [KMP](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/strings/KMP)
- [Z-Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/strings/z_algorithm)
- [Trie](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/strings/trie)
	- [Implemented with static memory allocation](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/strings/trie/trie_static.cpp)
	- [Implemented with dynamic memory allocation](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/strings/trie/trie_dynamic.cpp)
- Suffix Array **<i>(comming soon)</i>**
- Aho Corasick's Algorithm **<i>(comming soon)</i>**

### Graphs
- [Graph Traversal and Representation](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/traversal)
	- [Optimized Representation](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal_static.cpp)
	- [DFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp)
	- [BFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp)
- [Topological Sort](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/traversal)
	- [DFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp)
	- [BFS (Khan's Algorithm)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp)
- [Shortest Path](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/shortest_path)
	- Single Source Shortest Path (SSSP)
		- [BFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/bfs.cpp)
		- [Dijkstra's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/dijkstra.cpp)
		- [Bellman Ford's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/bellman_ford.cpp)
		- Optimized Bellman Ford's Algorithm **<i>(comming soon)</i>**
	- All Pair Shortest Path (APSP)
		- [Floyd Warshal's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/floyd_warshal.cpp)
- Minimum Spanning Tree
	- Prim's Algorithm **<i>(comming soon)</i>**
	- Kruskal's Algorithm **<i>(comming soon)</i>**
- [Strongly Connected Components (SCC)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/strongly_connected_components)
	- [Kosaraju's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/strongly_connected_components/kosaraju.cpp)
- [Lowest Common Ancestor (LCA)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/lowest_common_ancestor)
	- [Implemented with parent sparse table](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/lowest_common_ancestor/LCA.cpp)
	- [Implemented with Euler walk and RMQ](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/lowest_common_ancestor/LCA_Euler.cpp)
- Max Flow
	- Edmonds-Karp's Algorithm **<i>(comming soon)</i>**

### Math
- Greatest Common Divisor (GCD)
- Least Common Multiple (LCM)
- Bézout's Coefficients (using extended Euclid's method)
- Fast Power
- Modular Inverse
- Combinations (nCr)
- Pascal Triangle
- Check Integer Primality
- Generate Prime Numbers (using Sieve of Eratosthenes' algorithm)
- Generate Divisors (single/bulk operation)
	- All divisors
	- Prime divisors
- Matrix Power **<i>(comming soon)</i>**
- Matrix Class

### Geomerty
Will be added soon...

### Other Algorithms
- Compute the length of the longest increasing sub-sequence (LIS)
- Stress test code
- Some other definitions
