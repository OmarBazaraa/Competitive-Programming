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

    // Removes a word from the trie assuming its existance.
    // O(n)
    void remove(const char* str) {
        node* cur = root;

        for (int i = 0; str[i]; ++i) {
            node* nxt = cur->edges[str[i]];
            cur = nxt;
        }

        cur->wordsCount--;
        distinctWordsCount -= (--cur->wordsEndCount == 0);
    }

    // Searches for the given word in the trie.
    // O(n)
    bool search(const char* str) {
        node* cur = root;

        for (int i = 0; str[i]; ++i) {
            node* nxt = cur->edges[str[i]];

            if (nxt == NULL) {
                return 0;
            }

            cur = nxt;
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

    t.remove("ABC");
    cout << t.search("ABC") << endl;

    t.remove("ABC");
    cout << t.search("ABC") << endl;

    t.clear();

    return 0;
}