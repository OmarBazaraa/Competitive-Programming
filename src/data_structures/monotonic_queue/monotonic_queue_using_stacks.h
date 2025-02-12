#include <stack>
#include <limits>

/**
 * The `monotonic_queue_state` is a helper structure used to store the state of the elements in the queue.
 */
template<class T>
struct monotonic_queue_state {
    T val, min, max;

    monotonic_queue_state() {
        min = std::numeric_limits<T>::max();
        max = std::numeric_limits<T>::min();
    }

    monotonic_queue_state(T val) : val(val), min(val), max(val) {}

    monotonic_queue_state(T val, T min, T max) : val(val), min(min), max(max) {}

    monotonic_queue_state(T val, const monotonic_queue_state<T>& base) : val(val) {
        min = std::min(val, base.min);
        max = std::max(val, base.max);
    }
};

/**
 * The `monotonic_queue_using_stacks` is a normal "first-in first-out" queue data structure with an extra ability
 * of keeping track of the minimum and/or the maximum elements so far in the queue efficiently in constant time.
 *
 * @tparam T the type of the elements in the queue.
 */
template<class T>
class monotonic_queue_using_stacks {
    mutable std::stack<monotonic_queue_state<T>> s1, s2;

public:
    /**
     * Constructs a new object of the `monotonic_queue_using_stacks` class.
     */
    monotonic_queue_using_stacks() {
        monotonic_queue_state<T> state;

        s1.push(state);
        s2.push(state);
    }

    /**
     * Pushes a new element to the end of the queue.
     *
     * @param val the new element to push.
     */
    void push(T val) {
        auto base = s1.top();

        s1.push(monotonic_queue_state<T>(val, s1.top()));
    }

    /**
     * Pops and removes the front element from the queue.
     *
     * @return the front element of the queue after removing it.
     */
    T pop() {
        T val = front();

        s2.pop();

        return val;
    }

    /**
     * @return the front element of the queue.
     */
    T front() const {
        // Flip the elements from stack `s1` to stack `s2`, only if `s2` is empty.
        if (s2.size() == 1) {
            flip();
        }

        return s2.top().val;
    }

    /**
     * @return the minimum element of the queue.
     */
    T min() const {
        return std::min(s1.top().min, s2.top().min);
    }

    /**
     * @return the maximum element of the queue.
     */
    T max() const {
        return std::max(s1.top().max, s2.top().max);
    }

    /**
     * @return whether the queue is empty or not.
     */
    bool empty() const {
        return s1.size() + s2.size() == 2;
    }

    /**
     * @return the size of the queue.
     */
    int size() const {
        return s1.size() + s2.size() - 2;
    }

private:
    void flip() const {
        while (s1.size() > 1) {
            auto base = s2.top();

            s2.push(monotonic_queue_state<T>(s1.top().val, base));
            s1.pop();
        }
    }
};
