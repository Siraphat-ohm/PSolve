#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 510;
int n, k;
int memo[MAX_N];
vector<int> arr;

void readInput(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
}

int maxPartitionSum(int i) {
    if ( i >= arr.size() )
        return 0;
    if ( memo[i] != -1 )
        return memo[i];
    int currMax = 0;
    int res = 0;
    int windowSize = 0;
    int end = min<int>(i + k, arr.size());
    for ( int j = i ; j < end ; j++ ) {
        currMax = max(currMax, arr[j]);
        windowSize = j - i + 1;
        res = max(res, maxPartitionSum(j+1) + currMax * windowSize);
    }
    return memo[i] = res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    cout << maxPartitionSum(0) << endl;
    return 0;
}
