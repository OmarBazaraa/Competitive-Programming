const int N = (1 << 17);    // Must be power of 2

// 1-indexed multiset that stores positive integers only.
class multiset_int {
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
            res += BIT[idx - 1];
            idx -= idx & -idx;
        }
        return res;
    }

public:
    multiset_int() {
        cnt = 0;
        memset(BIT, 0, sizeof(BIT));
    }

    void insert(int val) {
        update(val, 1);
        cnt++;
    }

    void remove(int val) {
        if (count(val) > 0) {
            update(val, -1);
            cnt--;
        }
    }

    int count(int val) {
        return get(val) - get(val - 1);
    }

    int size() {
        return cnt;
    }

    int operator[](int idx) {
        int val = 0;

        for (int len = (N >> 1); len; len >>= 1)
            if (idx > BIT[val + len])
                idx -= BIT[val += len];

        return val + 1;
    }
};