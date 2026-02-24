#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int H;
int L;
int B;
vector<vector<int>> MAP;

vector<vector<int>> dp;
int solve( int r, int c ){
      if (r < 0 || r >= H) {
        return 67676767;
      }

      if (c == L - 1) {
        return MAP[r][c];
      }

        int path1 = solve(r + 1, c + 1) + MAP[r][c] + B;
        int path2 = solve(r - 1, c + 1) + MAP[r][c] +B;
        int path3 = solve(r, c + 1) + MAP[r][c];
        int best = min({path1, path2, path3});

        return best;

}

int main() {
    cin >> H >> L >> B;
    MAP.assign(H, vector<int>(L));
    for ( int i = 0; i < H ; i++ ){
        for ( int j = 0 ; j < L ; j++ ){
            cin >> MAP[i][j];
        }
    }

    vector<vector<int>> dp(H, vector<int>(L));


    for (int r = 0; r < H; r++) {
      dp[r][L-1] = MAP[r][L-1];
    }

    for ( int c = L - 2 ; c >= 0 ; c-- ) {
        for ( int r = 0 ; r < H; r++ ){
            int path1 = dp[r][c + 1] + MAP[r][c];
            int path2 = 67676767;
            int path3 = 67676767;
            if (r > 0) {
              path2 = dp[r - 1][c + 1] + MAP[r][c] + B;
            }
            if (r < H - 1) {
              path3 = dp[r + 1][c + 1] + MAP[r][c] + B;
            }

            dp[r][c] = min({path1, path2, path3});

        }
    }

    int ans = INT_MAX;
    for ( int r = 0 ; r < H; r++ ) {
        ans = min(ans, dp[r][0]);
    }

    cout << ans;

    return 0;
}
