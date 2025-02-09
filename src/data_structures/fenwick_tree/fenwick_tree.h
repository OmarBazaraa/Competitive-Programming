#include <vector>

/**
 * The `fenwick_tree` (a.k.a. Binary Indexed Tree) is a data structure that stores an array of values
 * and can efficiently update values and compute prefix sums.
 *
 * @note
 * The tree is is 1-indexed.
 *
 * @tparam T the type of the elements in the tree.
 * @tparam N the maximum capacity of the tree.
 */
template<typename T, unsigned int N>
class fenwick_tree {
    int BIT[N + 1];

public:
    /**
	 * Constructs a new object of the `fenwick_tree` class with a fixed capacity.
     *
     * Time complexity: `O(N)`.
	 */
    fenwick_tree() {
        memset(BIT, 0, sizeof(BIT));
    }

    /**
     * Updates the value of a specified element in the tree by a given amount.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param idx the index of the element to update. Should be in the range of `[1, N]`.
     * @param val the amount to add to the specified element.
     */
    void update(int idx, T val) {
        while (idx <= N) {
            BIT[idx] += val;
            idx += idx & -idx;
        }
    }

    /**
     * Computes the prefix sum of values in the tree up to a specified index.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param idx the index of the last element in the prefix sum.
     * @return the sum of values in the interval `[1, idx]`.
     */
    T prefix_sum(int idx) const {
        T res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};
