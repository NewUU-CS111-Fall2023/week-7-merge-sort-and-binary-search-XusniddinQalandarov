#include <bits/stdc++.h>
using namespace std;

int max_beauty(vector<int>& permutation) {
  int n = permutation.size();
  int beauty = 0;
  for (int i = 0; i < n; i++) {
    beauty += abs(permutation[i] - i);
  }

  while (true) {
    int furthest_i = -1, furthest_diff = 0;
    for (int i = 0; i < n; i++) {
      int diff = abs(permutation[i] - i);
      if (diff > furthest_diff) {
        furthest_i = i;
        furthest_diff = diff;
      }
    }

    if (furthest_diff == 0) {
      break;
    }

    int best_swap_i = -1, best_swap_diff = 0;
    for (int swap_i = 0; swap_i < n; swap_i++) {
      if (swap_i == furthest_i) {
        continue;
      }

      int swap_diff = 0;
      if ((furthest_i < swap_i) ^ (furthest_i < furthest_diff)) {
        swap_diff = abs(permutation[swap_i] - furthest_i) - abs(permutation[swap_i] - swap_i) + abs(permutation[furthest_i] - swap_i) - abs(permutation[furthest_i] - furthest_i);
      }

      if (best_swap_diff < swap_diff) {
        best_swap_i = swap_i;
        best_swap_diff = swap_diff;
      }
    }

    if (best_swap_i != -1) {
      swap(permutation[furthest_i], permutation[best_swap_i]);
      beauty += best_swap_diff;
    } else {
      break;
    }
  }

  return beauty;
}

int main() {
  int n;
  cin >> n;
  vector<int> permutation(n);
  for (int i = 0; i < n; i++) {
    cin >> permutation[i];
  }

  cout << max_beauty(permutation) << endl;

  return 0;
}
