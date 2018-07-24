#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17);    // Must be power of 2

// 1-indexed multiset that stores positive integers only.
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
    // Default constructor.
    fenwick_multiset() {
        clear();
    }

    // Clears and removes all the elements from the multiset.
    void clear() {
        cnt = 0;
        memset(BIT, 0, sizeof(BIT));
    }

    // Returns the total number of integers in the multiset.
    int size() {
        return cnt;
    }

    // Returns the number of occurrence of the given integer in the multiset.
    int count(int val) {
        if (val < 1 || val > N)
            return 0;

        return get(val) - get(val - 1);
    }

    // Inserts a new integer value x (1 <= x <= N) to the multiset.
    void insert(int val) {
        if (val < 1 || val > N) {
            throw exception("ERROR :: invalid value to insert");
        }

        update(val, 1);
        cnt++;
    }

    // Removes the given integer from the multiset if exists.
    void remove(int val) {
        if (count(val) > 0) {
            update(val, -1);
            cnt--;
        }
    }

    // Returns integer from the multiset by its index.
    // Note that the multiset is 1-indexed.
    int operator[](int idx) {
        if (idx < 1 || idx > cnt) {
            throw out_of_range("ERROR :: trying to access an out of range element");
        }

        int val = 0;

        for (int len = (N >> 1); len; len >>= 1)
            if (idx > BIT[val + len])
                idx -= BIT[val += len];

        return val + 1;
    }

    // Returns the smallest index of an integer with value
    // greater than or equals to the given number.
    // Note that indices are referenced as if all elements are sorted by their value.
    int lower_bound(int val) {
        if (val <= 0)
            return 1;
        if (val >= N)
            return cnt + 1;

        return get(val - 1) + 1;
    }

    // Returns the smallest index of an integer with value
    // greater than to the given number.
    // Note that indices are referenced as if all elements are sorted by their value.
    int upper_bound(int val) {
        return lower_bound(val + 1);
    }
};