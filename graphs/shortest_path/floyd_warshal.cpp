#include <bits/stdc++.h>

using namespace std;

const int N = 101;

// Assume that:
// ------------
// adj[u][u] = 0
// adj[u][v] = cost(u, v)   when direct edge exists from u to v with cost (u, v)
// adj[u][v] = INF          otherwise
// ----------------------------------------------------
// par[u][v] = u
int n, adj[N][N], par[N][N];

// Initializes the graph adjacent matrix
void init() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = (i == j ? 0 : 1e9),
            par[i][j] = i;
}

// Finds the shortest path between any pair of nodes in the given graph
// and updates the adjacent matrix accordingly by running Floyd Warshall's algorithm.
// O(n^3)
void floyd() {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j],
                    par[i][j] = par[k][j];
}

// Returns whether the graph has negative cycles or not
// by checking the adjacent matrix after running Floyd Warshall's algorithm.
// O(n)
bool checkNegativeCycle() {
    bool ret = false;
    for (int i = 0; i < n; ++i) {
        ret = ret || (adj[i][i] < 0);
    }
    return ret;
}

// Prints the shortest path from node u to node v after running Floyd Warshall's algorithm.
// Note that the path is encoded in reversed order, so we need to print it recursively.
void printPath(int u, int v) {
    if (u != v) {
        printPath(u, par[u][v]);
    }
    
    printf("%d ", v + 1);
}

// Example
// 4 5
// 1 3 -2
// 2 1 4
// 2 3 3
// 3 4 2
// 4 2 -1
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