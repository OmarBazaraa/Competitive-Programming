#include<bits/stdc++.h>
using namespace std;

const int N = 100100;

// n:           total number of vertices in the graph.
// T:           counter represents time.
// root:        node id in the built bridge tree after calling buildBridgeTree().
// par[u]:      the parent array of the DSU data structure.
// tin[u]:      visiting (discovery) time of node u.
// low[u]:      earliest visiting time of a vertex that node u is reachable from.
// edges[u]:    list of out edges of node u in the graph.
// tree[u]:     list of out edges of node u in the built bridge tree after calling buildBridgeTree().
// bridges:     list contains all bridge edges of the graph after calling findBridges().
int n;
int T, root, par[N], tin[N], low[N];
vector<int> edges[N], tree[N];
vector<pair<int, int>> bridges;

// Returns the id the given element u.
int findSet(int u) {
    return (par[u] == u ? u : par[u] = findSet(par[u]));
}

// Unions both sets of the given elements u and v.
void unionSets(int u, int v) {
    par[findSet(u)] = findSet(v);
}

// Finds all the bridges of the given graph and inserts them in the
// global bridges vector.
// Bridge is an edge that upon removing it the graph will become disconnected.
// O(n)
void findBridges(int u = 1, int p = -1) {
    tin[u] = low[u] = ++T;

    for (auto v : edges[u]) {
        if (v == p) {
            continue;
        }

        if (tin[v] == 0) {
            findBridges(v, u);

            if (low[v] > tin[u]) {
                bridges.push_back({ u, v });
            } else {
                unionSets(u, v);
            }
        }

        low[u] = min(low[u], low[v]);
    }
}

// Builds the bridge tree from the given graph.
// O(n)
void buildBridgeTree() {
    // Initialize DSU
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }

    // Find bridges and merge other graph components
    findBridges();

    // Push bridge tree edges
    for (auto& b : bridges) {
        int u = findSet(b.first);
        int v = findSet(b.second);
        
        tree[u].push_back(v);
        tree[v].push_back(u);

        root = u;
    }
}