#include <bits/stdc++.h>

using namespace std;

// The total length of all the string, and the size of the alphabet.
const int N = 100100, ALPA_SIZE = 255;

int trie[N][ALPA_SIZE];     // The trie.
int nodesCount;             // The number of nodes in the trie.
int distinctWordsCount;     // The number of distinct word in the trie.
int wordsCount[N];          // Number of words sharing node "i"
int wordsEndCount[N];       // Number of words ending at node "i"

/**
 * Initializes the trie.
 * Must be called before each test case.
 */
void init() {
    nodesCount = 0;
    memset(trie, -1, sizeof(trie));
}

/**
 * Outs a new edge from the given node if not exists.
 *
 * @param id the node id to out the edge from
 * @param c  the type (or the character) of the edges.
 *
 * @return the id of the node following the added edge.
 */
int addEdge(int id, char c) {
    int& nxt = trie[id][c];
    if (nxt == -1) {
        nxt = ++nodesCount;
    }
    return nxt;
}

/**
 * Inserts a new word in the trie.
 *
 * Complexity: O(n)
 *
 * @param str the word to insert.
 */
void insert(const char* str) {
    int cur = 0;

    for (int i = 0; str[i]; ++i) {
        wordsCount[cur]++;
        cur = addEdge(cur, str[i]);
    }

    wordsCount[cur]++;
    distinctWordsCount += (++wordsEndCount[cur] == 1);
}

/**
 * Removes a word from the trie assuming that it was added before.
 *
 * Complexity: O(n)
 *
 * @param str the word to erase.
 */
void erase(const char* str) {
    int cur = 0;

    for (int i = 0; str[i]; ++i) {
        wordsCount[cur]--;

        int nxt = trie[cur][str[i]];

        if (wordsCount[nxt] == 1) {
            trie[cur][str[i]] = -1;
        }

        cur = nxt;
    }

    wordsCount[cur]--;
    distinctWordsCount -= (--wordsEndCount[cur] == 0);
}

/**
 * Searches for a word in the trie.
 *
 * Complexity: O(n)
 *
 * @param str the word to search for.
 *
 * @return the number of occurrences of the given word.
 */
int search(const char* str) {
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