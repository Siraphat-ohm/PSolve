#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
int N, L;
const int MAX_N = 100005;
int S[MAX_N];
int T[MAX_N];
int solve() {
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> T[i];
  }
  int start = S[0];
  int fences = 1;
  for (int i = 1; i <= N; i++) {
    if (T[i] - start > L) {
      fences++;
      start = S[i];
    }
  }
  return fences;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ans = solve();
  cout << ans;
  return 0;
}
