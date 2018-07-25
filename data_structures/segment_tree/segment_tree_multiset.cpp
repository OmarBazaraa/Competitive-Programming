#include <bits/stdc++.h>

using namespace std;

const int N = 1e9;

// Segment tree node struct
struct node {
    int size;
    node *childL, *childR;

    node() {
        size = 0;
        childL = childR = this;
    }

    node(int s, node* l, node* r) {
        size = s;
        childL = l;
        childR = r;
    }

    void update() {
        size = childL->size + childR->size;
    }
};

// 0-indexed multiset that stores integers in range of [-N, N].
class segment_multiset {
    node *nil, *root;

public:
    // Default constructor.
    segment_multiset() {
        root = nil = new node();
    }

    // Destructor
    ~segment_multiset() {
        clear();
        delete nil;
    }

    // Clears all the inserted elements from the multiset.
    void clear() {
        destroy(root);
        root = nil;
    }

    // Returns the total number of integers in the multiset.
    int size() {
        return root->size;
    }

    // Returns the number of occurrence of the given integer in the multiset.
    int count(int val) {
        node* cur = root;
        int l = -N, r = N;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (val <= mid) {
                cur = cur->childL;
                r = mid;
            } else {
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return cur->size;
    }

    // Inserts a new integer value to the multiset.
    void insert(int val, int cnt = 1) {
        assert(cnt > 0);
        insert(root, val, cnt, -N, N);
    }

    // Erases "cnt" occurances of the given integer from the multiset if exists.
    // Returns the number of deleted elements.
    int erase(int val, int cnt = 1) {
        assert(cnt > 0);
        return erase(root, val, cnt, -N, N);
    }

    // Returns integer from the multiset by its index (0-indexed).
    int operator[](int idx) {
        if (idx < 0 || idx >= root->size) {
            throw out_of_range("ERROR :: trying to access an out of range element");
        }

        node* cur = root;
        int l = -N, r = N;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (idx < cur->childL->size) {
                cur = cur->childL;
                r = mid;
            } else {
                idx -= cur->childL->size;
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return r;
    }

    // Returns the smallest index of an integer with value
    // greater than or equals to the given number.
    // Note that indices are referenced as if all elements are sorted by their value.
    int lower_bound(int val) {
        int ret = 0;

        node* cur = root;
        int l = -N, r = N;

        while (l < val) {
            int mid = l + (r - l) / 2;

            if (val <= mid) {
                cur = cur->childL;
                r = mid;
            } else {
                ret += cur->childL->size;
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return ret;
    }

    // Returns the smallest index of an integer with value
    // greater than to the given number.
    // Note that indices are referenced as if all elements are sorted by their value.
    int upper_bound(int val) {
        return lower_bound(val + 1);
    }

private:

    // Inserts a new integer value to the multiset.
    void insert(node*& root, int val, int cnt, int l, int r) {
        if (val < l || val > r) {
            return;
        }

        if (root == nil) {
            root = new node(0, nil, nil);
        }

        root->size += cnt;

        if (l == r) {
            return;
        }

        int mid = l + (r - l) / 2;

        insert(root->childL, val, cnt, l, mid);
        insert(root->childR, val, cnt, mid + 1, r);
    }

    // Erases "cnt" occurances of the given integer from the multiset if exists.
    // Returns the number of deleted elements.
    int erase(node*& root, int val, int cnt, int l, int r) {
        if (val < l || val > r) {
            return 0;
        }

        if (root == nil) {
            return 0;
        }

        if (l == r) {
            return remove(root, cnt);
        }

        int mid = l + (r - l) / 2;

        int ret = 0;

        ret += erase(root->childL, val, cnt, l, mid);
        ret += erase(root->childR, val, cnt, mid + 1, r);

        return remove(root, ret);        
    }

    // Removes "cnt" occurances of from given root node and destories it if
    // its size become smaller than or equals zero.
    int remove(node*& root, int cnt) {
        int ret = min(cnt, root->size);

        root->size -= cnt;

        if (root->size <= 0) {
            destroy(root);
            root = nil;
        }

        return ret;
    }

    // Clears the given segment tree and releases the allocated memory.
    // O(n)
    void destroy(node* root) {
        if (root == nil) {
            return;
        }

        destroy(root->childL);
        destroy(root->childR);
        delete root;
    }
};