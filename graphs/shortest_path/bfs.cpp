#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n;                  // The number of nodes.
int m;                  // The number of edges.
int dis[N];             // dis[v] : holds the shortest distance between the source and node "v".
int par[N];             // par[v] : holds the parent of "v" in the shortest path the source to node "v".
vector<int> edges[N];   // The graph adjacency list.

/**
 * Computes the shortest path between the given source node and
 * all the other nodes in an unweighted graph using a BFS algorithm,
 * and fills the results in the global "dis" and "par" arrays.
 * (i.e. Single-Source Shortest Path (SSSP))
 * 
 * Complexity: O(n+m)
 * 
 * @param src the source node.
 */
void bfs(int src) {
    queue<int> q;
    q.push(src);

    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    
    dis[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : edges[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

/**
 * Prints the shortest path from the source to node "v".
 * This function must not be called before running the BFS SSSP algorithm.
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