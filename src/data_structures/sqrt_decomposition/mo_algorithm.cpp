#include <bits/stdc++.h>

using namespace std;

// Mo's algorithm is a SQRT decomposition algorithm that
// solves some range queries problems offline in O((N+Q).sqrt(N))

// This code is an example of Mo's algorithm that requires
// for each query (L, R) to find the number of distinct values in the array from L to R.

// Other problems solved by Mo's algorithm have essentially similar code.
// What actually need to be changed are function insert and function remove below.

const int N = 100100;   // Max array size
const int Q = 100100;   // Max queries size

int n, m, a[N], cnt[N], ans[N];
int curL, curR, curAns;
int blockSize;

// Mo's query struct
struct query {
    int l, r, i;

    bool operator<(const query& rhs) const {
        if (l / blockSize != rhs.l / blockSize) {
            return l < rhs.l;
        }

        return r < rhs.r;
    }
} queries[Q];

// Inserts the given index into our current answer
void insert(int k) {
    curAns += (++cnt[a[k]] == 1);
}

// Removes the given index from our current answer
void remove(int k) {
    curAns -= (--cnt[a[k]] == 0);
}

// Solves all queries according to Mo's algorithm.
void solveMO() {
    // Set Mo's algorithms variables
    blockSize = sqrt(n) + 1;
    curL = 0, curR = -1, curAns = 0;

    // Sort queries
    sort(queries, queries + m);

    // Solve each query and save its answer
    for (int i = 0; i < m; ++i) {
        query& q = queries[i];

        while (curL < q.l) remove(curL++);
        while (curL > q.l) insert(--curL);
        while (curR < q.r) insert(++curR);
        while (curR > q.r) remove(curR--);

        ans[q.i] = curAns;
    }
}

// Reads problem data and queries
void read() {
    cin >> n >> m;

    // Read problem data
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    // Read problem queries
    for (int i = 0; i < m; ++i) {
        query& q = queries[i];
        q.i = i;
        scanf("%d %d", &q.l, &q.r);
    }
}