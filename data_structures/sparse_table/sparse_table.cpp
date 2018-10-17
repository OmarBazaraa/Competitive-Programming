const int N = 100100, M = 20;

int n, a[N], ST[M][N], LOG[N];

/**
 * Builds sparse table for computing min/max/gcd/lcm/..etc
 * for any contiguous sub-segment of the array.
 * 
 * This is an example of sparse table computing the minimum value.
 * 
 * Complexity: O(n.log(n))
 */
void buildST() {
    LOG[0] = -1;
    for (int i = 0; i < n; ++i) {
        ST[0][i] = i;
        LOG[i + 1] = LOG[i] + !(i & (i - 1));
    }

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; (i + (1 << j)) <= n; ++i) {
            int x = ST[j - 1][i];
            int y = ST[j - 1][i + (1 << (j - 1))];

            ST[j][i] = (a[x] <= a[y] ? x : y);
        }
    }
}

/**
 * Queries the sparse table for the value of the interval from l to r.
 * 
 * Complexity: O(1)
 * 
 * @param l     the left index of the range (inclusive).
 * @param r     the right index of the range (inclusive).
 */
int query(int l, int r) {
    int g = LOG[r - l + 1];
    int x = ST[g][l];
    int y = ST[g][r - (1 << g) + 1];
    return (a[x] <= a[y] ? x : y);
}