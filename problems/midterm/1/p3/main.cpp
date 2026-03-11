#include <bits/stdc++.h>

using namespace std;

int N, B, K;
const int MAX_N = 210;
int V[MAX_N];
int memo[MAX_N][MAX_N];

void readInput() {
    cin >> N >> B >> K;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
}

int combinePiece( int i, int k ) {
    if ( i >= N ) return 0;
    if ( k == 0 ) {
        return -1e9;
    }
    if ( memo[i][k] != -1 ) return memo[i][k];
    int curMax = 0;
    int ans = 0;
    for (int j = i; j < N; j++) {
        curMax = max(curMax, V[j]);
        int L = j - i + 1;
        int segVal = curMax * ( L + 1) / 2 - ( L - 1) * B;
        ans = max(ans, segVal + combinePiece(j + 1, k - 1));
    }
    return memo[i][k] = ans;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(memo, -1, sizeof(memo));
    readInput();
    cout << combinePiece(0, K) << endl;
    return 0;
}
