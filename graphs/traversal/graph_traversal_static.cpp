#include <bits/stdc++.h>

using namespace std;

const int N = 100100;       // Max number of nodes
const int M = 100100;       // Max number of edges


int n;                      // Number of nodes
int m;                      // Number of edges

int edgeId;                 // Next edge id to be inserted
int head[N];                // head[u]      : id of the last edge added from node u
int nxt[M];                 // nxt[e]       : next edge id pointed from the same node as e
int to[M];                  // to[e]        : id of the node pointed by edge e
int weight[M];              // weight[e]    : weight of edge e

bool vis[N];                // Visited array to mark whether node u has been visited before or not

// Advantages of this graph representation:
// ----------------------------------------
// 1.   Static memory allocation (faster).
//
// 2.   Every edge has an id associated with it.
//      (i.e. lots of possibilities with easier implementation)
//
// 3.   Simplicity of getting the reversed edges.
//      (i.e. reverse(e) = e XOR 1).
//
// 4.   Faster graph clearing during multiple test cases.
//      Clearing the head array is enought instead of 
//      clearing the entire graph.

// Initializes the graph
void init() {
    edgeId = 0;
    memset(head, -1, (n + 1) * sizeof(head[0]));
}

// Adds a new edge from node f to node t with weight w.
void addEdge(int f, int t, int w) {
    int e = edgeId++;

    to[e] = t;
    weight[e] = w;
    
    nxt[e] = head[f];
    head[f] = e;
}

// Adds a bi-directional edge between nodes f and t with weight w.
void addBiEdge(int f, int t, int w) {
    addEdge(f, t, w);
    addEdge(t, f, w);
}

// Depth-First Search from node u
void dfs(int u) {
    vis[u] = true;

    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        int w = weight[k];

        if (!vis[v]) {
            dfs(v);
        }
    }
}

// Reads and constructs the graph (i.e. number of nodes, and the edges).
// O(n)
void read() {
    cin >> n >> m;

    init();

    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addBiEdge(u, v, w);
    }
}