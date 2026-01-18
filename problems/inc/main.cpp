#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;

vector<int> arr;
vector<int> dp;

// int inc(int i) {
//   int max_len = 0;
//   if (i >= N)
//     return 0;
//
//   for (int j = i + 1; j < N; j++) {
//     if (arr[i] < arr[j]) {
//       max_len = max(max_len, inc(j));
//     };
//   }
//   return 1 + max_len;
// }
//
int main() {
  cin >> N;
  while (N--) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  N = arr.size();

  vector<int> dp(N + 1, 1);

  for (int i = N - 1; i >= 0; i--) {
    for (int j = i + 1; j < N; j++) {
      if (arr[i] < arr[j])
        dp[i] = max(dp[i], 1 + dp[j]);
    }
  }
  int ans = 0;
  for (int x : dp) {
    ans = max(ans, x);
  }

  int max_len = 0;
  int start_idx = 0;
  for (int i = 0; i < N; i++) {
    if (dp[i] > max_len) {
      max_len = dp[i];
      start_idx = i;
    }
  }

  vector<int> lis;
  int current_len = max_len;
  int i = start_idx;

  while (i < N) {
    lis.push_back(arr[i]);
    current_len--;

    if (current_len == 0)
      break;

    for (int j = i + 1; j < N; j++) {
      if (arr[i] < arr[j] && dp[j] == current_len) {
        i = j;
        break;
      }
    }
  }
  cout << ans << endl;
  for (int x : lis) {
    cout << x << " ";
  }
  return 0;
}
