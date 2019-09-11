#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


int n;                              // The number of nodes.
int m;                              // The number of edges.
int dis[N];                         // dis[v] : holds the shortest distance between the source and node "v".
int par[N];                         // par[v] : holds the parent of "v" in the shortest path the source to node "v".
vector<pair<int, int>> edges[N];    // The graph adjacency list.

/**
 * Computes the shortest path between the given source node and
 * all the other nodes in a weighted graph using the Bellman Ford's algorithm,
 * and fills the results in the global "dis" and "par" arrays.
 * (i.e. Single-Source Shortest Path (SSSP))
 * 
 * Complexity: O(n^2)
 * 
 * @param src the source node.
 * 
 * @return {@code true} if the graph contains negative cycles; {@code false} otherwise.
 */
bool bellmanFord(int src) {
    memset(par, -1, sizeof(par));
    memset(dis, 0x3F, sizeof(dis));
    
    dis[src] = 0;

    bool updated = 1;

    for (int k = 0; k < n && updated; ++k) {
        updated = 0;

        for (int u = 1; u <= n; ++u) {
            for (auto& e : edges[u]) {
                int v = e.first;
                int w = e.second;

                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    par[v] = u;
                    updated = 1;
                }
            }
        }
    }

    return updated;
}

/**
 * Prints the shortest path from the source to node "v".
 * This function must not be called before running the Bellman Fords SSSP algorithm.
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
        edges[u].push_back({ v, w });
        edges[v].push_back({ u, w });
    }
}