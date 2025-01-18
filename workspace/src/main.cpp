#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

static inline void boost_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

typedef long long int64;

int main() {
    boost_io();

    int T;
    cin >> T;

    while (T--) {
        string name;
        cin >> name;
        cout << "Hello, " << name << "!" << endl;
    }

    return 0;
}
