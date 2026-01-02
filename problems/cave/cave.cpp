#include "cave.h"
#include <cstring>

void build_com(int S[], int N, int k[], int L, int mid) {
  for (int j = 0; j < N; j++) {
    if (k[j] != -1) {
      S[j] = k[j];
    } else if (j >= L && j <= mid) {
      S[j] = 1;
    } else {
      S[j] = 0;
    }
  }
}

void exploreCave(int N) {
  int S[5000];
  int D[5000];
  int k[5000];
  std::memset(k, -1, sizeof(k));
  std::memset(S, 0, sizeof(S));
  int L = 0, R = N - 1;

  for (int i = 0; i < N; i++) {
    build_com(S, N, k, 1, 0);

    int try_res = tryCombination(S);
    int correct_val;

    if (try_res == -1 || try_res > i) {
      correct_val = 0;
    } else {
      correct_val = 1;
    }

    int L = 0, R = N - 1;

    while (L < R) {
      int mid = (L + R) / 2;

      build_com(S, N, k, L, mid);

      int res = tryCombination(S);

      bool door_open = (res == -1 || res > i);

      if (correct_val == 1) {
        if (door_open) {
          R = mid;
        } else {
          L = mid + 1;
        }
      } else {
        if (door_open) {
          L = mid + 1;
        } else {
          R = mid;
        }
      }
    }
    int index = L;
    k[index] = correct_val;
    S[index] = correct_val;
    D[index] = i;
  }

  answer(S, D);
}
