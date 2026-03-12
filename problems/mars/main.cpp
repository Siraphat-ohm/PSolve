#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string s;
int len;
int memo[1001][26];

int dist(int a, int b){
    int d = abs(a - b);
    return min(d, 26 - d);
}

int solve(int i, int j){
    if(i == len) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    int cur = s[i-1] - 'A';
    int nxt = s[i]   - 'A';

    int opt1 = dist(cur, nxt) + solve(i+1, j);

    int opt2 = dist(j, nxt) + solve(i+1, cur);

    return memo[i][j] = min(opt1, opt2);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        len = s.size();

        memset(memo, -1, sizeof(memo));

        int first = dist(0, s[0] - 'A');
        cout << first + solve(1, 0) << '\n';
    }
    return 0;
}
