#include <bits/stdc++.h>

using namespace std;

const int N = 100100, M = 20;


// E[i] = the i-th node in Euler path.
// L[i] = the level of the i-th node in Euler path (i.e. = dis[E[i]]).
// F[i] = the index of the first occurence of the i-th node in Euler array.
int n, m, u, v, F[N], ST[M][N], LOG[N];
vector<int> E, L, edges[N];

// Depth first traversal on the tree to fill E, L, and F arrays
// with the appropriate values.
// O(n)
void dfs(int u = 1, int par = 0, int lvl = 0) {
    F[u] = E.size();

    E.push_back(u);
    L.push_back(lvl);

    for (int v : edges[u]) {
        if (v != par) {
            dfs(v, u, lvl + 1);
            E.push_back(u);
            L.push_back(lvl);
        }
    }
}

// Computes the floor of the log of integer from 1 to n.
// After calling this function, LOG[i] will be equals to floor(log2(i)).
// O(n)
void computeLog() {
    LOG[0] = -1;
    for (int i = 1; i <= L.size(); ++i) {
        LOG[i] = LOG[i - 1] + !(i & (i - 1));
    }
}

// Builds the spase table to hold the index of the node with
// minimum level in Euler path.
// O(n.log(n))
void buildRMQ() {
    for (int i = 0; i < L.size(); ++i) {
        ST[0][i] = i;
    }

    for (int j = 1; (1 << j) <= L.size(); ++j) {
        for (int i = 0; (i + (1 << j)) <= L.size(); ++i) {
            int x = ST[j - 1][i];
            int y = ST[j - 1][i + (1 << (j - 1))];
            ST[j][i] = (L[x] < L[y]) ? x : y;
        }
    }
}

// Builds the LCA structure.
// O(n.log(n))
void buildLCA() {
    dfs();
    buildRMQ();
    computeLog();
}

// Queries the sparse table to get the index of the node
// with the minimum level in Euler path within the given range.
// O(1)
int query(int l, int r) {
    if (l > r) {
        swap(l, r);
    }

    int g = LOG[r - l + 1];
    int x = ST[g][l];
    int y = ST[g][r - (1 << g) + 1];

    return (L[x] < L[y]) ? x : y;
}

// Returns the lowest common ancestor of nodes u and v.
// O(1)
int getLCA(int u, int v) {
    return E[query(F[u], F[v])];
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