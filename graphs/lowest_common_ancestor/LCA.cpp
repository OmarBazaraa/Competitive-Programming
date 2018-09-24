#include <bits/stdc++.h>

using namespace std;

const int N = 100100, LOG_N = 20;

// dep[i]       : the distance to reach node i from the root (node 1) (i.e. the depth).
// LOG[i]       : floor(log2(i)).
// par[j][i]    : the (2^j)-th ancestor of node number i.
int n, m, u, v, dep[N];
int par[LOG_N][N], LOG[N];
vector<int> edges[N];


/**
 * Runs a depth first traversal on the tree to fill the global variables
 * with the appropriate values.
 *
 * Upon calling this function:
 * @var dep[i]      will be filled with the depth of node i.
 * @var par[j][i]   will be filled with the (2^j)-th ancestor of node number i.
 *
 * Complexity:      O(n.log(n))
 *
 * @param u         the root of the current sub-tree.
 * @param p         the parent of node u.
 * @param d         the depth or the level of node u from the root.
 */
void dfs(int u = 1, int p = 0, int d = 0) {
    dep[u] = d;
    par[0][u] = p;

    for (int i = 1; (1 << i) <= d; ++i) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }

    for (int v : edges[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

/**
 * Computes the floor of the log of integer from 1 to n.
 *
 * Upon calling this function:
 * @var LOG[i]  will be filled with floor(log2(i)).
 *
 * Complexity:  O(n)
 */
void computeLog() {
    LOG[0] = -1;
    for (int i = 1; i <= n; ++i) {
        LOG[i] = LOG[i - 1] + !(i & (i - 1));
    }
}

/**
 * Builds the LCA data structure.
 *
 * Complexity:  O(n.log(n))
 */
void buildLCA() {
    dfs();
    computeLog();
}

/**
 * Computes the k-th ancestor of the given node.
 *
 * Complexity:  O(log(k))
 *
 * @param u     the id of the node to get its k-th ancestor.
 * @param k     the order of the ancestor to return.
 *
 * @return      the id of the k-th ancestor of node u.
 */
int getAncestor(int u, int k) {
    while (k > 0) {
        int x = k & -k;
        k -= x;
        u = par[LOG[x]][u];
    }

    return u;
}

/**
 * Computes the lowest common ancestor (LCA) of nodes u and v.
 *
 * Complexity:  O(log(n))
 *
 * @param u     the first node id.
 * @param v     the second node id.
 *
 * @return      the LCA of the given nodes.
 */
int getLCA(int u, int v) {
    if (dep[u] > dep[v]) {
        swap(u, v);
    }

    v = getAncestor(v, dep[v] - dep[u]);

    if (u == v) {
        return u;
    }

    for (int i = LOG[dep[u]]; i >= 0; --i) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }

    return par[0][u];
}

/**
 * Computes the distance between the given pair of nodes: u and v.
 *
 * Complexity:  O(1)
 *
 * @param u     the first node id.
 * @param v     the second node id.
 *
 * @return      the distance between the given nodes.
 */
int getDistance(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[getLCA(u, v)];
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