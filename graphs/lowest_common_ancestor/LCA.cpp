#include <bits/stdc++.h>

using namespace std;

const int N = 100100, M = 20;

// ST[i][j] = the (2^j)-th ancestor of node number i.
// dis[i]   = the distance to reach node i from the root (node 1).
// LOG[i]   = floor(log2(i)).
int n, m, u, v, dis[N], ST[M][N], LOG[N];
vector<int> edges[N];

// Depth first traversal on the tree to fill ST[i][j] and dis[i] arrays
// with the appropriate values.
// O(n)
void dfs(int u = 1, int par = 0, int lvl = 0) {
    dis[u] = lvl;
    ST[0][u] = par;

    for (int i = 1; (1 << i) <= lvl; ++i) {
        ST[i][u] = ST[i - 1][ST[i - 1][u]];
    }

    for (int v : edges[u]) {
        if (v != par) {
            dfs(v, u, lvl + 1);
        }
    }
}

// Computes the floor of the log of integer from 1 to n.
// After calling this function, LOG[i] will be equals to floor(log2(i)).
// O(n)
void computeLog() {
    LOG[0] = -1;
    for (int i = 1; i <= n; ++i) {
        LOG[i] = LOG[i - 1] + !(i & (i - 1));
    }
}

// Builds the LCA structure.
// O(n.log(n))
void buildLCA() {
    dfs();
    computeLog();
}

// Returns the k-th ancestor of node u.
// O(log(k))
int getAncestor(int u, int k) {
    while (k > 0) {
        int x = k & -k;
        k -= x;
        u = ST[LOG[x]][u];
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
        if (ST[i][u] != ST[i][v]) {
            u = ST[i][u];
            v = ST[i][v];
        }
    }

    return ST[0][u];
}

// Example
// 8 100
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 3 7
// 5 8
int main() {
    cin >> n >> m;

    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    buildLCA();

    while (m--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", getLCA(u, v));
    }

    return 0;
}