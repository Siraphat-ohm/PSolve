#include <iostream>
#include <vector>
using namespace std;

int N,L;

int main() {
    cin >> N >> L;

    vector<int> queue(N);
    vector<int> order(L);
    vector<int> max_prev(N, -1);

    for(int i = 0; i < N; i++) {
        cin >> queue[i];
        if (i == 0) {
            max_prev[i] = queue[i];
        } else {
            max_prev[i] = max(max_prev[i-1], queue[i]);
        }
    }

    for(int i = 0; i < L; i++) {
        int index ;
        cin >> index;
        order[i] = index-1;
    }

    for ( int i = 0 ; i < L ; i++ ){
        int index = order[i];
        if ( queue[index] == max_prev[index] ) {
            cout << max_prev[index] - queue[index] << '\n';
        } else {
            cout << max_prev[index] - queue[index] + 1 << '\n';
        }
    }

    return 0;
}
