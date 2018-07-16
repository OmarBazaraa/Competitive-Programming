const int N = (1 << 17);

int n, BIT[N];

// Updates the given index by the given value.
// O(log(n))
void update(int idx, int val) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

// Returns the sum of values from 1 to the given index.
// O(log(n))
int get(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}