#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


int n;                      // Number of nodes
int m;                      // Number of edges
bool vis[N];                // Visited array to mark whether node u has been visited before or not
vector<int> edges[N];       // Graph adjacency list
vector<int> sortedNodes;    // List of topologically sorted nodes

// Depth-First Search from node u
void dfs(int u) {
    vis[u] = true;

    for (int v : edges[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

// Breadth-First Search from node u
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;

    while (!q.empty()) {
        u = q.front();
        q.pop();
        
        for (int v : edges[u]) {
            if (vis[v]++ == 0) {
                q.push(v);
            }
        }
    }
}

// Depth-First Search topological sort from node u.
// Sorts the nodes of the graph in a topological order, and
// fills the result in the global (sortedNodes) vector but in reversed direction.
// Note: Works for DAG
void topoSortDFS(int u) {
    vis[u] = true;

    for (int v : edges[u]) {
        if (!vis[v]) {
            topoSortDFS(v);
        }
    }

    sortedNodes.push_back(u);
}

// Breadth-First Search topological sort using Khan algorithm.
// Sorts the nodes of the graph in a topological order, and
// fills the result in the global (sortedNodes) vector.
// Works for DAG
// O(V+E)
void topoSortBFS() {
    queue<int> q;
    vector<int> inDeg(n + 1, 0);

    // Compute the in degree of each node
    // (i.e. the number of in-edges towards node u)
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

// Traverses the entire graph.
// Note that if the graph is connected then a single DFS or BFS will be enough.
// O(V+E)
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

// Reads and constructs the graph (i.e. number of nodes, and the edges).
// O(n)
void read() {
    cin >> n >> m;

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
    }
}