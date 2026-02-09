#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX_N = 100010;
int d[MAX_N], x[MAX_N];
pair<int, int> jobs[MAX_N];

void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> x[i];
    jobs[i].first = d[i];
    jobs[i].second = x[i];
  }
}

int main() {
  read_input();
  sort(jobs, jobs + n);
  int t = 0;
  int penalty = 0;
  for ( int i = 0 ; i < n ; i++ ) {
      t += jobs[i].second;
        penalty = max(penalty,( t - jobs[i].first - 10) * 1000 );
  }
  cout << penalty;
  return 0;
}
