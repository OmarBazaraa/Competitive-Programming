#include<bits/stdc++.h>

using namespace std;

/**
 * B R I D G E
 * -----------
 *
 * A bridge is an edge that upon removing it the graph will be disconnected.
 */

const int N = 100100;

//
// Global graph variables.
//
int n;                              // The number of nodes.
int m;                              // The number of edges.
vector<int> edges[N];               // The graph adjacency list.

//
// Bridges related variables
//
int T;                              // A timer counter.
int tin[N];                         // tin[u] : the visiting (discovery) time of node "u".
int low[N];                         // low[u] : the earliest visiting time of a vertex that node "u" is reachable from.
vector<pair<int, int>> bridges;     // A list of all bridges in the graph.

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
void findBridges(int u, int p = -1) {
    tin[u] = low[u] = ++T;

    for (auto v : edges[u]) {
        if (v == p) {
            continue;
        }

        if (tin[v] == 0) {
            findBridges(v, u);

            if (low[v] > tin[u]) {
                bridges.push_back({u, v});
            }
        }

        low[u] = min(low[u], low[v]);
    }
}

/**
 * Finds all the bridges of the graph and inserts them in the
 * global "bridges" vector.
 *
 * Complexity: O(n+m)
 */
void findBridges() {
    for (int i = 1; i <= n; ++i) {
        if (tin[i] == 0) {
            findBridges(i);
        }
    }
}