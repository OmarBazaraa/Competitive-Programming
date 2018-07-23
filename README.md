# Competitive Programming

C++ code library contains useful algorithms for competitive programming.

## Content

A brief explanation to each of the following topics will be added soon, hopefully.

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
		- [Fenwick Tree as Multiset](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/fenwick_tree/fenwick_tree_multiset.cpp)
	- [Segment Tree](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/data_structures/segment_tree)
		- [Basic Segment Tree (static memory allocation)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/segment_tree/segment_tree_static.cpp)
		- [Basic Segment Tree (dynamic memory allocation)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/segment_tree/segment_tree_dynamic.cpp)
		- Persistent Segment Tree **<i>(comming soon)</i>**
		- [Segment Tree as Multiset](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/segment_tree/segment_tree_multiset.cpp)
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
	- [DFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp#L14)
	- [BFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp#L25)
- [Topological Sort](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/traversal)
	- [DFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp#L43)
	- [BFS (Khan's Algorithm)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/traversal/graph_traversal.cpp#L59)
- [Shortest Path](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/shortest_path)
	- Single Source Shortest Path (SSSP)
		- [BFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/bfs.cpp)
		- [Dijkstra's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/dijkstra.cpp)
		- [Bellman Ford's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/bellman_ford.cpp)
		- [Optimized Bellman Ford's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/bellman_ford_optimized.cpp)
	- All Pair Shortest Path (APSP)
		- [Floyd Warshal's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/shortest_path/floyd_warshal.cpp)
- [Minimum Spanning Tree](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/minimum_spanning_tree)
	- [Kruskal's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/minimum_spanning_tree/kruskal.cpp)
	- Prim's Algorithm **<i>(comming soon)</i>**
- [Strongly Connected Components (SCC)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/strongly_connected_components)
	- [Kosaraju's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/strongly_connected_components/kosaraju.cpp)
- [Lowest Common Ancestor (LCA)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/lowest_common_ancestor)
	- [Implemented with parent sparse table](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/lowest_common_ancestor/LCA.cpp)
	- [Implemented with Euler walk and RMQ](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/lowest_common_ancestor/LCA_Euler.cpp)
- Max Flow
	- Edmonds-Karp's Algorithm **<i>(comming soon)</i>**
- [Others](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/graphs/others)
	- [Tree Diameter](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/others/tree_diameter.cpp)
	- [Bipartite Graph Check](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/others/bipartite_graph.cpp)
	- [Graph Bridges](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/others/graph_bridges.cpp)
	- [Bridge Tree](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/graphs/others/bridge_tree.cpp)

### Math
- [Basic Discrete Math & Modular Arithmetics](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/math)
	- [Greatest Common Divisor (GCD)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L8)
	- [Least Common Multiple (LCM)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L27)
	- [Bézout's Coefficients (using extended Euclid's method)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L33)
	- [Fast Power](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L50)
	- [Modular Inverse](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L80)
	- [Combinations (nCr)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L88)
	- [Pascal Triangle](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L103)
	- [Check Integer Primality](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L113)
	- [Generate Prime Numbers (using Sieve of Eratosthenes' algorithm)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L126)
	- [Generate Divisors (single/bulk operation)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/math.cpp#L143)
		- All divisors
		- Prime divisors
- [Matrix Operations](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/math)
	- [Matrix Class](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/math/matrix.cpp)
	- Matrix Power **<i>(comming soon)</i>**

### Geomerty
Will be added soon...

### Search Algorithms **<i>(comming soon)</i>**
- Binary Search
- Ternary Search

### Sorting Algorithms **<i>(comming soon)</i>**
- Heap Sort 
- Merge Sort
- Quick Sort
- Radix Sort

### Other Algorithms
- K-th Order Statistic **<i>(comming soon)</i>**
- [Longest Increasing Sub-sequence (LIS)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/others/others.cpp)
- [Stress test code](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/others/stress.cpp)
- [Code definitions](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/others/others.cpp)

## Thanks
Special thanks to anyone contributed to this repository:
- By teaching me any of these topics.
- By inspiring me any code optimizations.
- By being supportive.
