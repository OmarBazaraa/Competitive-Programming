#include <bits/stdc++.h>

using namespace std;

// The size of the alphabet.
const int ALPA_SIZE = 255;

/**
 * Trie node struct.
 */
struct node {
    node* edges[ALPA_SIZE] = {};
    int wordsCount = 0;     // Number of words sharing this node
    int wordsEndCount = 0;  // Number of words ending at this node
};

/**
 * Trie class to insert, erase, and search for words in time complexity of O(n).
 */
class trie {
    node* root;             // The root of the trie.
    int nodesCount;         // The number of nodes in the trie.
    int distinctWordsCount; // The number of distinct word in the trie.

public:
    /**
     * Constructs a new empty trie.
     */
    trie() {
        root = new node();
        nodesCount = distinctWordsCount = 0;
    }

    /**
     * Destructs this trie.
     */
    ~trie() {
        destroy(root);
    }

    /**
     * Clears and removes all the words in this trie.
     */
    void clear() {
        destroy(root);
        root = new node();
        nodesCount = distinctWordsCount = 0;
    }

    /**
     * Inserts a new word in the trie.
     *
     * @param str the word to insert.
     */
    void insert(const char* str) {
        node* cur = root;

        for (int i = 0; str[i]; ++i) {
            cur->wordsCount++;

            if (cur->edges[str[i]] == NULL) {
                cur->edges[str[i]] = new node();
                nodesCount++;
            }

            cur = cur->edges[str[i]];
        }

        cur->wordsCount++;
        distinctWordsCount += (++cur->wordsEndCount == 1);
    }

    /**
     * Removes a word from the trie assuming that it was added before.
     *
     * @param str the word to erase.
     */
    void remove(const char* str) {
        node* cur = root;

        for (int i = 0; str[i]; ++i) {
            cur->wordsCount--;

            node* nxt = (cur->edges[str[i]]);

            if (nxt->wordsCount == 1) {
                destroy(nxt);
                distinctWordsCount--;
                cur->edges[str[i]] = NULL;
                return;
            }

            cur = nxt;
        }

        cur->wordsCount--;
        cur->wordsEndCount--;
    }

    /**
     * Searches for a word in the trie.
     *
     * @param str the word to search for.
     *
     * @return the number of occurrences of the given word.
     */
    int search(const char* str) const {
        node* cur = reach(str);
        return cur != NULL ? cur->wordsEndCount : 0;
    }

    /**
     * Counts the total number of words added into the trie
     * that start with a given prefix.
     *
     * @param pre the prefix string.
     *
     * @return the number of words in the trie starting with the given prefix.
     */
    int getPrefixCount(const char* pre) const {
        node* cur = reach(pre);
        return cur != NULL ? cur->wordsCount : 0;
    }

    /**
     * Returns the total number of distinct words added into the trie.
     *
     * @return the number of distinct words in the trie.
     */
    int getDistinctWordsCount() const {
        return distinctWordsCount;
    }

private:

    /**
     * Follows the trie to reach the node representing the given string.
     *
     * @param str the string to reach.
     *
     * @return the node representing the given string; or {@code NULL} if not available.
     */
    node* reach(const char* str) const {
        node* cur = root;

        for (int i = 0; str[i]; ++i) {
            node* nxt = cur->edges[str[i]];

            if (nxt == NULL) {
                return NULL;
            }

            cur = nxt;
        }

        return cur;
    }

    /**
     * Clears the given trie and releases the allocated memory.
     *
     * @param root the root of the sub-tree to destroy.
     */
    void destroy(node* root) {
        if (root == NULL) return;
        for (int i = 0; i < ALPA_SIZE; ++i) {
            destroy(root->edges[i]);
        }
        nodesCount--;
        delete root;
    }
};