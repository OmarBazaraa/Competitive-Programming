#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

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
    monotonic_queue() {
        s1.push({ INT_MIN, { INT_MIN, INT_MAX } });
        s2.push({ INT_MIN, { INT_MIN, INT_MAX } });
    }

    void push(T v) {
        add(s1, v);
    }

    void pop() {
        flip();
        s2.pop();
    }

    T front() {
        flip();
        return s2.top().F;
    }

    T max() {
        return std::max(s1.top().S.F, s2.top().S.F);
    }

    T min() {
        return std::min(s1.top().S.S, s2.top().S.S);
    }

    T size() {
        return s1.size() + s2.size() - 2;
    }
};