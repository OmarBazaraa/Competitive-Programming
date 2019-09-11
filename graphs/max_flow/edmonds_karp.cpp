#include <bits/stdc++.h>

using namespace std;


const int N = 105;          // Max number of nodes
const int M = 105;          // Max number of edges


//
// Graph related variables.
//
int n, m;                   // The number of nodes and number of edges
int edgeId;                 // The next edge id to be inserted.
int head[N];                // head[u]     : the id of the last edge added from node "u".
int nxt[M];                 // nxt[e]      : the next edge id pointed from the same node as "e".
int to[M];                  // to[e]       : the id of the node pointed by edge "e".
int capacity[M];            // capacity[e] : the maximum capacity of edge "e".

//
// Max flow related variables.
//
int src, snk;               // the id of source and sink nodes.
int dist[N];                // dist[u]     : the shortest distance between the source and node "u".
int from[N];                // from[u]     : the id of the edge that leads to node "u" in the path from source to sink.
int flow[M];                // flow[u]     : the current flow of edge "e".


/**
 * Initializes the graph.
 * Must be called before each test case.
 */
void init() {
    edgeId = 0;
    memset(head, -1, sizeof(head));
}

/**
 * Adds a new directed edge in the graph from node "f" to node "t"
 * with maximum capacity "c".
 *
 * @param f the source node.
 * @param t the target node.
 * @param c the capacity of the edge.
 */
void addEdge(int f, int t, int c) {
    int e = edgeId++;

    to[e] = t;
    capacity[e] = c;
    flow[e] = 0;

    nxt[e] = head[f];
    head[f] = e;
}

/**
 * Adds a new augmented edge in the graph between node "f" and node "t"
 * with maximum capacity "w".
 *
 * @param f the first node.
 * @param t the second node.
 * @param c the capacity of the edge.
 */
void addAugEdge(int f, int t, int c) {
    addEdge(f, t, c);
    addEdge(t, f, 0);
}

/**
 * Finds a path from the source to the sink while respecting 
 * the constraints on the capacities of the edges.
 * 
 * Do not call this function directly.
 * 
 * Complexity: O(V+E)
 * 
 * @return {@code true} if a path is found; {@code false} otherwise.
 */
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

            if (f >= c) {
                continue;
            }

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                from[v] = e;
                q.push(v);
            }

            if (v == snk) {
                return true;
            }
        }
    }

    return false;
}

/**
 * Augments the previously found path to the flow graph.
 * 
 * Do not call this function directly.
 * 
 * @return the maximum flow of the previously found path.
 */
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

/**
 * Calculates the maximum flow of the graph.
 * 
 * Complexity: O(min(V.E^2, (V+E).MaxFlow))
 * 
 * @return the value of the maximum flow.
 */
int maxFlow() {
    int f = 0;

    while (findPath()) {
        f += augmentPath();
    }

    return f;
}

/**
 * Reads and constructs the graph.
 */
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