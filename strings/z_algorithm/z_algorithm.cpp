#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

// Z-Algorithm longest match array. Don't access it directly
int Z[N];

/**
 * Computes the length of the longest prefix starting at the i-th character
 * that match a prefix of the string, and fills the results in the global "Z" array.
 *
 * Complexity: O(n)
 *
 * @param str the string to apply Z-Algo on.
 */
void z_function(const char* str) {
    for (int i = 1, l = 0, r = 0; str[i]; ++i) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);

        while (str[i + Z[i]] && str[Z[i]] == str[i + Z[i]])
            Z[i]++;

        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }
}