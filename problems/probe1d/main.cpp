#include "probelib.h"
#include <cstdio>

int n;

int main() {
  int n = probe_init();

  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = ((high - low) / 2) + low;

    if (probe_check(low, mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  probe_answer(low);
}
