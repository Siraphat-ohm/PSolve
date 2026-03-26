#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int N;
ll L;

const int MAX_N = 100005;

ll A[MAX_N];
ll B[MAX_N];

void readInput() {
  cin >> N >> L;

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
}

void solve() {
  vector<pair<ll, ll>> intervals;

  for (int i = 0; i < N; i++) {
    if (B[i] > L) {
      cout << -1 << "\n";
      return;
    }

    ll max_dist = L - B[i];
    ll l_b = A[i] - max_dist;
    ll r_b = A[i] + max_dist;

    intervals.pb({r_b, l_b});
  }

  sort(all(intervals));

  int ponds = 0;
  ll last = -2e18;

  for (auto c_i : intervals) {
    ll c_r = c_i.fi;
    ll c_l = c_i.se;

    if (c_l > last) {
      ponds++;
      last = c_r;
    }
  }

  cout << ponds << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;

  readInput();
  while (t--) {
    solve();
  }

  return 0;
}
