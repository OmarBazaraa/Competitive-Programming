#include <stack>
#include <limits>

template<class T>
struct monotonic_queue_state {
    T val;
    T min;
    T max;

    monotonic_queue_state(T val, T min, T max)
        : val(val), min(min), max(max)
    {
        // Constructor.
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
        auto state = monotonic_queue_state<T>(
            std::numeric_limits<T>::min(),
            std::numeric_limits<T>::max(),
            std::numeric_limits<T>::min()
        );

        s1.push(state);
        s2.push(state);
    }

    /**
     * Pushes a new element to the end of the queue.
     *
     * @param val the new element to push.
     */
    void push(T val) {
        add(s1, val);
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
        flip();
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
    void add(std::stack<monotonic_queue_state<T>>& stack, T val) const {
        T max = std::max(val, stack.top().max);
        T min = std::min(val, stack.top().min);

        stack.push(monotonic_queue_state<T>(val, min, max));
    }

    void flip() const {
        // Only flip if stack `s2` is empty.
        if (s2.size() > 1) {
            return;
        }

        // Move all elements from stack `s1` to stack `s2`.
        while (s1.size() > 1) {
            add(s2, s1.top().val);

            s1.pop();
        }
    }
};
