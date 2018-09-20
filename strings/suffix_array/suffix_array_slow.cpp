#include <bits/stdc++.h>

using namespace std;

// A string of length n has (n + 1) suffixes.
// The k-th suffix of a string is the substring starting from k-th character
// to the end of that string (i.e. str[k .. n]).
// Suffix array is an array of all suffixes of a given string sorted
// in lexicographical order.

const int N = 10010;

int SA[N];              // Array holding all suffixes in lexicographical order
                        // (i.e. SA[k] = i, where i is the k-th smallest suffix)
int bucket[N];          // Array holding the position (after sorting) of the i-th suffix in SA array
                        // (i.e. bucket[SA[k]] = k)

// Comparator struct needed to sort the suffixes on the first 2h
// given that they are already sorted on the first h letters.
struct comparator {
    int h;

    comparator(int h) : h(h) {}

    bool operator()(int i, int j) const {
        if (bucket[i] != bucket[j])
            return bucket[i] < bucket[j];
        else
            return bucket[i + h] < bucket[j + h];
    }
};

// Builds suffix array in time complexity of n.log^2(n),
// where n is the length of the string.
void buildSuffixArray(const string& str) {
    // Number of suffixes
    int n = str.size() + 1;

    // Fill suffixes and let their bucket be the first char in the suffix
    for (int i = 0; i < n; ++i) {
        SA[i] = i;
        bucket[i] = str[i];
    }

    // Sort suffixes on the first letter
    sort(SA, SA + n, comparator(0));

    // Temporary bucket array needed in the following calculations
    vector<int> sortedBucket(n + 1, 0);

    for (int h = 1; sortedBucket[n - 1] != n - 1; h <<= 1) {
        // Sort on suffixes on the first 2h letters
        // given they are sorted in the first h letters
        sort(SA, SA + n, comparator(h));

        // Compute the new buckets of the suffixes after sorting
        // on the first 2h letters.
        for (int i = 1; i < n; ++i) {
            sortedBucket[i] = sortedBucket[i - 1] + comparator(h)(SA[i - 1], SA[i]);
        }

        // Re-map buckets into bucket array to be accessed by the suffix key
        for (int i = 0; i < n; ++i) {
            bucket[SA[i]] = sortedBucket[i];
        }
    }
}

// Sample driver program
int main() {
    string s;
    cin >> s;

    buildSuffixArray(s);

    for (int i = 0; i <= s.size(); ++i) {
        cout << SA[i] << ' ' << s.substr(SA[i]) << endl;
    }

    return 0;
}