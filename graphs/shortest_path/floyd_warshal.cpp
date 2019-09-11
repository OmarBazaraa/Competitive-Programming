#include <bits/stdc++.h>

using namespace std;

const int N = 505, oo = 1e9;


int n;              // The number of nodes.
int adj[N][N];      // The graph adjacency matrix.
int par[N][N];      // par[u][v] : holds the parent node of "v" in the shortest path from "u" to "v".


/**
 * Initializes the graph.
 * Must be called before each test case.
 */
void init() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = (i == j ? 0 : oo), par[i][j] = i;
}

/**
 * Computes the shortest path between any pair of nodes in the graph
 * and updates the adjacency matrix in accordance by running Floyd Warshall's algorithm.
 * (i.e. All-Pair Shortest Path (APSP))
 *
 * Complexity: O(n^3)
 */
void floyd() {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j], par[i][j] = par[k][j];
}

/**
 * Checks whether the graph has negative cycles or not.
 * This function must not be called before running the Floyd Warshall's algorithm.
 *
 * Complexity: O(n)
 *
 * @return {@code true} if the graph has at least one negative cycle; {@code false} otherwise.
 */
bool checkNegativeCycle() {
    bool ret = false;
    for (int i = 0; i < n; ++i) {
        ret = ret || (adj[i][i] < 0);
    }
    return ret;
}

/**
 * Prints the shortest path from node "u" to node "v".
 * This function must not be called before running the Floyd Warshall's algorithm.
 *
 * Note that the path is encoded in reverse order,
 * that why we need to print it recursively.
 *
 * @param u the first node in the path.
 * @param v the last node in the path.
 */
void printPath(int u, int v) {
    if (u != v) {
        printPath(u, par[u][v]);
    }

    printf("%d ", v + 1);
}

/**
 * Example program.
 * 
 * 4 5
 * 1 3 -2
 * 2 1 4
 * 2 3 3
 * 3 4 2
 * 4 2 -1
 */
int main() {
    // Read number of nodes
    cin >> n;

    // Initializes the graph's adjacent matrix
    init();

    // Read edges
    int m, u, v, w;
    cin >> m;
    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u - 1][v - 1] = w;
    }

    // Compute all-pairs shortest path
    floyd();

    // Print adjacent matrix after running Floyd Warshal's algorithm
    cout << endl << "All-Pairs Shortest Path:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            cout << setw(4) << adj[i][j] << (" \n"[j == n - 1]);
        }
    }
    cout << endl;

    // Read pairs and print their shortest path
    cin >> m;
    while (m--) {
        scanf("%d %d", &u, &v);
        printPath(u - 1, v - 1);
        cout << endl;
    }

    return 0;
}