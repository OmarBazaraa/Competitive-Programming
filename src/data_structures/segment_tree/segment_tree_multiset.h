#include <algorithm>
#include <cassert>

/**
 * The `segment_multiset_node` is a helper structure used to represent a node in the segment tree multiset.
 */
struct segment_multiset_node {
    unsigned int size;
    segment_multiset_node *childL, *childR;

    segment_multiset_node() {
        size = 0;
        childL = childR = this;
    }

    segment_multiset_node(int s, segment_multiset_node* l, segment_multiset_node* r) {
        size = s;
        childL = l;
        childR = r;
    }
};

/**
 * The `segment_tree_multiset` is a multiset data structure, implemented using a segment tree,
 * and is used to store a collection of possibly repeated integers.
 * The multiset keeps its elements sorted in non-descending order, and besides the regular
 * set operations, it supports finding the k-th smallest element efficiently.
 *
 * @note
 * The multiset is 0-indexed and can store elements in the range of `[-N, N]`.
 */
class segment_tree_multiset {
    using node = segment_multiset_node;

    const int SEG_L, SEG_R;
    node *root, *nil;

public:
    /**
     * Constructs a new object of the `segment_tree_multiset` class.
     *
     * Time complexity: `O(1)`.
     *
     * @param N the maximum value of the integers to be stored in the multiset.
     */
    segment_tree_multiset(int L = -(1 << 29), int R = (1 << 29)) : SEG_L(L), SEG_R(R) {
        root = nil = new node();
    }

    /**
     * Destructs the multiset and releases the allocated memory.
     *
     * Time complexity: `O(N)`.
     */
    ~segment_tree_multiset() {
        destroy(root);
        delete nil;
    }

    /**
     * Clears and removes all the elements in this multiset.
     *
     * Time complexity: `O(N)`.
     */
    void clear() {
        destroy(root);
        root = nil;
    }

    /**
     * Returns the total number of elements currently stored in the multiset.
     *
     * Time complexity: `O(1)`.
     *
     * @return the size of the multiset.
     */
    int size() {
        return root->size;
    }

    /**
     * Counts the number of occurrences of a specified element in the multiset.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key the element to count its occurrences.
     * @return the number of occurrences of the specified element.
     */
    int count(int key) {
        auto cur = root;
        auto l = SEG_L, r = SEG_R;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (key <= mid) {
                cur = cur->childL;
                r = mid;
            }
            else {
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return cur->size;
    }

    /**
     * Inserts a new element to the multiset, possibly multiple times.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key the element to insert. Should be in the range of [-N, N].
     * @param count the number of occurrences to insert.
     */
    void insert(int key, unsigned int count = 1) {
        assert(SEG_L <= key && key <= SEG_R);

        if (count == 0) {
            return;
        }

        insert(key, count, root, SEG_L, SEG_R);
    }

    /**
     * Removes a number of occurrences of a specified element from the multiset, if exists.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key the element to remove. Should be in the range of [-N, N].
     * @param count the number of occurrences to attempt to remove.
     * @return the actual number of deleted occurrences of the specified element.
     */
    int erase(int key, unsigned int count = 1) {
        assert(SEG_L <= key && key <= SEG_R);

        if (count == 0) {
            return 0;
        }

        return erase(key, count, root, SEG_L, SEG_R);
    }

    /**
     * Returns an element from the multiset by its index.
     *
     * Time complexity: `O(log(N))`.
     *
     * @note
     * The multiset is kept sorted in non-descending order.
     *
     * @param k the index to return its corresponding element. Should be in the range of `[0, size)`.
     * @return the k-th smallest element in the multiset.
     */
    int operator[](unsigned int k) {
        auto cur = root;
        auto l = SEG_L, r = SEG_R;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (k < cur->childL->size) {
                cur = cur->childL;
                r = mid;
            }
            else {
                k -= cur->childL->size;
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return r;
    }

    /**
     * Searches for the index of the first element with a key greater than or equals to a specified key.
     *
     * Time complexity: `O(log(N))`.
     *
     * @note
     * The multiset is kept sorted in non-descending order.
     *
     * @param key the key to search for its lower bound index.
     * @return the lower bound index; or `size + 1` if such element does not exist.
     */
    int lower_bound(int key) {
        auto ret = 0;
        auto cur = root;
        auto l = SEG_L, r = SEG_R;

        while (l < key) {
            int mid = l + (r - l) / 2;

            if (key <= mid) {
                cur = cur->childL;
                r = mid;
            }
            else {
                ret += cur->childL->size;
                cur = cur->childR;
                l = mid + 1;
            }
        }

        return ret;
    }

    /**
     * Searches for the index of the first element with a key greater than a specified key.
     *
     * Time complexity: `O(log(N))`.
     *
     * @note
     * The multiset is kept sorted in non-descending order.
     *
     * @param key the key to search for its upper bound index.
     * @return the upper bound index; or `size + 1` if such element does not exist.
     */
    int upper_bound(int val) {
        return lower_bound(val + 1);
    }

private:
    /**
     * Insert a element to the multiset a specified number of times.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key   the element to insert. Should be in the range of [-N, N].
     * @param count the number of occurrences to insert.
     * @param root  the current root of the segment tree.
     * @param segL  the left index of the range of the current segment.
     * @param segR  the right index of the range of the current segment.
     */
    void insert(int key, unsigned int count, node*& root, int segL, int segR) {
        if (root == nil) {
            root = new node(count, nil, nil);
        } else {
            root->size += count;
        }

        if (segL == segR) {
            return;
        }

        int mid = segL + (segR - segL) / 2;

        if (key <= mid) {
            insert(key, count, root->childL, segL, mid);
        } else {
            insert(key, count, root->childR, mid + 1, segR);
        }
    }

    /**
     * Removes a number of occurrences of a specified element from the multiset, if exists.
     *
     * Time complexity: `O(log(N))`.
     *
     * @param key   the element to remove. Should be in the range of [-N, N].
     * @param count the number of occurrences to attempt to remove.
     * @param root  the current root of the segment tree.
     * @param segL  the left index of the range of the current segment.
     * @param segR  the right index of the range of the current segment.
     * @return the actual number of deleted occurrences of the specified element.
     */
    int erase(int key, unsigned int count, node*& root, int segL, int segR) {
        if (root == nil) {
            return 0;
        }

        if (segL == segR) {
            return remove(root, count);
        }

        int mid = segL + (segR - segL) / 2;

        int ret = (key <= mid)
            ? erase(key, count, root->childL, segL, mid)
            : erase(key, count, root->childR, mid + 1, segR);

        return remove(root, ret);
    }

    /**
     * Removes a specified number of occurrences from a node and destroys it
     * if it becomes empty.
     *
     * @param root  the node to remove from.
     * @param count the number of occurrences to erase (note: cnt > 0).
     * @return the actual number of deleted occurrences.
     */
    int remove(node*& root, unsigned int count) {
        auto size = root->size;

        if (count >= size) {
            destroy(root);
            root = nil;
            return size;
        }
        else {
            root->size -= count;
            return count;
        }
    }

    /**
     * Clears the given segment subtree and releases the allocated memory.
     *
     * @param root the subtree to destroy.
     */
    void destroy(node* root) {
        if (root == nil) return;
        destroy(root->childL);
        destroy(root->childR);
        delete root;
    }
};
