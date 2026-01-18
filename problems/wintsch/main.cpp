#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;

struct Job {
  int start, end, weight;
  int index;
};
vector<Job> jobs;
vector<int> next_t;
vector<int> dp;

// int solve(int i) {
//   if (i >= N || i < 0)
//     return 0;
//
//   int take = jobs[i].weight + solve(next_t[i]);
//   int skip = solve(i + 1);
//   return max({take, skip});
// }

int main() {
  cin >> N;
  jobs.resize(N);
  next_t.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> jobs[i].start >> jobs[i].end >> jobs[i].weight;
    jobs[i].index = i;
  }
  // sort(jobs.begin(), jobs.end(),
  //      [](const Job &a, const Job &b) { return a.end < b.end; });

  sort(jobs.begin(), jobs.end(),
       [](const Job &a, const Job &b) { return a.start < b.start; });
  // Cal next_t[]
  for (int i = 0; i < N; i++) {
    auto it = lower_bound(
        jobs.begin() + i + 1, jobs.end(), jobs[i].end,
        [](const Job &job, int end_time) { return job.start < end_time; });
    next_t[i] = it - jobs.begin();
  }

  dp.assign(N + 10, -1);
  dp[N] = 0;

  for (int i = N - 1; i >= 0; i--) {
    int take = jobs[i].weight + dp[next_t[i]];
    int skip = dp[i + 1];
    dp[i] = max({take, skip});
  }

  vector<int> selected;
  int i = 0;

  while (i < N) {
    int take = jobs[i].weight + dp[next_t[i]];
    int skip = dp[i + 1];

    if (take >= skip) {
      selected.push_back(jobs[i].index + 1);
      i = next_t[i];
    } else {
      i++;
    }
  }

  cout << dp[0] << endl;
  cout << selected.size() << endl;
  for (int idx : selected) {
    cout << idx << " ";
  }

  return 0;
}
