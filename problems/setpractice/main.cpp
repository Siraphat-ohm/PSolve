#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> s;

void readInput() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    for ( int i = 0 ; i < m; i++ ) {
        int y;
        cin >> y;
        auto it = s.lower_bound(y);
        if ( it == s.begin() ) {
            cout << *it << '\n';
        } else if ( it == s.end() ) {
            cout << *(--it) << '\n';
        } else {
            auto left_it = it;
            --left_it;
            int dist_left = y - *left_it;
            int dist_right = *it - y;
            cout << (dist_left <= dist_right ? *left_it : *it) << '\n';
        }

    }
    return 0;
}
