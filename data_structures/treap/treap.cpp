#include <bits/stdc++.h>

using namespace std;

struct node;

node *nil, *root;

// Treap node struct
struct node {
    int key, priority, size;
    node *childL, *childR;

    node() {
        size = 0;
        childL = childR = this;
    }

    node(int val, node* l = nil, node* r = nil) {
        key = val;
        childL = l;
        childR = r;
        size = 1;
        priority = rand();
    }

    void update() {
        size = childL->size + childR->size + 1;
    }
};

ostream& operator<<(ostream& out, node* root) {
    out << "(" << root->key << ", " << root->size << ")";
    return out;
}

void print(node* root, int indent) {
    if (root == nil) {
        return;
    }

    if (root->childL != nil && root->childR != nil) {
        cout << string(indent - 1, '\t') << "      /" << "\t       \\" << endl;

        cout << string(indent - 1, '\t');
        cout << root->childL;

        cout << string(2, '\t');
        cout << root->childR << endl;
    }
    else if (root->childL != nil) {
        cout << string(indent - 1, '\t') << "      /" << endl;
        cout << string(indent - 1, '\t') << root->childL << endl;
    }
    else if (root->childR != nil) {
        cout << string(indent, '\t') << "       \\" << endl;
        cout << string(indent + 1, '\t') << root->childR << endl;
    }

    print(root->childL, indent - 1);
    print(root->childR, indent + 1);
}

void printTree(node* root) {
    cout << string(root->size, '\t') << root << endl;
    print(root, root->size);
}

// Initializes the treap operations.
void init() {
    srand(time(0));
    root = nil = new node();
}

// Splits the given treap (root) into two different treaps: L and R
// such that L contains all the nodes with values <= key and R contains the other nodes.
// Note that the original treap will not exist anymore after the split operation.
void split(node* root, node*& l, node*& r, int key) {
    if (root == nil) {
        l = r = nil;
        return;
    }

    if (key >= root->key) {
        l = root;
        split(root->childR, l->childR, r, key);
    }
    else {
        r = root;
        split(root->childL, l, r->childL, key);
    }

    root->update();
}

// Merges the given two treaps L and R into a single treap (root).
// Note that the largest value of L must be less than the smallest value of R
// in order to get a correct merge operation.
// Note that L and R will not exist anymore after the merge operation.
void merge(node* l, node* r, node*& root) {
    if (l == nil) {
        root = r;
        return;
    }

    if (r == nil) {
        root = l;
        return;
    }

    if (l->priority > r->priority) {
        root = l;
        merge(l->childR, r, root->childR);
    }
    else {
        root = r;
        merge(l, r->childL, root->childL);
    }

    root->update();
}

// Inserts a new node into the given treap.
void insert(node*& root, node* newNode) {
    if (root == nil) {
        root = newNode;
        return;
    }

    if (newNode->priority > root->priority) {
        split(root, newNode->childL, newNode->childR, newNode->key);
        root = newNode;
    }
    else {
        insert((newNode->key <= root->key) ? root->childL : root->childR, newNode);
    }

    root->update();
}

// Erases a single node from the treap having its key matches
// the given key if exists.
void erase(node*& root, int key) {
    if (root == nil) {
        return;
    }

    if (key == root->key) {
        node* temp = root;
        merge(root->childL, root->childR, root);
        delete temp;
    }
    else {
        erase((key <= root->key) ? root->childL : root->childR, key);
    }

    root->update();
}

// Returns the smallest index of a node with key
// greater than or equals to the given key.
// Note that indices are referenced as if all nodes are sorted by their keys.
int lowerBound(node* root, int key) {
    int ret = 0;

    while (root != nil) {
        if (key <= root->key) {
            root = root->childL;
        }
        else {
            ret += root->childL->size + 1;
            root = root->childR;
        }
    }

    return ret;
}

// Returns the smallest index of a node with key
// greater than the given key.
// Note that indices are referenced as if all nodes are sorted by their keys.
int upperBound(node* root, int key) {
    return lowerBound(root, key + 1);
}

// Returns the idx-th node in the given treap.
// Note that indices are referenced as if all nodes are sorted by their keys.
node* getByIndex(node* root, int idx) {
    while (root != nil && idx != root->childL->size) {
        if (idx < root->childL->size) {
            root = root->childL;
        }
        else {
            idx -= root->childL->size + 1;
            root = root->childR;
        }
    }

    return root;
}

int main() {
    init();

    vector<int> vec = { 2, 2, 3, 7, 7, 9 };

    random_shuffle(vec.begin(), vec.end());

    for (int x : vec) {
        insert(root, new node(x));
    }

    printTree(root);
    return 0;
}