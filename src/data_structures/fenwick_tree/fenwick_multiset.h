#include <vector>

/**
 * The `fenwick_multiset` is a multiset data structure, implemented using a Fenwick tree,
 * and is used to store a collection of possibly repeated integers.
 * The multiset keeps its elements sorted in non-descending order, and besides the regular
 * set operations, it supports finding the k-th smallest element efficiently.
 *
 * @note
 * The multiset is is 1-indexed.
 *
 * @tparam P the power of 2 that represents the maximum capacity of the multiset.
 */
template<unsigned int P>
class fenwick_multiset {
    static const int N = 1 << P;

    int siz;
    int BIT[N + 1];

public:
    /**
     * Constructs a new object of the `fenwick_multiset` class with a fixed capacity.
     *
     * Time complexity: `O(N)`.
     */
    fenwick_multiset() {
        siz = 0;
        memset(BIT, 0, sizeof(BIT));
    }

    /**
     * Clears and removes all elements from the multiset.
     *
     * Time complexity: `O(N)`.
     */
    void clear() {
        siz = 0;
        memset(BIT, 0, sizeof(BIT));
    }

    /**
     * Returns the total number of elements currently stored in the multiset.
     *
     * Time complexity: `O(1)`.
     *
     * @return the size of the multiset.
     */
    int size() const {
        return siz;
    }

    /**
     * Counts the number of occurrences of a specified element in the multiset.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key the element to count its occurrences.
     * @return the number of occurrences of the specified element.
     */
    int count(int key) const {
        if (key < 1 || key > N) {
            return 0;
        }

        return get(key) - get(key - 1);
    }

    /**
     * Inserts a new element to the multiset.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key the element to insert. Should be in the range of [1, N].
     */
    void insert(int key) {
        update(key, 1);
        siz++;
    }

    /**
     * Removes a single occurrence of a specified element from the multiset, if exists.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key the element to remove.
     * @return `true` if the element was removed successfully; `false if the element does not exist.
     */
    bool erase(int key) {
        if (count(key) <= 0) {
            return false;
        }

        update(key, -1);
        siz--;
        return true;
    }

    /**
     * Returns an integer from the multiset by its index.
     *
     * @note
     * The multiset is kept sorted in non-descending order.
     *
     * @param idx the index to return its corresponding element. Should be in the range of `[1, size]`.
     *
     * @return the idx-th smallest integer in the multiset.
     */
    int operator[](int idx) {
        // Note that this methods requires that N is a power of 2.
        int val = 0;

        for (int len = (N >> 1); len > 0; len >>= 1) {
            if (idx > BIT[val + len]) {
                idx -= BIT[val += len];
            }
        }

        return val + 1;
    }

    /**
     * Searches for the index of the first element with a key greater than or equals to a specified key.
     *
     * @note
     * The multiset is kept sorted in non-descending order.
     *
     * @param key the key to search for its lower bound index.
     * @return the lower bound index; or `size + 1` if such element does not exist.
     */
    int lower_bound(int key) const {
        if (key <= 0)
            return 1;

        if (key > N)
            return siz + 1;

        return get(key - 1) + 1;
    }

    /**
     * Searches for the index of the first element with a key greater than a specified key.
     *
     * @note
     * The multiset is kept sorted in non-descending order.
     *
     * @param key the key to search for its upper bound index.
     * @return the upper bound index; or `size + 1` if such element does not exist.
     */
    int upper_bound(int val) const {
        return lower_bound(val + 1);
    }

private:
    void update(int idx, int val) {
        while (idx < N) {
            BIT[idx] += val;
            idx += idx & -idx;
        }
    }

    int get(int idx) const {
        int res = 0;

        while (idx > 0) {
            res += BIT[idx];
            idx -= idx & -idx;
        }

        return res;
    }
};
