#include <queue>

/**
 * The `monotonic_queue` is a normal "first-in first-out" queue data structure with an extra ability
 * of keeping track of the minimum and/or the maximum elements so far in the queue efficiently in constant time.
 *
 * @tparam T the type of the elements in the queue.
 */
template<class T>
class monotonic_queue {
    std::queue<T> qu;
    std::deque<T> mx, mn;

public:
    /**
     * Pushes a new element to the end of the queue.
     *
     * @param val the new element to push.
     */
    void push(T val) {
        qu.push(val);

        // Keep the max-queue sorted in non-increasing order.
        while (mx.size() > 0 && mx.back() < val) mx.pop_back();
        mx.push_back(val);

        // Keep the min-queue sorted in non-decreasing order.
        while (mn.size() > 0 && mn.back() > val) mn.pop_back();
        mn.push_back(val);
    }

    /**
     * Pops and removes the front element from the queue.
     * 
     * @return the front element of the queue after removing it.
     */
    T pop() {
        T val = qu.front();

        qu.pop();

        if (mx.front() == val) mx.pop_front();
        if (mn.front() == val) mn.pop_front();

        return val;
    }

    /**
     * @return the front element of the queue.
     */
    T front() const {
        return qu.front();
    }

    /**
     * @return the minimum element of the queue.
     */
    T min() const {
        return mn.front();
    }

    /**
     * @return the maximum element of the queue.
     */
    T max() const {
        return mx.front();
    }

    /**
     * @return whether the queue is empty or not.
     */
    bool empty() const {
        return qu.empty();
    }

    /**
     * @return the size of the queue.
     */
    int size() const {
        return qu.size();
    }
};
