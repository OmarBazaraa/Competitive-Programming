#include <bits/stdc++.h>

using namespace std;

// This is an example of segment tree that calculates and updates the
// sum of values of any contiguous segment in an array in O(log(n)).

// Other problems solved by the segment trees have similar code
// with some modifications.

#define childL(id) (id * 2)
#define childR(id) (id * 2 + 1)

const int N = 100100;

int n, a[N];
int tree[N * 4];
int lazy[N * 4];

// Updates a specific node by the given values.
int updateNode(int v, int id, int l, int r) {
	lazy[id] += v;
	tree[id] += (r - l) * v;
	return tree[id];
}

// Propagates the lazy updated data of the given node down to its children.
void propagate(int id, int l, int r) {
	int mid = (l + r) / 2;

	updateNode(lazy[id], childL(id), l, mid);
	updateNode(lazy[id], childR(id), mid, r);

	lazy[id] = 0;
}

// Builds the segment tree recursively.
// O(n)
int build(int id = 1, int l = 0, int r = n) {
	if (l == r - 1) return tree[id] = a[l];

	int mid = (l + r) / 2;

	return tree[id] = build(childL(id), l, mid) + build(childR(id), mid, r);
}

// Updates the range define by [x, y) by the given value v.
// O(log(n))
int update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
	if (x >= r || y <= l) return tree[id];
	if (x <= l && y >= r) return updateNode(v, id, l, r);

	propagate(id, l, r);

	int mid = (l + r) / 2;

	return tree[id] = update(x, y, v, childL(id), l, mid) + update(x, y, v, childR(id), mid, r);
}

// Queries the segment tree to return the value of the range define by [x, y).
// O(log(n))
int query(int x, int y, int id = 1, int l = 0, int r = n) {
	if (x >= r || y <= l) return 0;
	if (x <= l && y >= r) return tree[id];

	propagate(id, l, r);

	int mid = (l + r) / 2;

	return query(x, y, childL(id), l, mid) + query(x, y, childR(id), mid, r);
}