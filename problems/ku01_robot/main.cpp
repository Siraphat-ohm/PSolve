#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, h2, b1, b2;
    int x, y;

    if (!(cin >> h1 >> h2 >> b1 >> b2 >> x >> y)) return 0;

    int max_profit = 0;
    for (int ww = 0; ww <= h1 && ww <= b1; ++ww) {
        for (int bb = 0; bb <= h2 && bb <= b2; ++bb) {
            int k = ww + bb;
            int rem_h1 = h1 - ww;
            int rem_b1 = b1 - ww;
            int rem_h2 = h2 - bb;
            int rem_b2 = b2 - bb;

            int wb = min(rem_h1, rem_b2);
            int bw = min(rem_h2, rem_b1);
            int l = wb + bw;

            int current_profit = min(k, x) + min(l, y);

            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }
    }

    cout << max_profit;

    return 0;
}
