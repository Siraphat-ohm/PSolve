#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int MAX_N = 100010;

int k;
int n, m;
vector<int> adj[MAX_N];
int color[MAX_N];

void init() {
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    color[i] = 0;
  }
}

void read_input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

bool bfs(int s) {
  list<int> Q;

  Q.push_back(s);
  color[s] = 1;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop_front();

    for (int v : adj[u]) {
      if (color[v] == 0) {
        color[v] = (color[u] == 1) ? 2 : 1;
        Q.push_back(v);
      } else if (color[v] == color[u]) {
        return false;
      }
    }
  }

  return true;
}

void solve() {
  read_input();

  bool is_bi = true;

  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      if (!bfs(i)) {
        is_bi = false;
        break;
      }
    }
  }

  if (is_bi) {
    cout << "yes\n";
  } else {
    cout << "no\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  if (cin >> k) {
    while (k--) {
      init();
      solve();
    }
  }
  return 0;
}
