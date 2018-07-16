const int N = (1 << 17);

int n, BIT[N];

void update(int idx, int val) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int get(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}