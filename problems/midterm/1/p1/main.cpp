#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> heights(N);

    for (int i = 0; i < N; i++) {
        cin >> heights[i].first;
        heights[i].second = i;
    }

    sort(heights.begin(), heights.end());

    vector<int> answers(N);

    for (int i = 0; i < N; i++) {
        int h = heights[i].first;
        int orig_idx = heights[i].second;

        int l = (i > 0) ? heights[i-1].first : INT_MIN;
        int r = (i < N-1) ? heights[i+1].first : INT_MIN;

        answers[orig_idx] = min(abs(h - l), abs(h - r));
    }

    for (int i = 0; i < N; i++) {
        cout << answers[i] << '\n';
    }

    return 0;
}
