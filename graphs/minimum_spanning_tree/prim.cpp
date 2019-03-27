#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


// Struct holds all needed information about the edges
// with comparison operator defined for the priority queue sorting.
struct edge {
    int to, weight;

    edge() {}
    edge(int t, int w) : to(t), weight(w) {}

    // Note that we are actually implementing the greater than operator (not the less than operator)
    // as the priority queue is implemented as max heap.
    bool operator<(const edge& rhs) const {
        return weight > rhs.weight;
    }
};

int n, m;
bool vis[N];
vector<edge> edges[N];

// Returns the total weight of the minimum spanning tree of the given weighted graph.
// O(n.log(n))
int primMST() {
    priority_queue<edge> q;
    q.push(edge(0, 0));

    int MST = 0;

    while (!q.empty()) {
        int u = q.top().to;
        int w = q.top().weight;
        q.pop();

        if (vis[u]++) {
            continue;
        }
        
        MST += w;

        for (edge& e : edges[u]) {
            if (!vis[e.to]) {
                q.push(e);
            }
        }
    }

    return MST;
}

// Reads a weighted undirected graph.
void read() {
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back(edge(v, w));
        edges[v].push_back(edge(u, w));
    }
}