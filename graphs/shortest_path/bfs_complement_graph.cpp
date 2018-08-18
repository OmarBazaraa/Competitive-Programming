#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, dis[N], vis[N];
vector<int> edges[N];

// Calculates the shortest path between the given node u and all other nodes
// for the complement of the given unweighted graph,
// and fills the results in the global shortest path "dis" array.
// O(n)
void bfs(int u) {
    queue<int> q;
    q.push(u);
    
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;

    int id = 0;
    list<int> l1, l2;
    memset(vis,  0, sizeof(vis));

    for (int i = 1; i <= n; ++i) {
        if (i != u) {
            l1.push_back(i);
        }
    }

    while (!q.empty()) {
        u = q.front();
        q.pop();
        id++;

        for (int v : edges[u]) {
            if (dis[v] == -1) {
                vis[v] = id;
            }
        }

        for (int v : l1) {
            if (vis[v] == id) {
                l2.push_back(v);
                continue;
            }

            dis[v] = dis[s] + 1;
            q.push(v);
        }

        l1.clear();
        l1.swap(l2);
    }
}