#include <bits/stdc++.h>

using namespace std;

// Treap node struct
struct node {
    int key, priority, size;
    node *childL, *childR;

    node() {
        size = 0;
        childL = childR = this;
    }

    node(int k, node* l, node* r) {
        key = k;
        childL = l;
        childR = r;
        size = 1;
        priority = rand();
    }

    void update() {
        size = childL->size + childR->size + 1;
    }
};

// 0-indexed treap-based multiset.
class treap {
    node *nil, *root;

public:
    // Constructs an emptry treap.
    treap() {
        srand(time(0));
        root = nil = new node();
    }

    // Destructor.
    ~treap() {
        destroy(root);
        delete nil;
    }

    // Clears all the inserted elements from the multiset.
    void clear() {
        destroy(root);
        root = nil;
    }

    // Returns the total number of integers in the multiset.
    int size() {
        return root->size;
    }

    // Returns the number of occurrence of the given integer in the multiset.
    int count(int key) {
        int res = 0;
        node* cur = root;

        while (cur != nil) {
            if (key <= cur->key) {
                res += (key == cur->key);
                cur = cur->childL;
            } else {
                cur = cur->childR;
            }
        }

        return res;
    }

    // Inserts the given element into the given treap.
    void insert(int key) {
        insert(root, new node(key, nil, nil));
    }

    // Erases the given element from the treap if exists.
    bool erase(int key) {
        return erase(root, key);
    }

    // Returns the idx-th node in the given treap.
    // Note that indices are referenced as if all nodes are sorted by their keys.
    int operator[](int idx) {
        node* cur = root;

        while (cur != nil && idx != cur->childL->size) {
            if (idx < cur->childL->size) {
                cur = cur->childL;
            } else {
                idx -= cur->childL->size + 1;
                cur = cur->childR;
            }
        }

        return cur->key;
    }

    // Returns the smallest index of a node with key
    // greater than or equals to the given key.
    // Note that indices are referenced as if all nodes are sorted by their keys.
    int lower_bound(int val) {
        int ret = 0;

        node* cur = root;

        while (cur != nil) {
            if (val <= cur->key) {
                cur = cur->childL;
            } else {
                ret += cur->childL->size + 1;
                cur = cur->childR;
            }
        }

        return ret;
    }

    // Returns the smallest index of a node with key
    // greater than the given key.
    // Note that indices are referenced as if all nodes are sorted by their keys.
    int upper_bound(int key) {
        return lower_bound(key + 1);
    }

private:

    // Inserts a new node into the given treap.
    void insert(node*& root, node* newNode) {
        if (root == nil) {
            root = newNode;
            return;
        }

        if (newNode->priority > root->priority) {
            split(root, newNode->childL, newNode->childR, newNode->key);
            root = newNode;
        } else {
            insert((newNode->key <= root->key) ? root->childL : root->childR, newNode);
        }

        root->update();
    }

    // Erases a single node from the treap having its key matches
    // the given key if exists.
    bool erase(node*& root, int key) {
        if (root == nil) {
            return 0;
        }

        bool ret = 1;

        if (key == root->key) {
            node* temp = root;
            merge(root->childL, root->childR, root);
            delete temp;
        } else {
            ret = erase((key <= root->key) ? root->childL : root->childR, key);
            root->update();
        }   

        return ret;
    }

    // Splits the given treap (root) into two different treaps: rootL and rootR
    // such that L contains all the nodes with values <= key and R contains the other nodes.
    // Note that the original treap will not exist anymore after the split operation.
    // O(log(n))
    void split(node* root, node*& rootL, node*& rootR, int key) {
        if (root == nil) {
            rootL = rootR = nil;
            return;
        }

        if (key >= root->key) {
            rootL = root;
            split(root->childR, rootL->childR, rootR, key);
        } else {
            rootR = root;
            split(root->childL, rootL, rootR->childL, key);
        }

        root->update();
    }

    // Merges the given two treaps rootL and rootR into a single treap (root).
    // Note that the largest value of L must be less than the smallest value of R
    // in order to get a correct merge operation.
    // Note that L and R will not exist anymore after the merge operation.
    // O(log(n))
    void merge(node* rootL, node* rootR, node*& root) {
        if (rootL == nil) {
            root = rootR;
            return;
        }

        if (rootR == nil) {
            root = rootL;
            return;
        }

        if (rootL->priority > rootR->priority) {
            root = rootL;
            merge(rootL->childR, rootR, root->childR);
        } else {
            root = rootR;
            merge(rootL, rootR->childL, root->childL);
        }

        root->update();
    }

    // Clears the given treap and releases the allocated memory.
    // O(n)
    void destroy(node* root) {
        if (root == nil) {
            return;
        }

        destroy(root->childL);
        destroy(root->childR);
        delete root;
    }
};