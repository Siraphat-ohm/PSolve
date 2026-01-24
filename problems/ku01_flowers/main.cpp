#include <iostream>

using namespace std;

int main() {
    long long L, N;
    cin >> L >> N;


    long long k = 1;
    while (true) {
        long long side = k * L;
        long long total_cells = (side * (side + 1)) / 2;

        if (total_cells >= N) {
            cout << k << endl;
            break;
        }
        k++;
    }

    return 0;
}
