#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int N, M;
multiset<ll> boats;

void readInput() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    boats.insert(x);
  }
}
void solve() {
  int ans = 0;

  for (int i = 0; i < M; i++) {
    int req;
    cin >> req;

    auto it = boats.lower_bound(req);

    if (it != boats.end()) {
      ans++;
      boats.erase(i);
    } else {
      break;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  readInput();
  while (t--)
    solve();
  return 0;
}
