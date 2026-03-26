#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int N, M, S, K;
const int MAX_N = 50005;
const int MAX_M = 100005;

int L[MAX_N];
int P[MAX_N];
int dist[MAX_N];
vector<int> adj[MAX_N];

void readInput() {
  cin >> N >> M >> K >> S;

  for (int i = 0; i < N; i++)
    cin >> L[i];

  for (int i = 0; i < K; i++)
    cin >> P[i];

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
};

int bfs(int card) {
  if (L[0] > card || L[N - 1] > card)
    return -1;
  memset(dist, -1, sizeof(dist));
  queue<int> q;
  dist[1] = 0;
  q.push(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == N)
      return dist[N];

    for (int v : adj[u]) {
      if (dist[v] == -1 && L[v - 1] <= card) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return -1;
}

void solve() {
  ll ans = -1;
  for (int k = 0; k < K; k++) {
    int rooms = bfs(k + 1);
    if (rooms != -1 && rooms <= S - 1) {
      if (ans == -1 || P[k] < ans)
        ans = P[k];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  readInput();
  solve();
  return 0;
}
