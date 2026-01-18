#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
vector<int> p;
map<pair<int, int>, int> memo;

int solve(int i, int diff) {
  if (i >= N) {
    return (diff == 0) ? 0 : -1e8;
  }

  auto key = make_pair(i, diff);
  if (memo.count(key))
    return memo[key];

  int result = -1e8;
  result = max(result, solve(i + 1, diff + p[i]) + p[i]);
  result = max(result, solve(i + 1, diff - p[i]) + p[i]);
  result = max(result, solve(i + 1, diff));

  return memo[key] = result;
}

int main() {
  cin >> N;
  p.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  int ans = solve(0, 0);
  cout << max(0, ans / 2) << endl;

  return 0;
}
