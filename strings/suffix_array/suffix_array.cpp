#include <bits/stdc++.h>

using namespace std;

/**
 * S U F F I X   A R R A Y
 * -----------------------
 *
 * A string of length n has (n+1) suffixes.
 * The k-th suffix of a string is its substring starting from the k-th character
 * to the end of that string (i.e. str[k .. n]).
 *
 * Suffix array is an array of all suffixes of a given string sorted
 * in lexicographical order.
 */

// The maximum length of the string
const int N = 1e5 + 5;

// SA:      the suffix array, holding all the suffixes in lexicographical order.
// bucket:  array holding the bucket (i.e. the order) of the i-th suffix after sorting.
int SA[N], bucket[N];

/**
 * Comparator struct needed to sort the suffixes on the first 2h,
 * given they are already sorted on the first h letters.
 *
 * This struct uses bucket array in its comparisons.
 */
struct comparator {
    int h;

    comparator(int h) : h(h) {}

    bool operator()(int i, int j) const {
        if (bucket[i] != bucket[j])
            return bucket[i] < bucket[j];
        return bucket[i + h] < bucket[j + h];
    }
};

/**
 * Builds the suffix array of the given string in time complexity of
 * O(n.log(n)), where n is the length of the given string.
 *
 * Upon calling this function:
 * @var SA[i]       will hold the i-th smallest suffix of the string
 * @var bucket[i]   will hold the position of the i-th suffix in
 *                  suffix array (i.e. bucket[SA[i]] = i)
 *
 * @param str       the string needed to compute its suffix array.
 */
void buildSuffixArray(const string& str) {
    // Number of suffixes
    int n = str.size() + 1;

    // Initially fill the suffixes and let their buckets be the first char in each suffix
    for (int i = 0; i <= n; ++i) {
        SA[i] = i;
        bucket[i] = str[i];
    }

    // Sort suffixes on the first letter
    sort(SA, SA + n, comparator(0));

    // Temporary arrays needed in the following calculations
    vector<int> sortedSA(n, n - 1), sortedBucket(n), bucketStart(n);

    // Keep sorting until the number of buckets become equals to the number of suffixes
    for (int h = 1; sortedBucket[n - 1] != n - 1; h <<= 1) {
        // Compute the new buckets of the previous sorting iteration
        // During the h-th iteration, all the suffixes begin with the the same h letters
        // will be in the same bucket (i.e. have the same bucket id)
        comparator comp(h >> 1);
        for (int i = 1; i < n; ++i) {
            sortedBucket[i] = sortedBucket[i - 1] + comp(SA[i - 1], SA[i]);
        }

        // Compute where each bucket starts,
        // and re-map buckets to be indexed by suffix id
        for (int i = 1; i < n; ++i) {
            bucket[SA[i]] = sortedBucket[i];

            if (sortedBucket[i] > sortedBucket[i - 1]) {
                bucketStart[sortedBucket[i]] = i;
            }
        }

        // Sort the suffixes on their first 2h letters in a temporary array (i.e. sortedSA),
        // given they are sorted on the first h letters
        for (int i = 0; i < n; ++i) {
            int k = SA[i] - h;

            if (k >= 0) {
                sortedSA[bucketStart[bucket[k]]++] = k;
            }
        }

        // Copy the sorted suffix of the h-th iteration in the global suffix array
        for (int i = 0; i < n; ++i) {
            SA[i] = sortedSA[i];
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