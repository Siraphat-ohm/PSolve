#include <iostream>
#include <algorithm>


using namespace std;

long long N, A ,B ;
int p[200010];

void readInput() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    readInput();
    sort(p, p + N);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        auto lower = lower_bound(p + i + 1, p + N, A - p[i]);
        auto upper = upper_bound(p + i + 1, p + N, B - p[i]);
        long long cnt = upper - lower;
        if (cnt > 0) {
            ans += cnt;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
