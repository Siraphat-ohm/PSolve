#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> MAP;
vector<vector<int>> dp;
int T, N, M;

// int earthcrack(int i, int j) {
//   if (j < 0 || j >= N) {
//     return 67676767;
//   }
//
//   if (i == M - 1) {
//     return MAP[i][j];
//   }
//
//   int path1 = earthcrack(i + 1, j) + MAP[i][j];
//   int path2 = earthcrack(i + 1, j + 1) + MAP[i][j];
//   int path3 = earthcrack(i + 1, j - 1) + MAP[i][j];
//
//   int best = min({path1, path2, path3});
//
//   return best;
// }

int main() {

  cin >> T;
  while (T--) {
    cin >> M >> N;
    MAP.assign(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        cin >> MAP[i][j];
        // cout << MAP[i][j] << " ";
      }
      // cout << "\n";
    }

    vector<vector<int>> dp(M, vector<int>(N));

    for (int j = 0; j < N; j++) {
      dp[M - 1][j] = MAP[M - 1][j];
    }

    for (int i = M - 2; i >= 0; i--) {
      for (int j = 0; j < N; j++) {
        int path1 = dp[i + 1][j] + MAP[i][j];

        int path2 = 67676767, path3 = 67676767;
        if (j > 0) {
          path2 = dp[i + 1][j - 1] + MAP[i][j];
        }
        if (j < N - 1) {
          path3 = dp[i + 1][j + 1] + MAP[i][j];
        }

        dp[i][j] = min({path1, path2, path3});
      }
    }

    int minEnergy = INT_MAX;
    for (int j = 0; j < N; j++) {
      minEnergy = min(minEnergy, dp[0][j]);
    }

    cout << minEnergy << '\n';
  }

  return 0;
}
