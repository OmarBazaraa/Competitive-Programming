# Competitive Programming

C++ code library contains useful algorithms for competitive programming.

#### PDF Version
[1] You can download an easy printable minified PDF version of this library from [here](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/docs/Momentum%20Library.pdf).

[2] You can download *Theoretical Computer Science Cheat Sheet* from [here](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/docs/Cheat%20Sheet.pdf).

## Content

A brief explanation to each of the following topics will be added soon, hopefully.

### Data Structures
- [Sparse Table](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/data_structures/sparse_table)
- [Monotonic Queue](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/data_structures/monotonic_queue)
	- [Implemented with two stacks](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/monotonic_queue/monotonic_queue_using_stacks.cpp)
	- [Implemented with double ended queue](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/monotonic_queue/monotonic_queue.cpp)
- [Disjoint-Sets Union (DSU)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/data_structures/disjoint_sets_union)
- Trees
	- [Fenwick Tree (Binary Indexed Tree)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/data_structures/fenwick_tree)
		- [Basic Fenwick Tree](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/fenwick_tree/fenwick_tree.cpp)
		- [Fenwick Tree with Range Update](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/fenwick_tree/fenwick_tree_range.cpp)
		- [Fenwick Tree as Multiset](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/fenwick_tree/fenwick_tree_multiset.cpp)
	- [Segment Tree](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/data_structures/segment_tree)
		- [Basic Segment Tree (static memory allocation)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/segment_tree/segment_tree_static.cpp)
		- [Basic Segment Tree (dynamic memory allocation)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/segment_tree/segment_tree_dynamic.cpp)
		- [Persistent Segment Tree](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/segment_tree/persistent_segment_tree.cpp)
		- [Segment Tree as Multiset](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/segment_tree/segment_tree_multiset.cpp)
	- [Treap](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/data_structures/treap)
	- Splay Tree **<i>(comming soon)</i>**
- [SQRT Decomposition](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/data_structures/sqrt_decomposition)
	- [Mo's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/sqrt_decomposition/mo_algorithm.cpp)

### Strings
- [KMP](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/strings/KMP)
- [Z-Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/strings/z_algorithm)
- [Trie](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/strings/trie)
	- [Implemented with static memory allocation](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/strings/trie/trie_static.cpp)
	- [Implemented with dynamic memory allocation](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/strings/trie/trie_dynamic.cpp)
- Suffix Array
	- [Suffix Array O(n.log^2(n))](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/strings/suffix_array/suffix_array_slow.cpp)
	- [Suffix Array O(n.log(n))](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/strings/suffix_array/suffix_array.cpp)
- Aho Corasick's Algorithm **<i>(comming soon)</i>**

### Graphs
- [Graph Traversal and Representation](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/traversal)
	- [Optimized Representation](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/traversal/graph_traversal_static.cpp)
	- [DFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/traversal/graph_traversal.cpp#L14)
	- [BFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/traversal/graph_traversal.cpp#L25)
- [Topological Sort](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/traversal)
	- [DFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/traversal/graph_traversal.cpp#L43)
	- [BFS (Khan's Algorithm)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/traversal/graph_traversal.cpp#L59)
- [Shortest Path](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/shortest_path)
	- Single Source Shortest Path (SSSP)
		- [BFS](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/shortest_path/bfs.cpp)
		- [BFS on Complement Graph](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/shortest_path/bfs_complement_graph.cpp)
		- [Dijkstra's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/shortest_path/dijkstra.cpp)
		- [Bellman Ford's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/shortest_path/bellman_ford.cpp)
		- [Optimized Bellman Ford's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/shortest_path/bellman_ford_optimized.cpp)
	- All Pair Shortest Path (APSP)
		- [Floyd Warshal's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/shortest_path/floyd_warshal.cpp)
- [Minimum Spanning Tree](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/minimum_spanning_tree)
	- [Kruskal's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/minimum_spanning_tree/kruskal.cpp)
	- [Prim's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/minimum_spanning_tree/prim.cpp)
- [Strongly Connected Components (SCC)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/strongly_connected_components)
	- [Kosaraju's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/strongly_connected_components/kosaraju.cpp)
- [Lowest Common Ancestor (LCA)](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/lowest_common_ancestor)
	- [Implemented with parent sparse table](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/lowest_common_ancestor/LCA.cpp)
	- [Implemented with Euler walk and RMQ](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/lowest_common_ancestor/LCA_Euler.cpp)
- [Max Flow](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/max_flow)
	- [Edmonds-Karp's Algorithm](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/max_flow/edmonds_karp.cpp)
- [Others](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/graphs/others)
	- [Tree Diameter](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/others/tree_diameter.cpp)
	- [Bipartite Graph Check](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/others/bipartite_graph.cpp)
	- [Graph Bridges](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/others/graph_bridges.cpp)
	- [Bridge Tree](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/graphs/others/bridge_tree.cpp)

### Math
- [Basic Discrete Math & Modular Arithmetics](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/math)
	- [Greatest Common Divisor (GCD)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L9)
	- [Least Common Multiple (LCM)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L29)
	- [Bézout's Coefficients (using extended Euclid's method)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L44)
	- [Fast Power](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L69)
	- [Modular Inverse](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L97)
	- [Combinations (nCr)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L117)
	- [Combinations (nCr) for Large Numbers](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L139)
	- [Pascal Triangle](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L176)
	- [Check Integer Primality](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L196)
	- [Check Integer Primality using Miller Rabin](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L219)
	- [Generate Prime Numbers (using Sieve of Eratosthenes' algorithm)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L290)
	- [Generate Divisors (single/bulk operation)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp#L315)
		- All divisors
		- Prime divisors
- [Matrix Operations](https://github.com/OmarBazaraa/Competitive-Programming/tree/master/src/math)
	- [Matrix Class](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/matrix.cpp)
	- [Matrix Power](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/matrix_minified.cpp)

### Geomerty
Will be added soon...

### Search Algorithms
- [Binary Search](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/search/binary_search.cpp)
- [Ternary Search](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/search/ternary_search.cpp)

### Sorting Algorithms **<i>(comming soon)</i>**
- Heap Sort
- Merge Sort
- Quick Sort
- Radix Sort

### Other Algorithms
- [K-th Order Statistic](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/others/kth_order_statistic.cpp)
- [Longest Increasing Sub-sequence (LIS)](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/others/others.cpp)
- [Stress test code](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/others/stress.cpp)
- [Code definitions](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/others/others.cpp)

## Thanks
Special thanks to anyone contributed to this repository:
- By teaching me any of these topics.
- By inspiring me any code optimizations.
- By being supportive.
