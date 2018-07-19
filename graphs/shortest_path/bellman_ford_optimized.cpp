#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, m, dis[N], par[N], inQ[N];
vector<pair<int, int>> edges[N];

// Calculates the shortest path between the given node src and all other nodes
// (Single-Source Shortest Path (SSSP)) for the given weighted graph with negative cycles,
// and fills the results in the global shortest path "dis" array.
// Returns whether the graph contains negative cycles or not.
// Worst case when dense graph:     O(n^2)
// Average case when sparse graph:  O(n) approximately
bool bellmanFord(int src) {
    queue<int> q;
    q.push(src);

    memset(par, -1, sizeof(par));
    memset(dis, 0x3F, sizeof(dis));
    dis[src] = 0;

    for (int k = 0; k < n && !q.empty(); ++k) {
        int siz = q.size();

        while (siz--) {
            int u = q.front();
            q.pop();
            inQ[u] = 0;

            for (auto& e : edges[u]) {
                int v = e.first;
                int w = e.second;

                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    par[v] = u;

                    if (inQ[v] == 0) {
                        inQ[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }

    return (q.size() > 0);
}

// Prints the shortest path from node u to node v after running
// Bellman Ford's algorithm with node u as the source.
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
        edges[u].push_back({ v, w });
        edges[v].push_back({ u, w });
    }
}