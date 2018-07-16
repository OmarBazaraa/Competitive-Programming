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
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

fenwick_tree M, C;

// Updates the range from l to r with the given value.
void update(int l, int r, int val) {
    M.update(l, val);
    M.update(r + 1, -val);
    C.update(l, -val * (l - 1));
    C.update(r + 1, val * r);
}

// Returns the sum of values from 1 to the given index.
int get(int idx) {
    return idx * M[idx] + C[idx];
}