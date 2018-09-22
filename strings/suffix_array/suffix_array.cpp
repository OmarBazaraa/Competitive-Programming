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

// n:           the number of suffixes (length of the string + 1)
// SA:          the suffix array, holding all the suffixes in lexicographical order.
// suffixRank:  array holding the rank (i.e. the order) of the i-th suffix after sorting.
// LCP:         array holding the length of the longest common prefix between SA[i] and SA[i - 1].
int n, SA[N], suffixRank[N], LCP[N];

// Temporary arrays needed while computing the suffix array
int sortedSA[N], sortedRanks[N], rankStart[N];

/**
 * Comparator struct needed to sort the suffixes on the first 2h,
 * given they are already sorted on the first h letters.
 *
 * This struct uses suffixRank array in its comparisons.
 */
struct comparator {
    int h;

    comparator(int h) : h(h) {}

    bool operator()(int i, int j) const {
        if (suffixRank[i] != suffixRank[j])
            return suffixRank[i] < suffixRank[j];
        return suffixRank[i + h] < suffixRank[j + h];
    }
};

/**
 * Computes the ranks of the suffixes in the current sort iteration,
 * and where each of these ranks starts in the suffix array.
 * Also copies the sorted suffixes into the global suffix array (i.e. SA).
 *
 * Upon calling this function:
 * @var suffixRank[i]   will hold the rank (i.e. position) of the i-th suffix in SA.
 * @var rankStart[r]    will hold the first position in SA where rank r appear.
 * @var SA[i]           will hold the new suffix sorting of the current iteration.
 *
 * @param h             the current sort iteration of the suffix array.
 */
void computeSuffixRanks(int h) {
    // Initialize a comparator on the first 2h letters
    comparator comp(h);

    // Compute the new rank of each suffix,
    // and where each of these rank firstly appear in the suffix array
    for (int i = 1; i < n; ++i) {
        int& r = sortedRanks[i] = sortedRanks[i - 1];

        // If the two suffixes differ in their first 2h letters
        // then increment the rank and set its start position
        if (comp(sortedSA[i - 1], sortedSA[i])) {
            rankStart[++r] = i;
        }
    }

    // Copy the sorted suffixes of the h-th iteration in the global suffix array,
    // and re-map ranks into suffixRank array to be indexed by the suffix id
    for (int i = 0; i < n; ++i) {
        SA[i] = sortedSA[i];
        suffixRank[SA[i]] = sortedRanks[i];
    }
}

/**
 * Builds the suffix array of the given string in time complexity of
 * O(n.log(n)), where n is the length of the given string.
 *
 * Upon calling this function:
 * @var SA[i]           will hold the i-th smallest suffix of the string.
 * @var suffixRank[i]   will hold the position of the i-th suffix in
 *                      suffix array (i.e. suffixRank[SA[i]] = i).
 *
 * @param str           the string needed to compute its suffix array.
 */
void buildSuffixArray(const string& str) {
    // Set the number of suffixes
    n = str.size() + 1;

    // Initially fill the suffixes and let their ranks be the first char in each suffix
    for (int i = 0; i < n; ++i) {
        sortedSA[i] = i;
        suffixRank[i] = str[i];
    }

    // Sort suffixes on the first letter and initialize suffix ranks
    sort(sortedSA, sortedSA + n, comparator(0));
    computeSuffixRanks(0);

    // Keep sorting until the number of ranks become equals to the number of suffixes
    for (int h = 1; sortedRanks[n - 1] != n - 1; h <<= 1) {
        // Sort the suffixes on their first 2h letters in a temporary array (i.e. sortedSA),
        // given they are sorted on the first h letters
        for (int i = 0; i < n; ++i) {
            int k = SA[i] - h;

            if (k >= 0) {
                sortedSA[rankStart[suffixRank[k]]++] = k;
            }
        }

        // Compute intial suffix rank, rank start position,
        // and copy the sorted suffix array into the global suffix array
        computeSuffixRanks(h);
    }
}

/**
 * Computes the longest common prefix (LCP) of every two adjacent suffixes in the
 * suffix array.
 *
 * Note that buildSuffixArray(str) must be called before calling this function.
 *
 * Upon calling this function:
 * @var LCP[i]      will hold the length of the LCP between SA[i] and SA[i - 1].
 *
 * @param str       the string needed to compute its longest common prefix array.
 */
void buildLCP(const string& str) {
    int cnt = 0;
    for (int i = 0, k = 0; i < str.size(); ++i) {
        int j = SA[suffixRank[i] - 1];
        while (str[i + cnt] == str[j + cnt]) ++cnt;
        LCP[suffixRank[i]] = cnt;
        if (cnt > 0) --cnt;
    }
}

// Sample driver program
int main() {
    string s;
    cin >> s;

    buildSuffixArray(s);
    buildLCP(s);

    for (int i = 0; i <= s.size(); ++i) {
        cout << SA[i] << ' ' << s.substr(SA[i]) << ' ' << LCP[i] << endl;
    }

    return 0;
}