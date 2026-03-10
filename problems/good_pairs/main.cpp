#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 100010;
int N, S, T;
int p[MAX_N];

void readInput() {
    cin >> N >> S >> T;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    int s = 0 ;
    for ( int i = 0; i < N; i++) {
        auto lower = lower_bound(p + i + 1, p + N, S - p[i]);
        auto upper = upper_bound(p + i + 1, p + N, T + p[i]);
        int pairs = upper - lower;
        if (pairs > 0) {
            s += pairs;
        }
    }
    cout << s << '\n';
    return 0;
}
