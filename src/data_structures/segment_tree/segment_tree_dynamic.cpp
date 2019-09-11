#include <bits/stdc++.h>

using namespace std;

// This is an example of segment tree that calculates and updates the
// sum of values of any contiguous segment in an array in O(log(n)).

// Other problems solved by the segment trees have similar code
// with some modifications.

struct node;

const int N = 100100;

int n, a[N];
node *nil, *root;

// Segment tree node struct
struct node {
    int data, lazy;
    node *childL, *childR;

    node() {
        data = lazy = 0;
        childL = childR = this;
    }

    node(int val, node* l = nil, node* r = nil) {
        data = val, lazy = 0;
        childL = l;
        childR = r;
    }

    // Propagates the lazy updated data of this node down to its children.
    void propagate(int l, int r) {
        int mid = (l + r) / 2;

        childL->update(lazy, l, mid);
        childR->update(lazy, mid, r);

        lazy = 0;
    }

    // Updates the node by the given values.
    int update(int v, int l, int r) {
        lazy += v;
        data += (r - l) * v;
        return data;
    }
};

// Builds the segment tree recursively.
// O(n)
node* build(int l = 0, int r = n) {
    if (l == r - 1) return new node(a[l]);

    int mid = (l + r) / 2;

    node* childL = build(l, mid);
    node* childR = build(mid, r);

    return new node(childL->data + childR->data, childL, childR);
}

// Updates the range define by [x, y) by the given value v.
// O(log(n))
int update(int x, int y, int v, node* root = ::root, int l = 0, int r = n) {
    if (x >= r || y <= l) return root->data;
    if (x <= l && y >= r) return root->update(v, l, r);

    root->propagate(l, r);

    int mid = (l + r) / 2;

    return root->data = update(x, y, v, root->childL, l, mid) + update(x, y, v, root->childR, mid, r);
}

// Queries the segment tree to return the value of the range define by [x, y).
// O(log(n))
int query(int x, int y, node* root = ::root, int l = 0, int r = n) {
    if (x >= r || y <= l) return 0;
    if (x <= l && y >= r) return root->data;

    root->propagate(l, r);

    int mid = (l + r) / 2;

    return query(x, y, root->childL, l, mid) + query(x, y, root->childR, mid, r);
}

// Initializes the segment tree.
// O(n)
void init() {
    nil = new node();
    root = build();
}

// Clears the given segment tree and releases the allocated memory.
// O(n)
void destroy(node* root = ::root) {
    if (root == nil) {
        return;
    }

    destroy(root->childL);
    destroy(root->childR);
    delete root;
}

// Example
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    init();

    while (1) {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r) << endl;
    }

    destroy(root);
    return 0;
}