#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

const int MAX_N = 100005;

int N, M, S, T;
vector<int> adj[MAX_N];
int dist[MAX_N];
vector<int> factories;
queue<int> q;

void readInput() {
  cin >> N >> M >> S >> T;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  memset(dist, -1, sizeof(dist));

  for (int i = 0; i < S; i++) {
    int wh;
    cin >> wh;
    dist[wh] = 0;
    q.push(wh);
  }

  for (int i = 0; i < T; i++) {
    int f;
    cin >> f;
    factories.pb(f);
  }
}

void bfs() {
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

void solve() {
  for (int t : factories) {
    cout << dist[t] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  readInput();
  bfs();
  solve();
  return 0;
}
