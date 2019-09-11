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
int dep[N];             // dep[i]   : the distance between node "i" and the root of the tree.
int ST[LOG_N][N << 1];  // ST[j][i] : the index of the node with the minimum depth in Euler tour array in range [i, i+(2^j)-1].
int LOG[N << 1];        // LOG[i]   : the floor(log2(i)).
int F[N];               // F[i]     : the index of the first occurrence of the node "i" in Euler array.
vector<int> E;          // E[i]     : the i-th node in Euler tour.


/**
 * Runs an Euler tour on the tree, and fills the global variables
 * in accordance.
 *
 * Do not call this function directly.
 *
 * Complexity: O(n+m)
 *
 * Upon calling this function:
 * @var dep[i] : will hold the depth of node "i".
 * @var E[i]   : will hold the i-th node in the Euler tour.
 * @var F[i]   : will hold the index of the first occurrence of node "i" in Euler array.
 *
 * @param u the root of the current sub-tree.
 * @param p the parent of node "u".
 * @param d the depth or the level of node "u" from the root.
 */
void dfs(int u = 1, int p = -1, int d = 0) {
    dep[u] = d;
    F[u] = E.size();
    E.push_back(u);

    for (int v : edges[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            E.push_back(u);
        }
    }
}

/**
 * Builds the sparse table to hold the index of the node with
 * the minimum depth in Euler tour array.
 *
 * Do not call this function directly.
 *
 * Complexity: O(n.log(n))
 *
 * Upon calling this function:
 * @var LOG[i]   : will hold with floor(log2(i)).
 * @var ST[j][i] : will hold with the index of the node with the minimum depth
 *                 in Euler tour array in range [i, i+(2^j)-1].
 */
void buildRMQ() {
    LOG[0] = -1;

    for (int i = 0; i < E.size(); ++i) {
        ST[0][i] = i;
        LOG[i + 1] = LOG[i] + !(i & (i + 1));
    }

    for (int j = 1; (1 << j) <= E.size(); ++j) {
        for (int i = 0; (i + (1 << j)) <= E.size(); ++i) {
            int x = ST[j - 1][i];
            int y = ST[j - 1][i + (1 << (j - 1))];
            ST[j][i] = (dep[E[x]] < dep[E[y]]) ? x : y;
        }
    }
}

/**
 * Builds the LCA data structure.
 *
 * Complexity: O(n.log(n))
 */
void buildLCA() {
    dfs();
    buildRMQ();
}

/**
 * Queries the sparse table to get the index of the node
 * with the minimum depth in Euler tour array within the given range.
 *
 * Do not call this function directly.
 *
 * Complexity: O(1)
 *
 * @param l the left range.
 * @param r the right range.
 *
 * @return the index of the node with the minimum depth in Euler tour array.
 */
int query(int l, int r) {
    if (l > r) swap(l, r);
    int g = LOG[r - l + 1];
    int x = ST[g][l];
    int y = ST[g][r - (1 << g) + 1];
    return (dep[E[x]] < dep[E[y]]) ? x : y;
}

/**
 * Computes the lowest common ancestor (LCA) of of two nodes.
 *
 * Complexity: O(1)
 *
 * @param u the first node id.
 * @param v the second node id.
 *
 * @return the LCA of node "u" and node "v".
 */
int getLCA(int u, int v) {
    return E[query(F[u], F[v])];
}

/**
 * Computes the distance between two nodes.
 *
 * Complexity: O(1)
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