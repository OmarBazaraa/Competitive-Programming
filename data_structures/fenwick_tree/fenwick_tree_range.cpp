const int N = (1 << 17);

int n;

class fenwick_tree {
    int BIT[N];

public:
    fenwick_tree() {
        memset(BIT, 0, sizeof(BIT));
    }

    void update(int idx, int val) {
        while (idx <= n) {
            BIT[idx] += val;
            idx += idx & -idx;
        }
    }

    int operator[](int idx) {
        int res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

class range_fenwick_tree {
    fenwick_tree M, C;

public:
    // Updates the range from l to r with the given value.
    void update(int l, int r, int val) {
        M.update(l, val);
        M.update(r + 1, -val);
        C.update(l, -val * (l - 1));
        C.update(r + 1, val * r);
    }

    // Returns the sum of values from 1 to the given index.
    int operator[](int idx) {
        return idx * M[idx] + C[idx];
    }
};