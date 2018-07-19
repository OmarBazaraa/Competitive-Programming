#include <bits/stdc++.h>

using namespace std;

const int N = 100100;


// Struct holds all needed information about the edges
// with comparison operator defined for the sorting.
struct edge {
	int from, to, weight;

	edge() {}
	edge(int f, int t, int w) : from(f), to(t), weight(w) {}

	bool operator<(const edge& rhs) const {
		return (weight < rhs.weight);
	}
};

int n, m;
int par[N];
vector<edge> edges;

// Initializes an n-sets.
void init() {
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
	}
}

// Returns the id the given element u.
int findSet(int u) {
	return u == par[u] ? u : par[u] = findSet(par[u]);
}

// Unions both sets of the given elements u and v.
// Returns false if the two elements were in the same set, true otherwise.
bool unionSets(int u, int v) {
	int x = findSet(u);
	int y = findSet(v);

	if (x == y) {
		return false;
	}

	par[x] = y;
	return true;
}

// Returns the total weight of the minimum spanning tree of the given weighted graph.
// O(n.log(n))
int kruskalMST() {
	init();
	sort(edges.begin(), edges.end());

	int MST = 0;

	for (auto& e : edges) {
		if (unionSets(e.from, e.to)) {
			MST += e.weight;
		}
	}

	return MST;
}

// Reads a weighted undirected graph.
void read() {
	cin >> n >> m;

	while (m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back(edge(u, v, w));
	}
}