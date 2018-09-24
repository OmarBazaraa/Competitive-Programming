#include <bits/stdc++.h>

using namespace std;

const int N = 100100, LOG_N = 20;

// dep[i]   : the distance between node i and the root of the tree.
// E[i]     : the i-th node in Euler path.
// F[i]     : the index of the first occurence of the node i in Euler array.
// LOG[i]   : floor(log2(i)).
// ST[j][i] : the index of the node with the minimum depth in Eular tour array in range [i, i+(2^j)-1].
int n, m, u, v, dep[N];
int F[N], ST[LOG_N][N << 1], LOG[N << 1];
vector<int> E, edges[N];

/**
 * Runs an Eular tour on the tree, and fills the global variables
 * with the appropriate values.
 *
 * Upon calling this function:
 * @var dep[i]  will be filled with the depth of node i.
 * @var E[i]    will be filled with the i-th node in the Eular tour.
 * @var F[i]    will be filled with the index of the first occurence of node i in Euler array.
 *
 * Complexity:  O(n)
 *
 * @param u     the root of the current sub-tree.
 * @param p     the parent of node u.
 * @param d     the depth or the level of node u from the root.
 */
void dfs(int u = 1, int p = 0, int d = 0) {
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
 * Builds the spase table to hold the index of the node with
 * the minimum depth in Euler tour array.
 *
 * Upon calling this function:
 * @var LOG[i]      will be filled with floor(log2(i)).
 * @var ST[j][i]    will be filled with the index of the node with the minimum depth
 *                  in Eular tour array in range [i, i+(2^j)-1].
 *
 * Complexity:      O(n.log(n))
 */
void buildRMQ() {
    int i, j, x, y;
    for (i = 0, LOG[0] = -1; i < E.size(); ++i) {
        ST[0][i] = i;
        LOG[i + 1] = LOG[i] + !(i & (i + 1));
    }
    for (j = 1; (1 << j) <= E.size(); ++j) {
        for (i = 0; (i + (1 << j)) <= E.size(); ++i) {
            x = ST[j - 1][i];
            y = ST[j - 1][i + (1 << (j - 1))];
            ST[j][i] = (dep[E[x]] < dep[E[y]]) ? x : y;
        }
    }
}

/**
 * Builds the LCA data structure.
 *
 * Complexity:  O(n.log(n))
 */
void buildLCA() {
    dfs();
    buildRMQ();
}

/**
 * Queries the sparse table to get the index of the node
 * with the minimum depth in Euler tour array within the given range.
 *
 * Complexity:  O(1)
 */
int query(int l, int r) {
    if (l > r) swap(l, r);
    int g = LOG[r - l + 1];
    int x = ST[g][l];
    int y = ST[g][r - (1 << g) + 1];
    return (dep[E[x]] < dep[E[y]]) ? x : y;
}

/**
 * Computes the lowest common ancestor (LCA) of nodes u and v.
 *
 * Complexity:  O(1)
 *
 * @param u     the first node id.
 * @param v     the second node id.
 *
 * @return      the LCA of the given nodes.
 */
int getLCA(int u, int v) {
    return E[query(F[u], F[v])];
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