#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, k, a[N];

// Partitions the given range of the array into 3 parts
// using the last element (i.e. a[r]) as the pivot:
// [{ elements a[i] <= a[r] }, a[r], { elements a[i] > a[r] }].
// Returns the index of pivot after partitioning.
int partition(int l, int r) {
    int k = l - 1;

    for (int i = l; i <= r; ++i) {
        if (a[i] <= a[r]) {
            swap(a[i], a[++k]);
        }
    }

    return k;
}

// Partitions the given range of the array using random pivot
// and returns the index of pivot after partitioning.
int randomizedPartition(int l, int r) {
    int i = l + rand() % (r - l + 1);
    swap(a[i], a[r]);
    return partition(l, r);
}

// Returns the k-th order statistic (k-th smallest element)
// in the given range of the array.
// Worst Case Complexity:       O(n^2)
// Expected Case Complexity:    O(n)
int getKthOrderStatistic(int k, int l = 0, int r = n - 1) {
    int pivotIdx = randomizedPartition(l, r);

    int leftSize = pivotIdx - l + 1;

    if (k == leftSize) {
        return a[pivotIdx];
    }

    return (k < leftSize) ?
        getKthOrderStatistic(k, l, pivotIdx - 1) :
        getKthOrderStatistic(k - leftSize, pivotIdx + 1, r);
}

// Example driver program
int main() {
    srand(time(0));
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << getKthOrderStatistic(k) << endl;
}