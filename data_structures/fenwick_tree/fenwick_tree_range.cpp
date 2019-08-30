#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17);

/**
 * Regular Fenwick tree class.
 * 
 * Note that the tree is is 1-indexed.
 */
class fenwick_tree {
    int BIT[N];

public:
    /**
     * Constructs a new Fenwick tree.
     */
    fenwick_tree() {
        memset(BIT, 0, sizeof(BIT));
    }

    /**
     * Updates an element in the Fenwick tree.
     * 
     * Complexity: O(log(N))
     * 
     * @param idx the index of the element to be updated.
     * @param val the value to add to the given element.
     */
    void update(int idx, int val) {
        while (idx < N) {
            BIT[idx] += val;
            idx += idx & -idx;
        }
    }

    /**
     * Computes the prefix sum of values in the Fenwick tree.
     * 
     * Complexity: O(log(N))
     * 
     * @param idx the index of the last element in the prefix sum.
     * 
     * @return the sum of values in interval [1, idx].
     */
    int operator[](int idx) {
        int res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

/**
 * Fenwick tree class with range updates.
 * 
 * Note that the tree is is 1-indexed.
 */
class range_fenwick_tree {
    fenwick_tree M, C;

public:
    /**
     * Updates an interval in the Fenwick tree.
     * 
     * Complexity: O(log(N))
     * 
     * @param l   the index of the first element in the interval.
     * @param r   the index of the last element in the interval.
     * @param val the value to add to each element in the given interval [l, r].
     */
    void update(int l, int r, int val) {
        M.update(l, val);
        M.update(r + 1, -val);
        C.update(l, -val * (l - 1));
        C.update(r + 1, val * r);
    }

    /**
     * Computes the prefix sum of values in the Fenwick tree.
     * 
     * Complexity: O(log(N))
     * 
     * @param idx the index of the last element in the prefix sum.
     * 
     * @return the sum of values in interval [1, idx].
     */
    int operator[](int idx) {
        return idx * M[idx] + C[idx];
    }
};