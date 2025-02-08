#include <vector>
#include <numeric>

/**
 * The Disjoint-Set or `dsu` is a data structure to track a set of elements partitioned
 * into a number of disjoint subsets.
 */
class dsu {
    // The number of disjoint sets.
    int siz;

    // A vector to store the number of elements in each set.
    std::vector<int> counts;

    // A vector to store the leader of each element.
    mutable std::vector<int> leaders;

public:
    /**
     * Constructs a new object of the `dsu` class with a specified number of elements,
     * each in its own set.
     *
     * Time complexity: `O(n)`.
     *
     * @param n the initial number of disjoint sets.
     */
    dsu(int n) {
        siz = n;
        counts.resize(n, 1);
        leaders.resize(n);

        // Initialize the leaders with the identity function.
        std::iota(leaders.begin(), leaders.end(), 0);
    }

    /**
     * Time complexity: `O(1)`.
     *
     * @return the current number of disjoint sets.
     */
    int size() const {
        return siz;
    }

    /**
     * Gets the number of elements of a specified set.
     *
     * Time complexity: `O(alpha(N))` ~ `O(1)` amortized.
     *
     * @param u an element in the set required to return its size.
     * @return the size of the set containing the given element `u`.
     */
    int count(int u) const {
        return counts[find_id(u)];
    }

    /**
     * Finds the set id of an element.
     *
     * Time complexity: `O(alpha(N))` ~ `O(1)` amortized.
     *
     * @param u the element to find its set id.
     * @return the id of the set containing the given element `u`.
     */
    int find_id(int u) const {
        // This method uses path compression technique to optimize the performance.
        return u == leaders[u] ? u : leaders[u] = find_id(leaders[u]);
    }

    /**
     * Checks whether two elements are in the same set or not.
     *
     * Time complexity: `O(alpha(N))` ~ `O(1)` amortized.
     *
     * @param u the first element.
     * @param v the second element.
     * @return `true` if both elements are in the same set; `false` otherwise.
     */
    bool same_set(int u, int v) const {
        return find_id(u) == find_id(v);
    }

    /**
     * Unions or merges two disjoint sets into one.
     *
     * Time complexity: `O(alpha(N))` ~ `O(1)` amortized.
     *
     * @param u an element in the first set.
     * @param v an element in the second set.
     * @return `true` if both sets were merged together; and `false` if the given
     * elements `u` and `v` were already in the same set.
     */
    bool merge(int u, int v) {
        u = find_id(u);
        v = find_id(v);

        if (u == v) {
            return false;
        }

        siz--;
        counts[v] += counts[u];
        leaders[u] = v;
        return true;
    }
};
