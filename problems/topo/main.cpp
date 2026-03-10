#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int MAX_N = 100010;
const int MAX_M = 200010;

int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input() {
    cin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
        // deg[u]++;
        deg[v]++;

        // U --> V
    }
}

bool seen[MAX_N];
int layer[MAX_N];

void init() {
    for ( int u = 0 ; u < n; u++ ) {
        seen[u] = false;
        layer[u] = -1;
    }
}

void topo() {
    queue <int> q;

    for ( int u = 1; u <= n ; u++ ) {
        if ( deg[u] == 0 )
            q.push(u);
    }

    vector<int> order;

    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for ( auto v: adj[u] ) {
            deg[v]--;
            if ( deg[v] == 0 )
                q.push(v);
        }
    }

    if ((int)order.size() != n) {
        cout << "no\n";
    } else {
        for (int i = 0; i < (int)order.size(); i++) {
            cout << order[i];
            if (i + 1 < (int)order.size()) cout << "\n";
        }
        cout << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    topo();
    return 0;
}
