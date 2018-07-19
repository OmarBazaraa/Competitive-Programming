#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, dis[N], par[N];
vector<int> edges[N];

// Calculates the shortest path between the given node u and all other nodes
// (Single-Source Shortest Path (SSSP)) for the given unweighted graph,
// and fills the results in the global shortest path "dis" array.
// O(n)
void bfs(int u) {
    queue<int> q;
    q.push(u);

    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;

    while (!q.empty()) {
        u = q.front();
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

// Prints the shortest path from node u to node v after running
// the BFS algorithm with node u as the source.
// Note that the path is encoded in reversed order, so we need to print it recursively.
void printPath(int v) {
    if (~par[v]) {
        printPath(par[v]);
    }

    printf("%d ", v);
}