#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX = 200000;

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_D
 */
int main() {
  int R[MAX];
  int n, i;

  cin >> n;
  for (i = 0; i < n; i++) cin >> R[i];

  int max_value = -2000000000;
  int min_value = R[0];

  for (i = 1; i < n; i++) {
    max_value = max(max_value, R[i] - min_value);
    min_value = min(min_value, R[i]);
  }

  cout << max_value << endl;

  return 0;
}
