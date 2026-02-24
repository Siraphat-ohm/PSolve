#include <iostream>

using namespace std;

const int MAX_N = 100010;
const int MAX_M = 200010;

int n,q ;

int components[MAX_N];
int s[MAX_N];
int parents[MAX_N];

void init_union_find()
{
  for(int i=0; i<n; i++) {
    parents[i] = i;
    s[i] = 1;
  }
}

int find( int u ) {
    if ( parents[u] == u )
        return u;
    else
        return find( parents[u]);
}

void union_sets( int cu, int cv ) {
    if ( cu == cv )
        return;
    if ( s[cu] > s[cv]) {
        s[cu] += s[cv];
        parents[cv] = cu;
    } else {
        s[cv] += s[cu];
        parents[cu] = cv;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char cmd;
    cin >> n >> q;
    init_union_find();
    for ( int i = 0; i < q; i++ ){
        int u , v;
        cin >> cmd >> u >> v;
        int cu = find(u);
        int cv = find(v);

        if ( cmd == 'c' ) {
            union_sets(cu, cv);
        } else {
            cout << ( cu == cv ? "yes\n" : "no\n" );
        }
    }
}
