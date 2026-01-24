#include <iostream>
using namespace std;

int N, L;

int main() {
    cin >> L >> N ;
    for (int i = 1; i <= L ;i++ ){
        N -=  i*i ;
        // cout << "N:" << N << '\n';
        if ( N == 0 ) {
            cout << L-i;
            break;
        } else if ( N < 0 ) {
            cout << L-i+1;
            break;
        }
    }
    return 0;
}
