#include <iostream>

using namespace std;

int dp[1005];

// int solve(int n, int k) {
//   if (n == 0)
//     return 1;
//
//   if (n < 0)
//     return 0;
//
//   int s = 0;
//
//   for (int i = 1; i <= k + 1; i++) {
//     s += solve(n - i, k);
//   }
//
//   return s % 9337;
// }

int solve(int n, int k) {
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    dp[i] = 0;

    for (int j = 1; j <= k + 1; j++) {
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j]) % 9337;
      }
    }
  }

  return dp[n];
}

int main() {
  int n, k;
  cin >> n >> k;

  cout << solve(n, k);
  return 0;
}
