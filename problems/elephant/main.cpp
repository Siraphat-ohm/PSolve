#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> v;
int const MAX_N = 100010;
int memo[MAX_N];

long long solve(int i) {
  if (i > N)
    return 0;

  if (memo[i] != -1)
    return memo[i];

  long long res = solve(i + 1);

  if (i >= 3)
    res = max(res, v[i] + solve(i + 3));

  return memo[i] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  v.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> v[i];
  }

  memset(memo, -1, sizeof(memo));
  cout << solve(1);
  return 0;
}
