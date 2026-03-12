#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int MAP[210][210];
int memo[210][210];
int N, M;

void readInput() {
    cin >> M >> N ;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
}

int solve(int row, int col) {
      if (col < 0 || col >= N) {
        return -67676767;
      }

      if (row == M - 1) {
          // return MAP[row][col];
          if (row % 2 == 0)
              return MAP[row][col] + max(0, solve(row, col + 1));
          else
              return MAP[row][col] + max(0, solve(row, col - 1));
      }

      if (memo[row][col] != -1)
          return memo[row][col];

      int down = solve(row + 1, col) + MAP[row][col];
      if ( row % 2  == 0 ) {
          int keepLeft = solve(row, col + 1) + MAP[row][col];
          memo[row][col] = max(down, keepLeft);
      } else {
          int keepRight = solve(row, col - 1) + MAP[row][col];
          memo[row][col] = max(down, keepRight);
      }

      return memo[row][col];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    int ans = -1e9;
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < M; i++) {
        ans = max(ans, solve(0, i));
    }
    cout << ans << '\n';

    return 0;
}
