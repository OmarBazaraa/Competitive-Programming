#include<bits/stdc++.h>

using namespace std;

/**
 * B I P A R T I T E   G R A P H
 * -----------------------------
 *
 * A bipartite Graph is a graph whose vertices can be divided
 * into two independent sets: U and V,
 * such that every edge (u, v) either connects a vertex
 * from U to V or a vertex from V to U.
 * That is, there is no edge that connects two vertices from same set.
 */

const int N = 100100;


int color[N];           // The color of each node (i.e. which set each node belongs to).
vector<int> edges[N];   // The graph adjacency list.

/**
 * Checks whether the given graph is bipartite or not using a DFS algorithm.
 * Do not call this function directly.
 * 
 * Complexity: O(n+m)
 */
bool dfs(int u = 1) {
    for (int v : edges[u]) {
        if (color[v] == color[u]) {
            return false;
        }

        if (color[v] == -1) {
            color[v] = color[u] ^ 1;

            if (!dfs(v)) {
                return false;
            }
        }
    }

    return true;
}

/**
 * Checks whether the given graph is bipartite or not.
 * 
 * Complexity: O(n+m)
 * 
 * @return {@code true} if the graph is bipartite; {@code false} otherwise.
 */
bool isBipartiteGraph() {
    memset(color, -1, sizeof(color));
    color[1] = 0;
    return dfs();
}