#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 1010;
const double PI = acos(-1.0);

// Main 8 directions in clockwise order
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// Days of months
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Speeds up IO operations
void boostIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// Returns the length of the longest increasing subsequence of the array.
// O(n.log(n))
int n, a[N];
int getLIS() {
    int len = 0;
    vector<int> LIS(n, INT_MAX);

    for (int i = 0; i < n; ++i) {
        // To get the length of the longest non decreasing subsequence
        // replace function "lower_bound" with "upper_bound"
        int idx = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        LIS[idx] = a[i];
        len = max(len, idx);
    }
    
    return len + 1;
}