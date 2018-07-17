const int N = 100100;

int z[N];
char s[N];

// Computes the length of the longest prefix starting at the i-th character
// that match a prefix of the string, and fills the results in the global z array.
// O(n)
void z_function() {
    for (int i = 1, l = 0, r = 0; s[i]; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (s[i + z[i]] && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r)
            l = i,
            r = i + z[i] - 1;
    }
}