# Competitive Programming

A C++ code library that contains useful data structures and algorithms tailored for competitive programming contests.

#### PDF Version
[1] You can download an easy printable minified PDF version of this library from [here](docs/Momentum%20Library.pdf).
<br>
[2] You can download *Theoretical Computer Science Cheat Sheet* from [here](docs/Cheat%20Sheet.pdf).

## Content

### Data Structures
- [Sparse Table](src/data_structures/sparse_table)
- [Monotonic Queue](src/data_structures/monotonic_queue)
    - [Implemented with two stacks](src/data_structures/monotonic_queue/monotonic_queue_using_stacks.cpp)
    - [Implemented with double ended queue](src/data_structures/monotonic_queue/monotonic_queue.cpp)
- [Disjoint-Sets (DSU)](src/data_structures/disjoint_sets/)
- [Interval Map](/src/data_structures/interval_map/interval_map.h)
- Trees
    - [Fenwick Tree (Binary Indexed Tree)](src/data_structures/fenwick_tree)
        - [Basic Fenwick Tree](src/data_structures/fenwick_tree/fenwick_tree.cpp)
        - [Fenwick Tree with Range Update](src/data_structures/fenwick_tree/fenwick_tree_range.cpp)
        - [Fenwick Tree as Multiset](src/data_structures/fenwick_tree/fenwick_tree_multiset.cpp)
    - [Segment Tree](src/data_structures/segment_tree)
        - [Basic Segment Tree (static memory allocation)](src/data_structures/segment_tree/segment_tree_static.cpp)
        - [Basic Segment Tree (dynamic memory allocation)](src/data_structures/segment_tree/segment_tree_dynamic.cpp)
        - [Persistent Segment Tree](src/data_structures/segment_tree/persistent_segment_tree.cpp)
        - [Segment Tree as Multiset](src/data_structures/segment_tree/segment_tree_multiset.cpp)
    - [Treap](src/data_structures/treap)
    - Splay Tree **<i>(coming soon)</i>**
- [SQRT Decomposition](src/data_structures/sqrt_decomposition)
    - [Mo's Algorithm](src/data_structures/sqrt_decomposition/mo_algorithm.cpp)

### Strings
- [KMP](src/strings/KMP)
- [Z-Algorithm](src/strings/z_algorithm)
- [Trie](src/strings/trie)
    - [Implemented with static memory allocation](src/strings/trie/trie_static.cpp)
    - [Implemented with dynamic memory allocation](src/strings/trie/trie_dynamic.cpp)
- Suffix Array
    - [Suffix Array O(n.log^2(n))](src/strings/suffix_array/suffix_array_slow.cpp)
    - [Suffix Array O(n.log(n))](src/strings/suffix_array/suffix_array.cpp)
- Aho Corasick's Algorithm **<i>(coming soon)</i>**

### Graphs
- [Graph Traversal and Representation](src/graphs/traversal)
    - [Optimized Representation](src/graphs/traversal/graph_traversal_static.cpp)
    - [DFS](src/graphs/traversal/graph_traversal.cpp#L14)
    - [BFS](src/graphs/traversal/graph_traversal.cpp#L25)
- [Topological Sort](src/graphs/traversal)
    - [DFS](src/graphs/traversal/graph_traversal.cpp#L43)
    - [BFS (Khan's Algorithm)](src/graphs/traversal/graph_traversal.cpp#L59)
- [Shortest Path](src/graphs/shortest_path)
    - Single Source Shortest Path (SSSP)
        - [BFS](src/graphs/shortest_path/bfs.cpp)
        - [BFS on Complement Graph](src/graphs/shortest_path/bfs_complement_graph.cpp)
        - [Dijkstra's Algorithm](src/graphs/shortest_path/dijkstra.cpp)
        - [Bellman Ford's Algorithm](src/graphs/shortest_path/bellman_ford.cpp)
        - [Optimized Bellman Ford's Algorithm](src/graphs/shortest_path/bellman_ford_optimized.cpp)
    - All Pair Shortest Path (APSP)
        - [Floyd Warshal's Algorithm](src/graphs/shortest_path/floyd_warshal.cpp)
- [Minimum Spanning Tree](src/graphs/minimum_spanning_tree)
    - [Kruskal's Algorithm](src/graphs/minimum_spanning_tree/kruskal.cpp)
    - [Prim's Algorithm](src/graphs/minimum_spanning_tree/prim.cpp)
- [Strongly Connected Components (SCC)](src/graphs/strongly_connected_components)
    - [Kosaraju's Algorithm](src/graphs/strongly_connected_components/kosaraju.cpp)
- [Lowest Common Ancestor (LCA)](src/graphs/lowest_common_ancestor)
    - [Implemented with parent sparse table](src/graphs/lowest_common_ancestor/LCA.cpp)
    - [Implemented with Euler walk and RMQ](src/graphs/lowest_common_ancestor/LCA_Euler.cpp)
- [Max Flow](src/graphs/max_flow)
    - [Edmonds-Karp's Algorithm](src/graphs/max_flow/edmonds_karp.cpp)
- [Others](src/graphs/others)
    - [Tree Diameter](src/graphs/others/tree_diameter.cpp)
    - [Bipartite Graph Check](src/graphs/others/bipartite_graph.cpp)
    - [Graph Bridges](src/graphs/others/graph_bridges.cpp)
    - [Bridge Tree](src/graphs/others/bridge_tree.cpp)

### Math
- [Basic Discrete Math & Modular Arithmetics](src/math)
    - [Greatest Common Divisor (GCD)](src/math/math.cpp#L9)
    - [Least Common Multiple (LCM)](src/math/math.cpp#L29)
    - [Bézout's Coefficients (using extended Euclid's method)](src/math/math.cpp#L44)
    - [Fast Power](src/math/math.cpp#L69)
    - [Modular Inverse](src/math/math.cpp#L97)
    - [Combinations (nCr)](src/math/math.cpp#L117)
    - [Combinations (nCr) for Large Numbers](src/math/math.cpp#L139)
    - [Pascal Triangle](src/math/math.cpp#L176)
    - [Check Integer Primality](src/math/math.cpp#L196)
    - [Check Integer Primality using Miller Rabin](src/math/math.cpp#L219)
    - [Generate Prime Numbers (using Sieve of Eratosthenes' algorithm)](src/math/math.cpp#L290)
    - [Generate Divisors (single/bulk operation)](src/math/math.cpp#L315)
        - All divisors
        - Prime divisors
- [Matrix Operations](src/math)
    - [Matrix Class](src/math/matrix.cpp)
    - [Matrix Power](src/math/matrix_minified.cpp)

### Geometry
Will be added soon...

### Search Algorithms
- [Binary Search](src/search/binary_search.cpp)
- [Ternary Search](src/search/ternary_search.cpp)

### Sorting Algorithms **<i>(coming soon)</i>**
- Heap Sort
- Merge Sort
- Quick Sort
- Radix Sort

### Other Algorithms
- [K-th Order Statistic](src/others/kth_order_statistic.cpp)
- [Longest Increasing Sub-sequence (LIS)](src/others/others.cpp)
- [Stress test code](src/others/stress.cpp)
- [Code definitions](src/others/others.cpp)

## Thanks
Special thanks to anyone contributed to this repository:
- By teaching me any of these topics.
- By inspiring me any code optimizations.
- By being supportive.
