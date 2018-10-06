#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int F[N];

/**
 * KMP failure function.
 *
 * @param s     the pattern string.
 * @param c     the next char to get its failure index.
 * @param l     the length of the longest suffix ending at the previous char.
 *
 * @return      the length of the longest suffix ending the given char.
 */
int failure(const char* s, char c, int l) {
    while (l > 0 && c != s[l]) {
        l = F[l - 1];
    }
    return l + (c == s[l]);
}

/**
 * Computes the length of the longest suffix ending at the i-th character
 * that match a prefix of the string, and fills the results in the global F array.
 *
 * Complexity:  O(n)
 *
 * @param s     the pattern string to compute its KMP.
 */
void KMP(const char* s) {
    for (int i = 1; s[i]; ++i) {
        F[i] = failure(s, s[i], F[i - 1]);
    }
}

/**
 * Main driver program
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