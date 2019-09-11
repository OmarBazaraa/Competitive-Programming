#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

// KMP longest match array.
int F[N];

/**
 * KMP failure function.
 *
 * @param pat the pattern string.
 * @param cur the current char to get its failure index.
 * @param len the length of the longest suffix ending at the previous character
 *            matching a prefix of the pattern.
 *
 * @return the length of the longest suffix ending the given character matching a prefix of the pattern.
 */
int failure(const char* pat, char cur, int len) {
    while (len > 0 && cur != pat[len]) {
        len = F[len - 1];
    }
    return len + (cur == pat[len]);
}

/**
 * Computes the length of the longest suffix ending at the i-th character
 * that match a prefix of the string, and fills the results in the global "F" array.
 *
 * Complexity: O(n)
 *
 * @param pat the pattern string to compute its KMP.
 */
void KMP(const char* pat) {
    for (int i = 1; pat[i]; ++i) {
        F[i] = failure(pat, pat[i], F[i - 1]);
    }
}

/**
 * Sample driver program.
 */
int main() {
    string pattern, text;
    cin >> pattern >> text;

    KMP(pattern.c_str());

    int l = 0;

    for (int i = 0; i < text.size(); ++i) {
        l = failure(pattern.c_str(), text[i], l);

        if (l == pattern.size()) {
            cout << "Found substring" << endl;
        }
    }

    return 0;
}