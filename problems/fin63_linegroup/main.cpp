#include <bits/stdc++.h>

using namespace std;

int N;
int const MAX_N = 100010;
int V[MAX_N];
int memo[MAX_N];

void readInput() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }
}

int group(int i) {
  if (i >= N)
    return 0;
  if (memo[i] != -1)
    return memo[i];
  int curMax = 0;
  int curMin = 1e9;
  int ans = 1e9;

  for (int j = i + 1; j < N && j - i + 1 <= 10; j++) {
    curMax = max(curMax, V[j]);
    curMin = min(curMin, V[j]);
    curMax = max(curMax, V[i]);
    curMin = min(curMin, V[i]);
    ans = min(ans, curMax - curMin + group(j + 1));
  }
  return memo[i] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  readInput();
  memset(memo, -1, sizeof(memo));
  cout << group(0) << '\n';
  return 0;
}
