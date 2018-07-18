#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


int n;                      // Number of nodes
int m;                      // Number of edges
bool vis[N];                // Visited array to mark whether node u has been visited before or not
vector<int> edges[N];       // Graph adjacency list
vector<int> edgesT[N];		// Transposed graph adjacency list (i.e. the same graph but with reversed edges)
vector<int> sortedNodes;    // List of topologically sorted nodes
vector<vector<int>> scc;	// Strongly connected components

// Sorts the nodes of the given directed graph in a topological order, and
// fills the result in the given (nodes vector) vector but in reversed direction.
void topoSortDFS(int u, vector<int>* edges, vector<int>& nodes) {
	vis[u] = 1;

	for (int v : edges[u]) {
		if (!vis[v]) {
			topoSortDFS(v, edges, nodes);
		}
	}

	nodes.push_back(u);
}

// Extracts the strongly connected components (SCC) of the given directed graph
// using Kosaraju's algorithm, and fills them in the global (scc vector).
void kosaraju() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			topoSortDFS(i, edges, sortedNodes);
		}
	}

	memset(vis, 0, sizeof(vis));
	for (int i = sortedNodes.size() - 1; i >= 0; --i) {
		int u = sortedNodes[i];

		if (!vis[u]) {
			scc.push_back(vector<int>());
			topoSortDFS(u, edgesT, scc.back());
		}
	}
}