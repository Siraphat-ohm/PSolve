#include <bitset>
#include <cstring>
#include <iostream>
using namespace std;

int M[7];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int caseNum = 1;
  int n1, n2, n3, n4, n5, n6;

  while (cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6) {
    if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0)
      break;

    int total = n1 + 2 * n2 + 3 * n3 + 4 * n4 + 5 * n5 + 6 * n6;

    cout << "Collection #" << caseNum++ << ":\n";

    if (total & 1) {
      cout << "Can't be divided.\n\n";
      continue;
    }

    int target = total >> 1;

    bitset<60001> dp;
    dp[0] = 1;

    for (int k = 1; k <= n1; k++)
      dp |= (dp << 1);

    for (int k = 1; k <= n2; k++)
      dp |= (dp << 2);

    for (int k = 1; k <= n3; k++)
      dp |= (dp << 3);

    for (int k = 1; k <= n4; k++)
      dp |= (dp << 4);

    for (int k = 1; k <= n5; k++)
      dp |= (dp << 5);

    for (int k = 1; k <= n6; k++)
      dp |= (dp << 6);

    cout << (dp[target] ? "Can be divided.\n\n" : "Can't be divided.\n\n");
  }

  return 0;
}
