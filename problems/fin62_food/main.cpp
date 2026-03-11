#include <bits/stdc++.h>

using namespace std;

int N, K;
int const MAX_N = 5010;
int m[MAX_N];
int memo[MAX_N][MAX_N];

void readInput() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
}

int food( int i , int j ) {
    if ( i >= N ) return 0;
    if ( j < 0 ) return 0;
    if ( memo[i][j] != -1 ) return memo[i][j];
    int stay = 0;
    int goHome = 0;

    if ( j >= m[i] ) {
        stay = food(i+1, j - m[i]);
    } else {
        stay = food(i+1, j) + m[i];
    }

    goHome = food(i+1, K) + m[i];

    return memo[i][j] = min({stay, goHome});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    memset(memo, -1, sizeof(memo));
    cout << food(0, K) << endl;
    return 0;
}
