#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int N, M, S, T;
const int MAX_N = 50005;
vector<pair<int, int>> adj[MAX_N];

void readInput() {
  cin >> N >> M >> S >> T;
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].pb({v, c});
    adj[v].pb({u, c});
  }
}

int bfs(int fb_color) {
  vector<int> dist(N + 1, -1);
  queue<int> q;

  dist[S] = 0;
  q.push(S);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == T)
      return dist[u];
    for (auto edge : adj[u]) {
      int v = edge.fi;
      int c = edge.se;
      if (c == fb_color)
        continue;
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return 1e9;
}

void solve() {

  int red_path = bfs(2);

  int black_path = bfs(1);

  int ans = min(red_path, black_path);

  cout << (ans == 1e9 ? -1 : ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  readInput();
  solve();
  return 0;
}
