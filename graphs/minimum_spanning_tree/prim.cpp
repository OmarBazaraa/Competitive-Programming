#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


/**
 * Edge structs to holds all the needed information about an edge.
 */
struct edge {
    int to, weight;

    edge() {}
    edge(int t, int w) : to(t), weight(w) {}

    bool operator<(const edge& rhs) const {
        // Note that we are actually implementing the greater than operator
        // (not the less than operator) to flip the priority queue to min heap
        return weight > rhs.weight;
    }
};

int n;                  // The number of nodes.
int m;                  // The number of edges.
int vis[N];             // vis[v] : whether node "v" has been visited or not.
vector<edge> edges[N];  // The graph adjacency list.

/**
 * Computes the minimum spanning tree of a weighted graph.
 * 
 * Complexity: O(n.log(n))
 * 
 * @return the total weight of the edges in the minimum spanning tree.
 */
int primMST() {
    priority_queue<edge> q;
    q.push(edge(1, 0));

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

/**
 * Reads a weighted undirected graph.
 */
void read() {
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back(edge(v, w));
        edges[v].push_back(edge(u, w));
    }
}