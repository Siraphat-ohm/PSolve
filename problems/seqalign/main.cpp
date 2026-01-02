#include <algorithm>
#include <iostream>

using namespace std;
//
// int seq(int i, int j, string s, string t) {
//   if (i < 0)
//     return j + 1;
//   if (j < 0)
//     return i + 1;
//
//   if (s[i] == t[j]) {
//     return seq(i - 1, j - 1, s, t);
//   } else {
//     int opt1 = 1 + seq(i - 1, j - 1, s, t);
//     int opt2 = 1 + seq(i - 1, j, s, t);
//     int opt3 = 1 + seq(i, j - 1, s, t);
//
//     return min({opt1, opt2, opt3});
//   }
// }
int dp[405][405];

int solve(int n, int m, string s, string t) {

  for (int i = 1; i <= n; i++)
    dp[i][0] = i;

  for (int j = 1; j <= m; j++)
    dp[0][j] = j;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        int opt1 = dp[i - 1][j - 1] + 1;
        int opt2 = dp[i - 1][j] + 1;
        int opt3 = dp[i][j - 1] + 1;

        dp[i][j] = min({opt1, opt2, opt3});
      }
    }
  }

  return dp[n][m];
}

int main() {
  string s;
  string t;

  cin >> s;
  cin >> t;

  int n = s.length();
  int m = t.length();
  cout << solve(n, m, s, t);
  return 0;
}
