#include <bits/stdc++.h>
using namespace std;

int N;


int main() {
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    set<int> distinct;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += P[j];
            distinct.insert(sum);
        }
    }

    cout << distinct.size() << endl;
    return 0;
}
