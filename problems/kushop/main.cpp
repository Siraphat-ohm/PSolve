#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v;

// int solve(int i) {
//   if (i >= N || i < 0)
//     return 0; // out of range
//
//   int take = solve(i + 2) + v[i];
//
//   int skip = solve(i + 1);
//
//   return max({take, skip});
// }

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    v.push_back(val);
  }
  // cout << solve(0);
  vector<int> dp(N + 10, 0);
  for (int i = N - 1; i >= 0; i--) {
    int take = dp[i + 2] += v[i];
    int skip = dp[i + 1];
    dp[i] = max({take, skip});
  }
  cout << dp[0];
  return 0;
}
