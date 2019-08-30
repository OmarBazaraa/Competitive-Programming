const int N = 100100;

// The total number of sets.
int setsCount;

// DSU related variables. Do not access them directly.
int par[N], siz[N];

/**
 * Initializes the DSU with "n" independent sets.
 * 
 * @param n the number of sets to initialize.
 */
void init(int n) {
	setsCount = n;

	for (int i = 0; i < n; ++i) {
		par[i] = i;
		siz[i] = 1;
	}
}

/**
 * Finds the set id of an element.
 * 
 * @param u the element to find its set.
 * 
 * @return the set id of the given element.
 */
int findSet(int u) {
	return u == par[u] ? u : par[u] = findSet(par[u]);
}

/**
 * Checks whether two elements are in the same set.
 * 
 * @param u the first element.
 * @param v the second element.
 * 
 * @return {@code true} if elements "u" and "v" are in the same set;
 * 		   {@code false} otherwise.
 */
bool sameSet(int u, int v) {
	return findSet(u) == findSet(v);
}

/**
 * Unions two sets together into one set.
 * 
 * @param u an element in the first set.
 * @param v an element in the second set.
 * 
 * @return {@code true} if the set having element "u" is merged with the 
 * 		   set having element "v"; {@code false} if elements "u" and "v" were
 * 		   already in the same set.
 */
bool unionSets(int u, int v) {
	u = findSet(u);
	v = findSet(v);

	if (u == v) {
		return false;
	}
	
	setsCount--;
	siz[v] += siz[u];
	par[u] = v;
	return true;
}

/**
 * Returns the number of elements of a set.
 * 
 * @param u an element in the required set.
 * 
 * @return the size of the set having the given element "u".
 */
int getSetSize(int u) {
	return siz[findSet(u)];
}