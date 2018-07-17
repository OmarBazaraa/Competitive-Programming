const int N = 100100;

int setsCount;
int par[N], siz[N];

// Initializes an n-sets.
void init(int n) {
	setsCount = n;

	for (int i = 0; i < n; ++i) {
		par[i] = i;
		siz[i] = 1;
	}
}

// Returns the id the given element u.
int findSet(int u) {
	return u == par[u] ? u : par[u] = findSet(par[u]);
}

// Checks if the given elements u and v are in the same set or not.
bool sameSet(int u, int v) {
	return findSet(u) == findSet(v);
}

// Unions both sets of the given elements u and v.
void unionSets(int u, int v) {
	int x = findSet(u);
	int y = findSet(v);

	if (x != y) {
		setsCount--;
		siz[y] += siz[x];
		par[x] = y;
	}
}

// Returns the size of the set of the given element u.
int getSetSize(int u) {
	return siz[findSet(u)];
}