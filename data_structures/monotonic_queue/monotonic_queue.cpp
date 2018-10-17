#include <bits/stdc++.h>

using namespace std;

/**
 * Monotonic queue to keep track of the minimum and/or the maximum
 * elements so far in the queue in O(1).
 */
template<class T>
class monotonic_queue {
    queue<T> qu;
    deque<T> mx, mn;

public:
    /**
     * Pushes a new element in the queue.
     * 
     * @param v the new element to be pushed.
     */
    void push(T v) {
        qu.push(v);
        while (mx.size() && mx.back() < v) mx.pop_back();
        mx.push_back(v);
        while (mn.size() && mn.back() > v) mn.pop_back();
        mn.push_back(v);
    }

    /**
     * Pops the front element from the queue.
     * If the queue is empty, an exception is thrown.
     */
    void pop() {
        if (mx.front() == qu.front()) mx.pop_front();
        if (mn.front() == qu.front()) mn.pop_front();
        qu.pop();
    }

    /**
     * @return the front element of the queue.
     */
    T front() {
        return qu.front();
    }

    /**
     * @return the maximum element of the queue.
     */
    T max() {
        return mx.front();
    }

    /**
     * @return the minimum element of the queue.
     */
    T min() {
        return mn.front();
    }

    /**
     * @return the size of the queue.
     */
    T size() {
        return qu.size();
    }
};