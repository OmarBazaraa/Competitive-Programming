#include <bits/stdc++.h>

using namespace std;

/**
 * Disjoint-set data structure to tracks a set of elements partitioned
 * into a number of disjoint subsets.
 */
class DSU {
    int setsCount;
    vector<int> siz;
    mutable vector<int> par;

public:

    /**
     * Initializes the DSU with "n" independent sets.
     *
     * @param n the number of sets to initialize.
     */
    DSU(int n) {
        setsCount = n;
        siz.resize(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    /**
     * Finds the set id of an element.
     *
     * @param u the element to find its set id.
     *
     * @return the set id of the given element.
     */
    int findSetId(int u) const {
        return u == par[u] ? u : par[u] = findSetId(par[u]);
    }

    /**
     * Checks whether two elements are in the same set.
     *
     * @param u the first element.
     * @param v the second element.
     *
     * @return {@code true} if elements "u" and "v" are in the same set;
     * 		   {@code false} otherwise.
     */
    bool areInSameSet(int u, int v) const {
        return findSetId(u) == findSetId(v);
    }

    /**
     * Unions two sets together into one set.
     *
     * @param u an element in the first set.
     * @param v an element in the second set.
     *
     * @return {@code true} if the set having element "u" is merged with the
     * 		   set having element "v"; {@code false} if elements "u" and "v" were
     * 		   already in the same set.
     */
    bool unionSets(int u, int v) {
        u = findSetId(u);
        v = findSetId(v);

        if (u == v) {
            return false;
        }

        setsCount--;
        siz[v] += siz[u];
        par[u] = v;
        return true;
    }

    /**
     * Returns the number of elements of a set.
     *
     * @param u an element in the required set.
     *
     * @return the size of the set having the given element "u".
     */
    int getSetSize(int u) const {
        return siz[findSetId(u)];
    }

    /**
     * @return the number of disjoint sets.
     */
    int getSetsCount() const {
        return setsCount;
    }
};