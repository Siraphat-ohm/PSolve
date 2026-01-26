#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100010;

int n,m;
vector<int> adj[MAX_N];
vector<int> deg(MAX_N);

void read_input() {
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ) {
       int u,v;
       cin >> u >> v;
       u--; v--;
       adj[u].push_back(v);
       deg[u]++;
       adj[v].push_back(u);
       deg[v]++;
    }
}

bool visited[MAX_N];
bool found [MAX_N];
int parents[MAX_N];
int layers [MAX_N];

void init(){
    for ( int u = 0 ; u < n ; u++ ) {
        visited[u] = false;
        parents[u] = -1;
        found[u] = false;
    }
}

void bfs( int s ) {
    vector<int> current;
    vector<int> next;

    current.push_back(s);
    found[s] = true;
    layers[s] = 0;

    while ( !current.empty() ) {
        for ( int u : current ) {
            visited[u] = true;
            for ( int v : adj[u] ) {
                if ( !found[v] ) {
                    next.push_back(v);
                    found[v] = true;
                    layers[v] = layers[u] + 1;
                }
            }
        }
        current = next;
        next.clear();
    }
}

void dfs(int u) {
    visited[u] = true;
    for ( int d = 0 ; d < deg[u]; d++ ) {
        int v = adj[u][d];
        if ( !visited[v] ) {
            parents[v] = u;
            dfs(v);
        }
    }
}

int main() {

    read_input();
    init();
    int count = 0;
    for ( int s = 0 ; s < n ; s++ ) {
        if ( !visited[s] ) {
            count++;
            bfs(s);
        }
    }

    cout << count << '\n';
}
