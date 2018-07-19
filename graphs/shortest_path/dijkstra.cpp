#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


// Struct holds all needed information about the edges
// with comparison operator defined for the priority queue sorting.
struct edge {
    int from, to, weight;

    edge() {}
    edge(int f, int t, int w) : from(f), to(t), weight(w) {}

    // Note that we are actually implementing the greater than operator (not the less than operator)
    // as the priority queue is implemented as max heap.
    bool operator<(const edge& rhs) const {
        return weight > rhs.weight;
    }
};

int n, m, dis[N], par[N];
vector<edge> edges[N];

// Calculates the shortest path between the given node src and all other nodes
// (Single-Source Shortest Path (SSSP)) for the given weighted graph,
// and fills the results in the global shortest path "dis" array.
// O(n.log(n))
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

// Prints the shortest path from node u to node v after running
// Dijkstra's algorithm with node u as the source.
// Note that the path is encoded in reversed order, so we need to print it recursively.
void printPath(int v) {
    if (~par[v]) {
        printPath(par[v]);
    }

    printf("%d ", v);
}

// Reads a weighted undirected graph.
void read() {
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back(edge(u, v, w));
        edges[v].push_back(edge(v, u, w));
    }
}