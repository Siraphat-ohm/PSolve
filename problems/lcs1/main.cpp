#include <iostream>
#include <vector>

using namespace std;

// int lcs(int i, int j, string s, string t) {
//   if (i == 0 || j == 0)
//     return 0;
//
//   if (s[i] == t[j])
//     return lcs(i - 1, j - 1, s, t) + 1;
//   else
//     return max(lcs(i - 1, j, s, t), lcs(i, j - 1, s, t));
// }
//
// int main() {
//   string s;
//   string t;
//   cin >> s;
//   cin >> t;
//
//   int i = s.length();
//   int j = t.length();
//
//   cout << lcs(i, j, s, t);
//   return 0;
// }
//
//
//

int lcs(string s, string t) {
  int n = s.length();
  int m = t.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }

  return dp[n][m];
}

int main() {

  string s;
  string t;
  cin >> s;
  cin >> t;

  cout << lcs(s, t);
}
