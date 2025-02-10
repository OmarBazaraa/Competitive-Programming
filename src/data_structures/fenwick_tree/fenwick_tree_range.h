#include "fenwick_tree.h"

/**
 * The `range_fenwick_tree` (a.k.a. Binary Indexed Tree) is a data structure that stores an array of values
 * and can efficiently update values and compute prefix sums.
 * Additional to the normal `fenwick_tree` class, this data structure supports updating a range of values at once.
 *
 * @note
 * The tree is is 1-indexed.
 *
 * @tparam T the type of the elements in the tree.
 * @tparam N the maximum capacity of the tree.
 */
template<typename T, unsigned int N>
class range_fenwick_tree {
    fenwick_tree<T, N> M, C;

public:
    /**
     * Updates a contiguous range of elements in the tree by a specified amount.
     *
     * Time complexity: `O(log(N))`
     *
     * @param l   the starting index of the interval (inclusive).
     * @param r   the ending index of the interval (exclusive).
     * @param val the amount to add to each element in the specified interval `[l, r)`.
     */
    void update(int l, int r, T val) {
        M.update(l, val);
        M.update(r, -val);
        C.update(l, -val * (l - 1));
        C.update(r, val * (r - 1));
    }

    /**
     * Computes the prefix sum of values in the tree up to a specified index.
     *
     * Time complexity: `O(log(N))`
     *
     * @param idx the index of the last element in the prefix sum.
     * @return the sum of values in interval `[1, idx]`.
     */
    T prefix_sum(int idx) {
        return idx * M.prefix_sum(idx) + C.prefix_sum(idx);
    }
};
