#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

// n:           total number of vertices in the graph.
// T:           counter represents time.
// tin[u]:      visiting (discovery) time of node u.
// low[u]:      earliest visiting time of a vertex that node u is reachable from.
// edges[u]:    list of out edges of node u.
// bridges:     list contains all bridge edges of the graph after calling findBridges().
int n;
int T, tin[N], low[N];
vector<int> edges[N];
vector<pair<int, int>> bridges;

// Finds all the bridges of the given graph and inserts them in the
// global bridges vector.
// Bridge is an edge that upon removing it the graph will become disconnected.
// O(n)
void findBridges(int u = 1, int p = -1) {
    tin[u] = low[u] = ++T;

    for (auto v : edges[u]) {
        if (v == p) {
            continue;
        }

        if (tin[v] == 0) {  // if node v is not visited yet
            findBridges(v, u);

            if (low[v] > tin[u]) {
                bridges.push_back({ u, v });
            }
        }

        low[u] = min(low[u], low[v]);
    }
}