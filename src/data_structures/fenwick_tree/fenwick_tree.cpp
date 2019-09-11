const int N = (1 << 17);

// Binary Indexed Tree (i.e Fenwick Tree).
// Do not access this array directly.
int BIT[N];

/**
 * Updates an element in the Fenwick tree.
 * Note that the tree is 1-indexed.
 * 
 * Complexity: O(log(N))
 * 
 * @param idx the index of the element to be updated.
 * @param val the value to add to the given element.
 */
void update(int idx, int val) {
    while (idx < N) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

/**
 * Computes the prefix sum of values in the Fenwick tree.
 * Note that the tree is 1-indexed.
 * 
 * Complexity: O(log(N))
 * 
 * @param idx the index of the last element in the prefix sum.
 * 
 * @return the sum of values in interval [1, idx].
 */
int get(int idx) {
    int res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= idx & -idx;
    }
    return res;
}