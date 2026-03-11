#include <iostream>
using namespace std;

const int MAX_N = 5010;
int n;
int a[MAX_N];

void readInput(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int findMin() {
    int l = 0, r = n - 1;
    int mid = l + ( r - l ) / 2 ;
    while ( l < r ) {
        if ( a[mid] < a[r] ) {
            r = mid;
        } else if ( a[mid] > a[r] ) {
            l = mid + 1;
        } else {
            r--;
        }
        mid = l + ( r - l ) / 2 ;
    }
    return a[l];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    cout << findMin() << endl;
}
