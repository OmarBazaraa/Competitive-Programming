#include<bits/stdc++.h>
using namespace std;

/**
 * B R I D G E   T R E E
 * ---------------------
 *
 * A bridge is an edge that upon removing it the graph will be disconnected.
 *
 * A bridge tree of a graph is a tree formed as follows:
 *
 *  - Remove all the bridges in the graph so that the graph become disconnected.
 *  - Compress all the nodes in a single connected component into a singe node.
 *  - Re-add all the bridges between the compressed nodes.
 */

const int N = 100100;


//
// Global graph variables.
//
int n;                              // The number of nodes.
int m;                              // The number of edges.
vector<int> edges[N];               // The graph adjacency list.

//
// Bridge tree related variables.
//
int T;                              // A timer counter.
int root;                           // A node id in the built bridge tree.
int par[N];                         // The DSU parent array.
int tin[N];                         // tin[u] : the visiting (discovery) time of node "u".
int low[N];                         // low[u] : the earliest visiting time of a vertex that node "u" is reachable from.
vector<int> tree[N];                // The build bridge tree adjacency list.
vector<pair<int, int>> bridges;     // A list of all bridges in the graph.

/**
 * Finds the set id of an element.
 *
 * @param u the element to find its set id.
 *
 * @return the set id of the given element.
 */
int findSetId(int u) {
    return (par[u] == u ? u : par[u] = findSetId(par[u]));
}

/**
 * Finds all the bridges of the graph and inserts them in the
 * global "bridges" vector.
 *
 * Do not call this function directly.
 *
 * Complexity: O(n+m)
 *
 * @param u a node in DFS order.
 * @param p the parent of node "u".
 */
void findBridges(int u = 1, int p = -1) {
    tin[u] = low[u] = ++T;

    for (int v : edges[u]) {
        if (v == p) {
            continue;
        }

        if (tin[v] == 0) {
            findBridges(v, u);

            if (low[v] > tin[u]) {
                bridges.push_back({u, v});
            } else {
                par[findSetId(u)] = findSetId(v);
            }
        }

        low[u] = min(low[u], low[v]);
    }
}

/**
 * Builds the bridge tree of a graph.
 *
 * Complexity: O(n+m)
 */
void buildBridgeTree() {
    // Initialize DSU
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }

    // Find bridges and merge other graph components
    findBridges();

    // Push bridge tree edges
    for (auto& b : bridges) {
        int u = findSetId(b.first);
        int v = findSetId(b.second);

        tree[u].push_back(v);
        tree[v].push_back(u);

        root = u;
    }
}