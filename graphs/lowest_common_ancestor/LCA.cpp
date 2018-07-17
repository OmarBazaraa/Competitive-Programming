#include <bits/stdc++.h>

using namespace std;

const int N = 100100, M = 20;

// ST[i][j] holds the (2^j)-th ancestor of node number i.
// dis[i] holds the distance to reach node i from the root (node 1).
// LOG[i] = floor(log2(i)).
int n, m, u, v, dis[N], ST[N][M], LOG[N];
vector<int> edges[N];

// Computes the floor of the log of integer from 1 to n.
// After calling this function, LOG[i] will be equals to floor(log2(i)).
// O(n)
void computeLog() {
    LOG[0] = -1;
    for (int i = 1; i <= n; ++i) {
        LOG[i] = LOG[i - 1] + !(i & (i - 1));
    }
}

// Depth first traversal on the graph to fill ST[i][j] and dis[i]
// with the appropriate values.
void dfs(int u = 1, int par = 0, int lvl = 0) {
    dis[u] = lvl;
    ST[u][0] = par;

    for (int i = 1; (1 << i) <= lvl; ++i) {
        ST[u][i] = ST[ST[u][i - 1]][i - 1];
    }

    for (int v : edges[u]) {
        if (v != par) {
            dfs(v, u, lvl + 1);
        }
    }
}

// Returns the k-th ancestor of node u.
// O(log(k))
int getAncestor(int u, int k) {
    while (k > 0) {
        int x = k & -k;
        k -= x;
        u = ST[u][LOG[x]];
    }

    return u;
}

// Returns the lowest common ancestor of nodes u and v.
// O(log(n))
int getLCA(int u, int v) {
    if (dis[u] > dis[v]) {
        swap(u, v);
    }

    v = getAncestor(v, dis[v] - dis[u]);

    if (u == v) {
        return u;
    }

    for (int i = LOG[dis[u]]; i >= 0; --i) {
        if (ST[u][i] != ST[v][i]) {
            u = ST[u][i];
            v = ST[v][i];
        }
    }

    return ST[u][0];
}

// Example
int main() {
    cin >> n >> m;

    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    computeLog();
    dfs();

    while (m--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", getLCA(u, v));
    }
}