#include <bits/stdc++.h>

using namespace std;


const int N = 105;          // Max number of nodes
const int M = 105;          // Max number of edges

int n, m;                   // Number of nodes and number of edges

int edgeId;                 // The next edge id to be inserted
int head[N];                // head[u]      : id of the last edge added from node u
int nxt[M];                 // nxt[e]       : next edge id pointed from the same node as e
int to[M];                  // to[e]        : id of the node pointed by edge e
int capacity[M];            // capacity[e]  : maximum capacity of edge e
int flow[M];                // flow[u]      : current flow of edge e

int src, snk;               // id of source and sink nodes
int dist[N];                // dist[u]      : shortest distance between the source node and node u
int from[N];                // from[u]      : id of the edge that leads to node u in the path from source to sink nodes


// Initializes the graph
void init() {
    edgeId = 0;
    memset(head, -1, sizeof(head));
}

// Adds a new edge from node f to node t with capacity c.
void addEdge(int f, int t, int c) {
    int e = edgeId++;

    to[e] = t;
    capacity[e] = c;
    flow[e] = 0;

    nxt[e] = head[f];
    head[f] = e;
}

// Adds an augmented edge between nodes f and t with capacity c.
void addAugEdge(int f, int t, int c) {
    addEdge(f, t, c);
    addEdge(t, f, 0);
}

// Finds a path from the source node to the sink node while respecting 
// the constraints on the capacities of the edges.
// Returns whether a path is found from src to snk or not.
bool findPath() {
    queue<int> q;
    q.push(src);

    memset(dist, -1, sizeof(dist));
    dist[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int e = head[u]; ~e; e = nxt[e]) {
            int v = to[e];
            int c = capacity[e];
            int f = flow[e];

            if (c <= f) {
                continue;
            }

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                from[v] = e;
                q.push(v);
            }

            if (v == snk) {
                return 1;
            }
        }
    }

    return 0;
}

// Augments the found path to the flow graph.
// Returns the maximum flow of the previously found path.
int augmentPath() {
    int f = INT_MAX;

    // Calculate maximum flow of the found path
    for (int u = snk, e, r; u != src; u = to[r]) {
        e = from[u];    // x ---e--> u
        r = e ^ 1;      // x <--r--- u

        f = min(f, capacity[e] - flow[e]);
    }

    // Augment path
    for (int u = snk, e, r; u != src; u = to[r]) {
        e = from[u];    // x ---e--> u
        r = e ^ 1;      // x <--r--- u

        flow[e] += f;
        flow[r] -= f;   // Reversed edge for flow cancelation
    }

    return f;
}

// Calculates and returns the maximum flow of the given graph.
// O(min(V.E^2, (V+E).MaxFlow))
int maxFlow() {
    int f = 0;

    while (findPath()) {
        f += augmentPath();
    }

    return f;
}

// Reads and constructs the graph (i.e. number of nodes, and the edges).
// O(n)
void read() {
    cin >> n >> m;

    init();

    src = 1, snk = n;

    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        addAugEdge(u, v, c);
    }
}