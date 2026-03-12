#include <bits/stdc++.h>

using namespace std;

int N;
int const MAX_N = 1010;
int land[MAX_N];
int memo[MAX_N];

void readInput() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> land[i];
    }
}

int landPart(int i) {
    if (i >= N) return 0;
    if (memo[i] != -1) return memo[i];


    int ans = 0;
    int curMax = 0;

    for (int j = i; j < N; j++) {
        curMax = max(curMax, land[j]);
        if (j - i + 1 >= 5)
            ans = max(ans, curMax + landPart(j + 1));
    }
    return memo[i] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    memset(memo, -1, sizeof(memo));
    cout << landPart(0) << '\n';
    return 0;
}
