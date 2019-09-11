#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


/**
 * Edge structs to holds the needed information about an edge.
 */
struct edge {
	int from, to, weight;

	edge() {}
	edge(int f, int t, int w) : from(f), to(t), weight(w) {}

	bool operator<(const edge& rhs) const {
		return (weight < rhs.weight);
	}
};


int n;                  // The number of nodes.
int m;                  // The number of edges.
int par[N];             // The DSU parent array.
vector<edge> edges;		// The edges of the graph.

/**
 * Finds the set id of an element.
 *
 * @param u the element to find its set id.
 *
 * @return the set id of the given element.
 */
int findSetId(int u) {
	return u == par[u] ? u : par[u] = findSetId(par[u]);
}

/**
 * Computes the minimum spanning tree of a weighted graph.
 * 
 * Complexity: O(n.log(n))
 * 
 * @return the total weight of the edges in the minimum spanning tree.
 */
int kruskalMST() {
	int MST = 0;

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; ++i) {
		par[i] = i;
	}

	for (auto& e : edges) {
		int x = findSetId(e.from);
		int y = findSetId(e.to);

		if (x != y) {
			par[x] = y;
			MST += e.weight;
		}
	}

	return MST;
}

/**
 * Reads a weighted undirected graph.
 */
void read() {
	cin >> n >> m;

	while (m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back(edge(u, v, w));
	}
}