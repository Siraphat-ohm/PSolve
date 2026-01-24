#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int row = ceil(sqrt(N));
    if ( N == 1) {
        cout << 0;
        return 0;
    }

    bool isRowEven = row % 2 == 0;
    bool isNEven = N % 2 == 0;

    if ( isRowEven && isNEven ) {
        cout << 2*( row -  1) ;
    } else if ( isRowEven && !isNEven ) {
        cout << 2*( row -  1) - 1 ;
    } else if ( !isRowEven && isNEven ) {
        cout << 2*( row -  1) - 1 ;
    } else {
        cout << 2*( row -  1) ;
    }

    return 0;
}
