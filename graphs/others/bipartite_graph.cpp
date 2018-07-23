#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

// A Bipartite Graph is a graph whose vertices can be divided into two independent sets: U and V 
// such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U.
// That is, there is no edge that connects vertices of same set.


// color[u] =   { 0     if node u belongs to set U,
//              { 1     if node u belongs to set V

int color[N];
vector<int> edges[N];

// DFS traversal to check whether the given graph is bipartite or not.
// O(n)
bool dfs(int u = 0) {
    for (int v : edges[u]) {
        if (color[v] == -1) {
            color[v] = color[u] ^ 1;

            if (!dfs(v)) {
                return false;
            }
        }
        else if (color[v] == color[u]) {
            return false;
        }
    }

    return true;
}

// Checks whether the given graph is bipartite or not.
// O(n)
bool isBipartiteGraph() {
    memset(color, -1, sizeof(color));
    color[1] = 0;
    return dfs();
}