#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

char s[N], p[N];

int F[N];

// KMP failure function
int failure(char c, int l) {
    while (l > 0 && c != p[l]) {
        l = F[l - 1];
    }

    return l + (c == p[l]);
}

// Computes the length of the longest suffix of the given string ending at
// the i-th character matching a prefix of the pattern defined by the failure function,
// and fill the results in the global F array.
// O(n)
void KMP(const char* s) {
    for (int i = 1; s[i]; ++i) {
        F[i] = failure(s[i], F[i - 1]);
    }
}

// Example
int main() {
    cin >> s >> p;
    KMP(s);

    for (int i = 0; s[i]; ++i) {
        cout << F[i] << ' ';
    }

    return 0;
}