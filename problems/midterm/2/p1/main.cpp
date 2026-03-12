#include <bits/stdc++.h>
using namespace std;

int N;
int const MAX_N = 220010;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> Q;
    map<int, int> pos;
    set<int> P;

    cin >> N;
    int qidx = 0;
    int pidx = 0;

    for (int i = 0; i < N; i++) {
        int t ;
        cin >> t;
        int p, q;
        if ( t == 1 ) {
            cin >> q ;
            pos[q] = qidx++;
            Q.insert(q);
        } else {
            int q1;
            cin >> q1 >> p;
            // q2 = P - q1
            auto it = Q.lower_bound( p - q1);
            if ( it == Q.begin() ) { // head
                // cout << "Required P " << p << " Found " << *it + q1 << '\n';
                if ( *it + q1 >= p ) {
                    cout << pos[*it] + 1 << '\n';
                } else {
                    cout << "-1\n";
                }
            } else if ( it == Q.end() ) { // end
                // cout << "Required P " << p << " Found tail " << *(--it) + q1 << '\n';
                if ( *(--it) + q1 >= p ) {
                    cout << pos[*it] + 1 << '\n';
                } else {
                    cout << "-1\n";
                }
            } else {
               cout << pos[*it] + 1 << '\n';
            }
        }
    }
    return 0;
}
