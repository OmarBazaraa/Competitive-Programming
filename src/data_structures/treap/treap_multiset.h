// Treap node struct
struct treap_node {
    int key, priority, size;
    treap_node *childL, *childR;

    treap_node() {
        size = 0;
        childL = childR = this;
    }

    treap_node(int k, treap_node* l, treap_node* r) {
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
class treap_multiset {
    treap_node *nil, *root;

public:
    // Constructs an emptry treap.
    treap_multiset() {
        srand(time(0));
        root = nil = new treap_node();
    }

    // Destructor.
    ~treap_multiset() {
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
        treap_node* cur = root;

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
        insert(root, new treap_node(key, nil, nil));
    }

    // Erases the given element from the treap if exists.
    bool erase(int key) {
        return erase(root, key);
    }

    // Returns the idx-th node in the given treap.
    // Note that indices are referenced as if all nodes are sorted by their keys.
    int operator[](int idx) {
        treap_node* cur = root;

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

        treap_node* cur = root;

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
    void insert(treap_node*& root, treap_node* newNode) {
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
    bool erase(treap_node*& root, int key) {
        if (root == nil) {
            return 0;
        }

        bool ret = 1;

        if (key == root->key) {
            treap_node* temp = root;
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
    void split(treap_node* root, treap_node*& rootL, treap_node*& rootR, int key) {
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
    void merge(treap_node* rootL, treap_node* rootR, treap_node*& root) {
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
    void destroy(treap_node* root) {
        if (root == nil) {
            return;
        }

        destroy(root->childL);
        destroy(root->childR);
        delete root;
    }
};