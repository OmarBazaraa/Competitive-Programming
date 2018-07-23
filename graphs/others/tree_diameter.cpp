#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

int dis[N];
vector<int> edges[N];

// Returns the farthest node from the given source node,
// and fills the global distance array "dis".
// O(n)
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

// Returns the length of the diameter of the tree.
// (i.e. the length of the longest path in the tree).
// O(n)
int calcTreeDiameter(int root) {
    int u = bfs(root);
    int v = bfs(u);
    return dis[v];
}