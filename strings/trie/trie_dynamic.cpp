#include <bits/stdc++.h>

using namespace std;

const int N = 100100, A = 255;

// Trie node struct
struct node {
    node* edges[A] = {};

    int wordsCount = 0;     // Number of words sharing this node
    int wordsEndCount = 0;
};

class trie {
    node* root;

    // Frees up memory recourses of the trie.
    // O(n)
    void free(node* root) {
        if (root == NULL) {
            return;
        }

        for (int i = 0; i < A; ++i) {
            free(root->edges[i]);
        }

        delete root;
    }

public:
    int nodesCount;
    int distinctWordsCount;

    // Constructor.
    trie() {
        root = new node();
        nodesCount = 0;
        distinctWordsCount = 0;
    }

    // Destructor.
    ~trie() {
        free(root);
    }

    // Inserts a new word in the trie.
    // O(n)
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

    // Removes a word from the trie if exists.
    // O(n)
    void remove(const char* str) {
        if (!search(str)) {
            return 0;
        }

        node* cur = root;

        for (int i = 0; str[i]; ++i) {
            cur->wordsCount--;
            cur = cur->edges[str[i]];
        }

        cur->wordsCount--;
        distinctWordsCount -= (--cur->wordsEndCount == 0);
    }

    // Searches for the given word in the trie.
    // O(n)
    bool search(const char* str) {
        node* cur = root;

        for (int i = 0; str[i]; ++i) {
            if (cur->edges[str[i]] == NULL) {
                return 0;
            }

            cur = cur->edges[str[i]];
        }

        return cur->wordsEndCount;
    }

    // Clears the trie and removes all the inserted words.
    // O(n)
    void clear() {
        free(root);
        root = new node();
        nodesCount = 0;
        distinctWordsCount = 0;
    }
};

// Example
int main() {
    trie t;

    t.insert("ABC");
    t.insert("ABD");
    t.insert("AABC");
    t.insert("ABC");

    printf("Trie nodes count: \t\t%d\n", t.nodesCount);
    printf("Trie distinct words count: \t%d\n\n", t.distinctWordsCount);
    
    printf("Trie(ABC): \t%d\n", t.search("ABC"));
    printf("Trie(AABC): \t%d\n", t.search("AABC"));
    printf("Trie(AB): \t%d\n", t.search("AB"));
    printf("Trie(ABY): \t%d\n", t.search("ABY"));

    t.clear();

    return 0;
}