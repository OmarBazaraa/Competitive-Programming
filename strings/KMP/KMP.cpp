#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

char s[N];

int F[N];

// KMP failure function
int failure(char c, int l) {
    while (l > 0 && c != s[l]) {
        l = F[l - 1];
    }

    return l + (c == s[l]);
}

// Computes the length of the longest suffix ending at the i-th character
// matching a prefix of the string, and fills the results in the global F array.
// O(n)
void KMP() {
    for (int i = 1; s[i]; ++i) {
        F[i] = failure(s[i], F[i - 1]);
    }
}

// Example
// ABCABCABCAAAAB
int main() {
    cin >> s;
    KMP();

    for (int i = 0; s[i]; ++i) {
        cout << F[i] << ' ';
    }

    return 0;
}