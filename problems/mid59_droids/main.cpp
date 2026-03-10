#include <cstdlib>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int N, M;
set <int> S;

void readInput() {
    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) {
        int pos;
        cin >> pos;
        S.insert(pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    long long total_dist = 0;
    int resting_droid = -1;

    for ( int i = 0; i < M; i++ ) {
        int X;
        cin >> X;

        auto it = S.lower_bound(X);

        int chosen_droid = -1;

        if ( it == S.begin() ) {
            chosen_droid = *it;
        } else if ( it == S.end() ) {
            auto it_left = it;
            it_left--;
            chosen_droid = *it_left;
        } else {
            int right_pos = *it;
            auto it_left = it;
            it_left--;
            int left_pos = *it_left;

            int dist_right = right_pos - X;
            int dist_left = X - left_pos;

            if ( dist_left <= dist_right ) {
                chosen_droid = left_pos;
            } else {
                chosen_droid = right_pos;
            }
        }

        total_dist += abs(X - chosen_droid);
        S.erase(chosen_droid);

        if ( resting_droid != -1 ) {
            S.insert(resting_droid);
        }
        resting_droid = chosen_droid;
    }
    cout << total_dist << '\n';
    return 0;
}
