#include <bits/stdc++.h>

using namespace std;

// The maximum limit of the multiset.
// Must be power of two.
const int N = (1 << 17);

/**
 * Multiset that store positive integers in the range of [1, N].
 * The multiset is implemented using Fenwick tree.
 * 
 * Note that the multiset is is 1-indexed.
 * 
 * The most complex function in this class is done in time complexity of O(log(N)).
 */
class fenwick_multiset {
    int cnt, BIT[N + 1];

    void update(int idx, int val) {
        while (idx <= N) {
            BIT[idx] += val;
            idx += idx & -idx;
        }
    }

    int get(int idx) {
        int res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= idx & -idx;
        }
        return res;
    }

public:
    /**
     * Constructs a new Fenwick multiset.
     */
    fenwick_multiset() {
        clear();
    }

    /**
     * Clears and removes all the elements from the multiset.
     */
    void clear() {
        cnt = 0;
        memset(BIT, 0, sizeof(BIT));
    }

    /**
     * Returns the total number of integers stored in the multiset.
     * 
     * @return the size of the multiset.
     */
    int size() {
        return cnt;
    }

    /**
     * Counts the number of occurrence of an integer in the multiset.
     * 
     * @param val the integer to count its occurrences.
     * 
     * @return how many times the given integer is stored in the multiset.
     */
    int count(int val) {
        if (val < 1 || val > N) {
            return 0;
        }
        return get(val) - get(val - 1);
    }

    /**
     * Inserts a new integer to the multiset.
     * The value of the inserted integer should be in the range of [1, N].
     * 
     * @param val the integer to insert.
     */
    void insert(int val) {
        update(val, 1);
        cnt++;
    }

    /**
     * Removes one occurrence of an integer from the multiset if exists.
     * 
     * @param val the integer to remove.
     */
    void remove(int val) {
        if (count(val) > 0) {
            update(val, -1);
            cnt--;
        }
    }

    /**
     * Returns an integer from the multiset by its index.
     * Note that the multiset is kept sorted in non-descending order.
     * The index should be in the range of [1, {@link fenwick_multiset#size()}].
     * 
     * @param idx the index of the integer to return.
     * 
     * @return the idx-th smallest integer in the multiset.
     */
    int operator[](int idx) {
        int val = 0;

        for (int len = (N >> 1); len; len >>= 1)
            if (idx > BIT[val + len])
                idx -= BIT[val += len];

        return val + 1;
    }

    /**
     * Returns the index of the first integer with value greater
     * than or equals to the given value.
     * Note that the multiset is kept sorted in non-descending order.
     * 
     * @param val the value to returns its lower bound index.
     * 
     * @return the specified index; or {@code fenwick_multiset#size() + 1}
     *         if such integer does not exist.
     */
    int lower_bound(int val) {
        if (val <= 0)
            return 1;
        if (val >= N)
            return cnt + 1;

        return get(val - 1) + 1;
    }

    /**
     * Returns the index of the first integer with value greater
     * than the given value.
     * Note that the multiset is kept sorted in non-descending order.
     * 
     * @param val the value to returns its upper bound index.
     * 
     * @return the specified index; or {@code fenwick_multiset#size() + 1}
     *         if such integer does not exist.
     */
    int upper_bound(int val) {
        return lower_bound(val + 1);
    }
};