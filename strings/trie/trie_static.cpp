#include <bits/stdc++.h>

using namespace std;

const int N = 100100, A = 255;

int nodesCount;
int distinctWordsCount;
int trie[N][A];
int wordsCount[N];          // Number of words sharing node "i"
int wordsEndCount[N];       // Number of words ending at node "i"

// Initializes the trie.
void init() {
    nodesCount = 0;
    memset(trie, -1, sizeof(trie));
}

// Adds an edge (of character c) from the given node id if not exists,
// and returns the next node id.
int addEdge(int id, char c) {
    int& nxt = trie[id][c];
    if (nxt == -1) {
        nxt = ++nodesCount;
    }
    return nxt;
}

// Inserts a new word in the trie.
// O(n)
void insert(const char* str) {
    int cur = 0;

    for (int i = 0; str[i]; ++i) {
        wordsCount[cur]++;
        cur = addEdge(cur, str[i]);
    }

    wordsCount[cur]++;
    distinctWordsCount += (++wordsEndCount[cur] == 1);
}

// Removes a word from the trie assuming its existance.
// O(n)
void erase(const char* str) {
    int cur = 0;

    for (int i = 0; str[i]; ++i) {
        int nxt = trie[cur][str[i]];

        if (wordsCount[cur]-- == 1) {
            trie[cur][str[i]] = -1;
        }

        cur = nxt;
    }

    wordsCount[cur]--;
    distinctWordsCount -= (--wordsEndCount[cur] == 0);
}

// Searches for the given word in the trie.
// O(n)
bool search(const char* str) {
    int cur = 0;

    for (int i = 0; str[i]; ++i) {
        int nxt = trie[cur][str[i]];

        if (nxt == -1) {
            return 0;
        }

        cur = nxt;
    }

    return wordsEndCount[cur];
}