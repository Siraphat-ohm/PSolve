#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> cars(N);
    for (int i = 0; i < N; i++) {
        cin >> cars[i].first >> cars[i].second;
    }

    int unsell = 0;
    int max_eff = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (cars[i].second < max_eff) {
            unsell++;
        } else {
            max_eff = cars[i].second;
        }
    }

    cout << unsell << endl;

    return 0;
}
