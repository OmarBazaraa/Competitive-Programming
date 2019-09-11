#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17);

/**
 * Regular Fenwick tree class to compute and update prefix sum in O(log(N)).
 *
 * Note that the tree is is 1-indexed.
 */
template<class T>
class fenwick_tree {
    T BIT[N];

public:

    /**
	 * Constructs a new binary indexed tree.
	 *
	 * @param cap the maximum capacity of the tree.
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
    void update(int idx, T val) {
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
    T operator[](int idx) {
        T res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

/**
 * Fenwick tree class to compute and update range sum in O(log(N)).
 * 
 * Note that the tree is is 1-indexed.
 */
template<class T>
class range_fenwick_tree {
    fenwick_tree<T> M, C;

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
    void update(int l, int r, T val) {
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
    T operator[](int idx) {
        return idx * M[idx] + C[idx];
    }
};