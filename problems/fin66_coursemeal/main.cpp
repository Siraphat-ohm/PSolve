#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX_N = 500010;
long long X[MAX_N];
long long Y[MAX_N];
long long Z[MAX_N];
long long memo[MAX_N];

void readInput(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
}

long long maxMeal( int i ) {
    if (i >= N) return 0;

    if (memo[i] != -1) return memo[i];

    long long normal = maxMeal(i + 1) + X[i];
    long long special = maxMeal(i + 2) + Y[i];
    long long superSpecial = maxMeal(i + 4) + Z[i];
    long long skip = maxMeal(i + 1);
    return memo[i] = max({normal, special, superSpecial, skip});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    memset(memo, -1, sizeof(memo));
    printf("%lld\n", maxMeal(0));
    return 0;
}
