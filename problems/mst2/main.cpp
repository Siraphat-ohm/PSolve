#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 100010;
const int MAX_M = 200010;

int n,m;
pair<int,int> edges[MAX_M];
int weights[MAX_M];
vector<pair<int,int>> windex;

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



void read_input()
{
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int u,v,l;
    cin >> u >> v >> l;  u--;  v--;
    edges[i].first = u;
    edges[i].second = v;
    weights[i] = l;

    // for sorting
    windex.push_back({ l, i });
  }
  sort(windex.begin(), windex.end());
}

int main()
{
  read_input();
  int cost = 0;
  init_union_find();
  for(int i=0; i<m; i++) {
    // consider windex[i] -- edge with the i-th min weight
    int e = windex[i].second;
    int l = weights[e];
    int u = edges[e].first;
    int v = edges[e].second;

    int cu = find(u);
    int cv = find(v);
    if(cu != cv) {
      cost += l;
      union_sets(cu,cv);
    }
  }
  cout << cost << endl;
  return 0;
}
