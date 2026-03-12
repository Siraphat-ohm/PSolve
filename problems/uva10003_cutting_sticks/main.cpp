#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int dp[55][55];
int p[55];
int n;

int solve(int i, int j){
    if(j == i + 1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX/2;
    for(int k = i+1; k < j; k++){
        int cost = solve(i, k) + solve(k, j) + p[j] - p[i];
        dp[i][j] = min(dp[i][j], cost);
    }
    return dp[i][j];
}

int main(){
    int l;
    while(cin >> l && l != 0){
        cin >> n;

        p[0] = 0;
        for(int i = 1; i <= n; i++) cin >> p[i];
        p[n+1] = l;

        memset(dp, -1, sizeof(dp));

        cout << "The minimum cutting is " << solve(0, n+1) << ".\n";
    }
    return 0;
}
