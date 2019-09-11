#include <bits/stdc++.h>

using namespace std;

const int N = 100100, LOG_N = 20;


//
// Global graph variables.
//
int n;                  // The number of nodes.
int m;                  // The number of edges.
vector<int> edges[N];   // The graph adjacency list.

//
// LCA related variables.
//
int dep[N];             // dep[i]    : the distance between node "i" and the root of the tree.
int par[LOG_N][N];      // par[j][i] : the (2^j)-th ancestor of node "i".
int LOG[N];             // LOG[i]    : the floor(log2(i)).


/**
 * Runs a depth first traversal on the tree, and fills the global variables
 * in accordance.
 *
 * Do not call this function directly.
 *
 * Complexity: O((n+m).log(n))
 *
 * Upon calling this function:
 * @var dep[i]    : will hold the depth of node "i".
 * @var par[j][i] : will hold the (2^j)-th ancestor of node "i".
 *
 * @param u the root of the current sub-tree.
 * @param p the parent of node "u".
 * @param d the depth or the level of node "u" from the root.
 */
void dfs(int u = 1, int p = -1, int d = 0) {
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
 * Computes the floor of the log of integers from 1 to "n".
 *
 * Do not call this function directly.
 *
 * Complexity: O(n)
 *
 * Upon calling this function:
 * @var LOG[i] : will hold floor(log2(i)).
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
 * Complexity: O(n.log(n))
 */
void buildLCA() {
    dfs();
    computeLog();
}

/**
 * Computes the k-th ancestor of a given node.
 *
 * Complexity: O(log(k))
 *
 * @param u the id of the node to get its k-th ancestor.
 * @param k the order of the ancestor to return.
 *
 * @return the id of the k-th ancestor of node "u".
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
 * Computes the lowest common ancestor (LCA) of of two nodes.
 *
 * Complexity: O(log(n))
 *
 * @param u the first node id.
 * @param v the second node id.
 *
 * @return the LCA of node "u" and node "v".
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
 * Computes the distance between two nodes.
 *
 * Complexity: O(log(n))
 *
 * @param u the first node id.
 * @param v the second node id.
 *
 * @return the distance between node "u" and node "v".
 */
int getDistance(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[getLCA(u, v)];
}

/**
 * Example program.
 *
 * 8 100
 * 1 2
 * 1 3
 * 1 4
 * 2 5
 * 2 6
 * 3 7
 * 5 8
 */
int main() {
    cin >> n >> m;

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    buildLCA();

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", getLCA(u, v));
    }

    return 0;
}