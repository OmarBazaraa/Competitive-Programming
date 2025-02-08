#include <map>

/**
 * The `interval_map` is a data structure used to associate values to consecutive ranges of keys.
 *
 * @tparam K the type of the keys.
 * @tparam V the type of the values.
 */
template<typename K, typename V>
class interval_map
{
private:
    // The default value to use when no other value is associated with a key.
    V val_default;

    // The map to store the values.
    // `map[k] = v` means that the value `v` is associated with all keys
    // starting from `k` to the next key, or to infinity if there is no next key.
    std::map<K, V> map;

public:
    /**
     * Constructs a new object of the `interval_map` with a provided default value.
     *
     * Time complexity: `O(1)`.
     *
     * @param val the default value to use when no value is associated with a key.
     */
    interval_map(const V& val)
    {
        this->val_default = val;
    }

    /**
     * Looks up for the value associated with a specified key.
     *
     * Time complexity: `O(log(N))`, where `N` is the number of intervals in the map.
     *
     * @param key the key to search for its associated value.
     * @return the value associated with the specified key.
     */
    const V & operator[](const K& key) const
    {
        auto it = this->map.upper_bound(key);

        if (it == this->map.begin())
        {
            return val_default;
        }
        else
        {
            return (--it)->second;
        }
    }

    /**
     * Assigns a new value to a given interval, overwriting any previous values.
     *
     * Time complexity: `O(log(N))`, where `N` is the number of intervals in the map.
     *
     * @param key_begin the beginning of the interval (inclusive).
     * @param key_end the end of the interval (exclusive).
     * @param val the new value to set.
     */
    void assign(const K& key_begin, const K& key_end, const V& val)
    {
        if (key_begin >= key_end)
        {
            // Invalid interval.
            // Throw an exception or simply return.
            return;
        }

        // Get current values at both ends.
        const V val_begin = (*this)[key_begin];
        const V val_end = (*this)[key_end];

        // Delete all entries in the map in interval (key_begin, key_end).
        this->map.erase(this->map.upper_bound(key_begin), this->map.lower_bound(key_end));

        // Update the value on the left.
        if (val != val_begin)
        {
            this->map[key_begin] = val;
        }

        // Update the value on the right.
        if (val != val_end)
        {
            this->map[key_end] = val_end;
        }
    }
};
