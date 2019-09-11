#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


int n;                      // Number of nodes.
int m;                      // Number of edges.
bool vis[N];                // Visited array to mark whether node "u" has been visited before or not.
vector<int> edges[N];       // Graph adjacency list.
vector<int> edgesT[N];		// Transposed graph adjacency list (i.e. the same graph but with reversed edges).
vector<vector<int>> scc;	// Strongly connected components.

/**
 * Sorts all the nodes that are reachable from a given node "u"
 * in a topological order, and fills the result in reversed direction.
 *
 * @param u     a node to compute its reachable graph nodes topological order.
 * @param edges the graph to compute its topological order.
 * @param nodes the vector to ouput the results in.
 */
void topoSortDFS(int u, vector<int>* edges, vector<int>& nodes) {
    vis[u] = 1;

    for (int v : edges[u]) {
        if (!vis[v]) {
            topoSortDFS(v, edges, nodes);
        }
    }

    nodes.push_back(u);
}

/**
 * Extracts the strongly connected components (SCC) of the given directed graph
 * using Kosaraju's algorithm, and fills them in the global "scc" vector".
 */
void kosaraju() {
    vector<int> sortedNodes;

    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            topoSortDFS(i, edges, sortedNodes);
        }
    }

    memset(vis, 0, sizeof(vis));

    for (int i = sortedNodes.size() - 1; i >= 0; --i) {
        int u = sortedNodes[i];

        if (!vis[u]) {
            vector<int> tmp;
            topoSortDFS(u, edgesT, tmp);
            scc.push_back(tmp);
        }
    }
}