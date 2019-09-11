#include<bits/stdc++.h>

using namespace std;

const int N = 100100;


int dis[N];             // dis[v] : holds the shortest distance between the source and node "v".
vector<int> edges[N];   // The graph adjacency list.

/**
 * Computes the shortest distances from a given source node,
 * and fills the results in the global "dis" array.
 * 
 * Complexity: O(n+m)
 * 
 * @param u the source node.
 * 
 * @return the farthest node from the source node.
 */
int bfs(int u) {
    queue<int> q;
    q.push(u);

    memset(dis, -1, sizeof(dis));
    dis[u] = 0;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (auto v : edges[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    return u;
}

/**
 * Computes the length of the diameter of the tree
 * (i.e. the length of the longest path in the tree).
 * 
 * Complexity: O(n+m)
 */
int calcTreeDiameter(int root) {
    int u = bfs(root);
    int v = bfs(u);
    return dis[v];
}