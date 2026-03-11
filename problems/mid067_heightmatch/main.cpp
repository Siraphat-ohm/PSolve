#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, L;
const int MAX_N = 200010;
int h[MAX_N];
map<int, vector<int>> pos;

void readInput() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        pos[h[i]].push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();

    int ans = 0;

    for (int i = 0; i < N; i++) {
        auto lower = lower_bound(pos[h[i]].begin(), pos[h[i]].end(), i + 1);
        auto upper = upper_bound(pos[h[i]].begin(), pos[h[i]].end(), i + L);
        int count = upper - lower;
        if ( count > 0 ) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
