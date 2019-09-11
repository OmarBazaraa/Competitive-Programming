#include <bits/stdc++.h>

using namespace std;

/**
 * Segment tree node struct.
 */
struct node {
    int size;
    node* childL, * childR;

    /**
     * Constructs an empty node.
     */
    node() {
        size = 0;
        childL = childR = this;
    }

    /**
     * Constructs a new node.
     *
     * @param s the size of the node.
     * @param l the left child of this node.
     * @param r the right child of this node.
     */
    node(int s, node* l, node* r) {
        size = s;
        childL = l;
        childR = r;
    }

    /**
     * Update the size of this node.
     */
    void update() {
        size = childL->size + childR->size;
    }
};

/**
 * Multiset that store integers in the range of [-N, N].
 * The multiset is implemented using segment tree.
 *
 * Note that the multiset is 0-indexed.
 *
 * The most complex function in this class is done in time complexity of O(log(N)).
 */
class segment_multiset {
    const int N;
    node* nil, * root;

public:

    /**
     * Constructs a new multiset.
     * 
     * @param N the maximum absolute value this multiset can store.
     */
    segment_multiset(int N) : N(N) {
        root = nil = new node();
    }

    /**
     * Destruct this multiset.
     */
    ~segment_multiset() {
        destroy(root);
        delete nil;
    }

    /**
     * Clears and removes all the elements in this multiset.
     */
    void clear() {
        destroy(root);
        root = nil;
    }

    /**
     * Returns the total number of integers in the multiset.
     *
     * @return the size of the multiset.
     */
    int size() {
        return root->size;
    }

    /**
     * Counts the number of occurrences of the an integer in the multiset.
     *
     * @param val the integer to count its occurrences.
     *
     * @return the number of occurrences of the given integer.
     */
    int count(int val) {
        node* cur = root;
        int l = -N, r = N;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (val <= mid) {
                cur = cur->childL;
                r = mid;
            } else {
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return cur->size;
    }

    /**
     * Insert a number of occurrences of an integer to the multiset.
     *
     * @param val the integer to insert.
     * @param cnt the number of occurrences to insert (note: cnt > 0).
     */
    void insert(int val, int cnt = 1) {
        assert(cnt > 0);
        insert(root, val, cnt, -N, N);
    }

    /**
     * Erases a number of occurrences of an integer from the multiset if exists.
     *
     * @param val the integer to erase.
     * @param cnt the number of occurrences to erase (note: cnt > 0).
     *
     * @return the number of deleted elements.
     */
    int erase(int val, int cnt = 1) {
        assert(cnt > 0);
        return erase(root, val, cnt, -N, N);
    }

    /**
     * Returns an integer in the multiset by its index.
     *
     * Note that the multiset is kept sorted in non-decreasing order,
     * and is 0-indexed.
     *
     * @param idx the index.
     *
     * @return the "idx" smallest element currently in the multiset.
     */
    int operator[](int idx) {
        if (idx < 0 || idx >= root->size) {
            throw out_of_range("ERROR :: trying to access an out of range element");
        }

        node* cur = root;
        int l = -N, r = N;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (idx < cur->childL->size) {
                cur = cur->childL;
                r = mid;
            } else {
                idx -= cur->childL->size;
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return r;
    }

    /**
     * Returns the index of the first integer with value greater
     * than or equals to the given value.
     *
     * Note that the multiset is kept sorted in non-decreasing order,
     * and is 0-indexed.
     *
     * @param val the value to returns its lower bound index.
     *
     * @return the specified index; or {@code segment_multiset#size() + 1}
     *         if such integer does not exist.
     */
    int lower_bound(int val) {
        int ret = 0;

        node* cur = root;
        int l = -N, r = N;

        while (l < val) {
            int mid = l + (r - l) / 2;

            if (val <= mid) {
                cur = cur->childL;
                r = mid;
            } else {
                ret += cur->childL->size;
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return ret;
    }

    /**
     * Returns the index of the first integer with value greater
     * than the given value.
     *
     * Note that the multiset is kept sorted in non-decreasing order,
     * and is 0-indexed.
     *
     * @param val the value to returns its upper bound index.
     *
     * @return the specified index; or {@code segment_multiset#size() + 1}
     *         if such integer does not exist.
     */
    int upper_bound(int val) {
        return lower_bound(val + 1);
    }

private:

    /**
     * Insert a number of occurrences of an integer to the multiset.
     *
     * @param root the current root of the segment tree.
     * @param val  the integer to insert.
     * @param cnt  the number of occurrences to insert (note: cnt > 0).
     * @param l    the left index of the range of the current segment.
     * @param r    the right index of the range of the current segment.
     */
    void insert(node*& root, int val, int cnt, int l, int r) {
        if (val < l || val > r) {
            return;
        }

        if (root == nil) {
            root = new node(0, nil, nil);
        }

        root->size += cnt;

        if (l == r) {
            return;
        }

        int mid = l + (r - l) / 2;

        insert(root->childL, val, cnt, l, mid);
        insert(root->childR, val, cnt, mid + 1, r);
    }

    /**
     * Erases a number of occurrences of an integer from the multiset if exists.
     *
     * @param root the current root of the segment tree.
     * @param val  the integer to erase.
     * @param cnt  the number of occurrences to erase (note: cnt > 0).
     * @param l    the left index of the range of the current segment.
     * @param r    the right index of the range of the current segment.
     *
     * @return the number of deleted elements.
     */
    int erase(node*& root, int val, int cnt, int l, int r) {
        if (val < l || val > r) {
            return 0;
        }

        if (root == nil) {
            return 0;
        }

        if (l == r) {
            return remove(root, cnt);
        }

        int mid = l + (r - l) / 2;

        int ret = 0;

        ret += erase(root->childL, val, cnt, l, mid);
        ret += erase(root->childR, val, cnt, mid + 1, r);

        return remove(root, ret);
    }

    /**
     * Removes a number of occurrences of an integer from a node and destroys it
     * if it becomes empty.
     *
     * @param root the node to remove from.
     * @param cnt  the number of occurrences to erase (note: cnt > 0).
     *
     * @return the number of deleted elements.
     */
    int remove(node*& root, int cnt) {
        int ret = min(cnt, root->size);

        root->size -= cnt;

        if (root->size <= 0) {
            destroy(root);
            root = nil;
        }

        return ret;
    }

    /**
     * Clears the given segment tree and releases the allocated memory.
     *
     * @param root the root of the sub-tree to destroy.
     */
    void destroy(node* root) {
        if (root == nil) return;
        destroy(root->childL);
        destroy(root->childR);
        delete root;
    }
};