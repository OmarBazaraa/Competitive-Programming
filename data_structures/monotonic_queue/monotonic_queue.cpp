#include <bits/stdc++.h>

using namespace std;

template<class T>
class monotonic_queue {
    queue<T> qu;
    deque<T> mx;
    deque<T> mn;

public:
    void push(T v) {
        qu.push(v);
        while (mx.size() && mx.back() < v) mx.pop_back();
        mx.push_back(v);
        while (mn.size() && mn.back() > v) mn.pop_back();
        mn.push_back(v);
    }

    void pop() {
        if (mx.front() == qu.front()) mx.pop_front();
        if (mn.front() == qu.front()) mn.pop_front();
        qu.pop();
    }

    T front() {
        return qu.front();
    }

    T max() {
        return mx.front();
    }

    T min() {
        return mn.front();
    }

    T size() {
        return qu.size();
    }
};