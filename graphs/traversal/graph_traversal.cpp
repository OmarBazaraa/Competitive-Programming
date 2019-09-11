#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


int n;                      // Number of nodes.
int m;                      // Number of edges.
bool vis[N];                // Visited array to mark whether node "u" has been visited before or not.
vector<int> edges[N];       // Graph adjacency list.
vector<int> sortedNodes;    // List of topologically sorted nodes.

/**
 * Runs a depth-first search from a given node.
 *
 * @param u the node to start the DFS from.
 */
void dfs(int u) {
    vis[u] = true;

    for (int v : edges[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

/**
 * Runs a breadth-first search from a given node.
 *
 * @param u the node to start the BFS from.
 */
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int v : edges[u]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

/**
 * Sorts all the nodes that are reachable from a given node "u"
 * in a topological order using a DFS algorithm, and fills the result
 * in the global "sortedNodes" vector in reversed direction.
 *
 * This function is to be called for every un-visited node once.
 *
 * Note that it works correctly with Directed Acyclic Graphs (DAGs).
 *
 * Complexity: O(n+m)
 *
 * @param u a node to compute its reachable graph nodes topological order.
 */
void topoSortDFS(int u) {
    vis[u] = true;

    for (int v : edges[u]) {
        if (!vis[v]) {
            topoSortDFS(v);
        }
    }

    sortedNodes.push_back(u);
}

/**
 * Sorts the graph in a topological order using Khan BFS algorithm,
 * and fills the result in the global "sortedNodes" vector.
 *
 * Note that it works correctly with Directed Acyclic Graphs (DAGs).
 *
 * Complexity: O(n+m)
 */
void topoSortBFS() {
    queue<int> q;
    vector<int> inDeg(n + 1, 0);

    // Compute the in degree of each node
    // (i.e. the number of in-edges towards node "u")
    for (int i = 1; i <= n; ++i) {
        for (int v : edges[i]) {
            ++inDeg[v];
        }
    }

    // Push all nodes with zero in degree in the queue
    for (int i = 1; i <= n; ++i) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        sortedNodes.push_back(u);

        for (int v : edges[u]) {
            if (--inDeg[v] == 0) {
                q.push(v);
            }
        }
    }
}

/**
 * Traverses the entire graph.
 * Note that if the graph is connected then a single DFS or BFS will be enough.
 *
 * Complexity: O(n+m)
 */
void traverse() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            // Traverse using one of the following methods
            // Traverse method: DFS, BFS, or TopologicalSortDFS
            // Don't forget to comment the other un-needed methods
            dfs(i);
            bfs(i);
            topoSortDFS(i);
        }
    }
}

/**
 * Reads and constructs the graph.
 */
void read() {
    cin >> n >> m;

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
    }
}