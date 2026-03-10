#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
vector <vector<int>> MAP;
vector<vector<vector<int>>> dp;
int N, M, K;

void readInput() {
    cin >> N >> M >> K;
    MAP.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
}

int solve(int x, int y, int k){

    if ( y < 0 || y > M - 1 || k < 0 )
        return -1e9;

    if ( x > N - 1 )
        return 0;

    if ( dp[x][y][k] != -1 )
        return dp[x][y][k];

    int path1 = solve(x + 1, y, k - 1);
    int path2 = solve(x + 1, y - 1, k - 1);
    int path3 = solve(x + 1, y + 1, k - 1);
    dp[x][y][k] = max({path1, path2, path3}) + MAP[x][y];
    return dp[x][y][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();

    dp.assign(N, vector<vector<int>>(M, vector<int>(K + 1, -1)));

    int ans = -1e9;
    for (int i = 0; i < M; i++) {
        ans = max(ans, solve(0, i, K));
    }
    cout << ans << '\n';

    return 0;
}
