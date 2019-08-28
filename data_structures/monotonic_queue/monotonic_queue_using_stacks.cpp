#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

/**
 * Monotonic queue to keep track of the minimum and/or the maximum
 * elements so far in the queue in O(1).
 */
template<class T>
class monotonic_queue {
    stack<pair<T, pair<T, T>>> s1, s2;

    void add(stack<pair<T, pair<T, T>>>& s, T v) {
        T mx = std::max(v, s.top().S.F);
        T mn = std::min(v, s.top().S.S);

        s.push({ v, { mx, mn } });
    }

    void flip() {
        if (s2.size() > 1) {
            return;
        }
        
        while (s1.size() > 1) {
            add(s2, s1.top().F);
            s1.pop();
        }
    }

public:
    /**
     * Constructs a new monotonic queue.
     */
    monotonic_queue() {
        s1.push({ numeric_limits<T>::min(), { numeric_limits<T>::min(), numeric_limits<T>::max() } });
        s2.push({ numeric_limits<T>::min(), { numeric_limits<T>::min(), numeric_limits<T>::max() } });
    }

    /**
     * Pushes a new element to the end of this queue.
     * 
     * @param v the new element to be pushed.
     */
    void push(T v) {
        add(s1, v);
    }

    /**
     * Pops the front element from the queue.
     * If the queue is empty, an exception is thrown.
     */
    void pop() {
        flip();
        s2.pop();
    }

    /**
     * @return the front element of the queue.
     */
    T front() const {
        flip();
        return s2.top().F;
    }

    /**
     * @return the maximum element of the queue.
     */
    T max() const {
        return std::max(s1.top().S.F, s2.top().S.F);
    }

    /**
     * @return the minimum element of the queue.
     */
    T min() const {
        return std::min(s1.top().S.S, s2.top().S.S);
    }

    /**
     * @return the size of the queue.
     */
    size_t size() const {
        return s1.size() + s2.size() - 2;
    }
};