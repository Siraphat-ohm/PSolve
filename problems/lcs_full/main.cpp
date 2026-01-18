#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int n, m;

int lcs(string s, string t) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  return dp[n][m];
}

string getLCS(string s, string t) {
  int i = s.length();
  int j = t.length();
  string result = "";
  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      result = s[i - 1] + result;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  return result;
}

int main() {
  string s, t;
  cin >> s >> t;

  n = s.length();
  m = t.length();

  dp = vector<vector<int>>(n + 1, vector<int>(m + 1));

  cout << lcs(s, t) << endl;
  cout << getLCS(s, t);
}
