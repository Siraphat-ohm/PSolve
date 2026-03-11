#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> nums;
int memo[1001][101];

void read_input() {
    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

int splitArr(int i, int k) {
    if (memo[i][k] != -1) {
        return memo[i][k];
    }
    if ( i >=nums.size() ) {
        return 0;
    }
    if (k == 1) {
        return accumulate(nums.begin() + i, nums.end(), 0);
    }
    int curSum = 0;
    int ans = INT_MAX;
    int max_sum = INT_MIN;
    for (int j = i; j < nums.size(); ++j) {
        curSum += nums[j];
        max_sum = max(curSum, splitArr(j + 1, k - 1));
        ans = min(ans, max_sum);
    }
    return memo[i][k] = ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(memo, -1, sizeof(memo));
    read_input();
    cout << splitArr(0, k) << endl;
    return 0;
}
