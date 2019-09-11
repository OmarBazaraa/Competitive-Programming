#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


/**
 * Edge structs to holds the needed information about an edge.
 */
struct edge {
    int from, to, weight;

    edge() {}
    edge(int f, int t, int w) : from(f), to(t), weight(w) {}

    bool operator<(const edge& rhs) const {
        // Note that we are actually implementing the greater than operator
        // (not the less than operator) to flip the priority queue to min heap
        return weight > rhs.weight;
    }
};

int n;                  // The number of nodes.
int m;                  // The number of edges.
int dis[N];             // dis[v] : holds the shortest distance between the source and node "v".
int par[N];             // par[v] : holds the parent of "v" in the shortest path the source to node "v".
vector<edge> edges[N];  // The graph adjacency list.

/**
 * Computes the shortest path between the given source node and
 * all the other nodes in a weighted graph using the Dijkstra's algorithm,
 * and fills the results in the global "dis" and "par" arrays.
 * (i.e. Single-Source Shortest Path (SSSP))
 * 
 * Complexity: O((n+m)log(n))
 * 
 * @param src the source node.
 */
void dijkstra(int src) {
    priority_queue<edge> q;
    q.push(edge(-1, src, 0));

    memset(par, -1, sizeof(par));
    memset(dis, 0x3F, sizeof(dis));

    while (!q.empty()) {
        int u = q.top().from;
        int v = q.top().to;
        int w = q.top().weight;
        q.pop();

        if (dis[v] <= w) {
            continue;
        }

        dis[v] = w;
        par[v] = u;

        for (edge& e : edges[v]) {
            if (w + e.weight < dis[e.to]) {
                q.push(edge(v, e.to, w + e.weight));
            }
        }
    }
}

/**
 * Prints the shortest path from the source to node "v".
 * This function must not be called before running the Dijkstra's SSSP algorithm.
 *
 * Note that the path is encoded in reverse order,
 * that why we need to print it recursively.
 *
 * @param v the last node in the path.
 */
void printPath(int v) {
    if (~par[v]) {
        printPath(par[v]);
    }

    printf("%d ", v);
}

/**
 * Reads a weighted undirected graph.
 */
void read() {
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back(edge(u, v, w));
        edges[v].push_back(edge(v, u, w));
    }
}