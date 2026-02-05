#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;

int N, R;

vector<pair<int, int>> points;
int layers[MAX_N];
bool seen[MAX_N];

void read_input() {
    cin >> N >> R;
    points.push_back({0,0});

    for ( int i = 0; i < N; i++ ) {
        int x, y;
        cin >> x >> y;
        points.push_back({x,y});
    }

    points.push_back({100,100});

}

void init() {
    memset(layers, -1, sizeof(layers));
    memset(seen, false, sizeof(seen));
}

int bfs( int s ) {
    list<int> Q;

    Q.push_back(s);
    seen[s] = true;
    layers[s] = 0;

    while ( !Q.empty() ) {
        int u = Q.front();
        Q.pop_front();

        for ( int v = 0; v < points.size(); v++ ) {
            if ( seen[v] ) continue;
            int dx = points[v].first - points[u].first;
            int dy = points[v].second - points[u].second;
            if ( dx * dx + dy * dy <= R * R ) {
                layers[v] = layers[u] + 1;
                seen[v] = true;
                Q.push_back(v);
            }
        }
    }

    return layers[points.size()-1];
}

int main() {

    read_input();
    init();

    int ans = bfs(0);
    cout << ans << endl;

    return 0;
}
