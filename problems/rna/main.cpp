#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
string r;

vector<vector<int>> dp;

bool check(char b1, char b2) {
  int s = b1 + b2;
  return (s == 'A' + 'U') || (s == 'C' + 'G');
}

// int MaxPair(int i, int j) {
//   if (i >= j)
//     return 0;
//
//   int maxPairs = MaxPair(i + 1, j);
//
//   for (int k = i + 5; k <= j; k++) {
//     if (check(r[i], r[k]))
//       maxPairs = max(maxPairs, 1 + MaxPair(i + 1, k - 1) + MaxPair(k + 1,
//       j));
//   }
//
//   return maxPairs;
// }

int main() {
  cin >> r;
  int N = r.length();
  dp.assign(N + 5, vector<int>(N + 5, 0));
  int maxPairs;
  for (int i = N - 1; i >= 0; i--) {
    for (int j = i; j < N; j++) {

      if (j - i < 4) {
        dp[i][j] = 0;
        continue;
      }

      maxPairs = dp[i + 1][j];

      for (int k = i + 5; k <= j; k++) {
        if (check(r[i], r[k])) {
          maxPairs = max(maxPairs, 1 + dp[i + 1][k - 1] + dp[k + 1][j]);
        }
      }

      dp[i][j] = maxPairs;
    }
  }
  cout << dp[0][N - 1];
  return 0;
}
