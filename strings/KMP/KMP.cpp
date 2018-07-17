#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int f[N];
char s[N];

// KMP failure function
int failure(char c, int l) {
    while (l > 0 && c != s[l]) {
        l = f[l - 1];
    }
    return l + (c == s[l]);
}

// Computes the length of the longest suffix ending at the i-th character
// that match a prefix of the string, and fills the results in the global f array.
// O(n)
void KMP() {
    for (int i = 1; s[i]; ++i) {
        f[i] = failure(s[i], f[i - 1]);
    }
}

// Example
// ABCABCABCAAAAB
int main() {
    cin >> s;
    
    KMP();

    for (int i = 0; s[i]; ++i) {
        cout << f[i];
    }

    cout << endl;

    return 0;
}