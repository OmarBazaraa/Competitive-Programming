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
 * Worst Case Complexity   : O(n^2)
 * Average Case Complexity : O(n)
 * 
 * @param src the source node.
 * 
 * @return {@code true} if the graph contains negative cycles; {@code false} otherwise.
 */
bool bellmanFord(int src) {
    queue<int> q;
    vector<bool> inQ(n + 1, false);
    q.push(src);

    memset(par, -1, sizeof(par));
    memset(dis, 0x3F, sizeof(dis));

    dis[src] = 0;

    for (int k = 0; k < n && !q.empty(); ++k) {
        int siz = q.size();

        while (siz--) {
            int u = q.front();
            q.pop();
            inQ[u] = false;

            for (auto& e : edges[u]) {
                int v = e.first;
                int w = e.second;

                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    par[v] = u;

                    if (inQ[v]) {
                        continue;
                    }
                    
                    q.push(v);
                    inQ[v] = true;
                }
            }
        }
    }

    return (q.size() > 0);
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