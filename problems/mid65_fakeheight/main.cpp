#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 100010;
int N;
long long orig[MAX_N];
long long sorted_h[MAX_N];

long long base_diff = 0;
long long min_total_diff = 0;

void readInput() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> orig[i];
        sorted_h[i] = orig[i];
    }
}

void check( long long target, int i  ) {
    auto it = lower_bound(sorted_h, sorted_h + N, target);
    int idx = it - sorted_h;

    int start = max(0, idx - 4);
    int end = min(N - 1, idx + 4);

    for ( int j = start; j <= end; j++ ) {
        long long Y = sorted_h[j];

        if ( Y == orig[i]) continue;
        if ( i > 0 && Y == orig[i-1]) continue;
        if ( i < N - 1 && Y == orig[i+1]) continue;

        long long old_local = 0;
        long long new_local = 0;

        if ( i == 0 ) {
            old_local = abs(orig[0] - orig[1]);
            new_local = abs( Y - orig[1]);
        } else if ( i == N - 1 ) {
            old_local = abs(orig[N-1] - orig[N-2]);
            new_local = abs( Y - orig[N-2]);
        } else {
            old_local = abs(orig[i] - orig[i+1]) + abs(orig[i] - orig[i-1]);
            new_local = abs( Y - orig[i+1]) + abs( Y - orig[i-1]);
        }

        long long current_total = base_diff - old_local + new_local;
        if ( current_total < min_total_diff) {
            min_total_diff = current_total;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();

    for ( int i = 0; i < N - 1; i++ ) {
        base_diff += abs(orig[i] - orig[i + 1]);
    }

    min_total_diff = base_diff;

    sort(sorted_h, sorted_h + N);

    for ( int i = 0 ; i < N ; i++ ) {
        if ( i == 0 ) {
            check( orig[1], i);
        } else if ( i == N - 1 ) {
            check( orig[N-2], i);
        } else {
            check( orig[i-1], i);
            check( orig[i+1], i);
        }
    }
    cout << min_total_diff << '\n';
    return 0;
}
