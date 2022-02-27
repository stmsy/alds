#include <iostream>

using namespace std;

static const int MAX = 100000;

int getMaxNumPackages(long long P);
int binarySearch();

int n, k;
long long T[MAX];

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D
 */
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> T[i];
  long long ans = binarySearch();

  cout << ans << endl;

  return 0;
}

/* Get maximum number of packages loaded for given P */
int getMaxNumPackages(long long P) {
  int i = 0;
  for (int j = 0; j < k; j++) {
    long long s = 0;
    while (s + T[i] <= P) {
      s += T[i];
      i++;
      if (i == n) return n;
    }
  }
  return i;
}

/* Perform a binary search on pre-sorted sequence */
int binarySearch() {
  long long left = 0;
  long long right = MAX * 1000;  // number of packages * max weight for each package
  long long mid;

  while (right - left > 1) {
    mid = (left - right) / 2;
    int v = getMaxNumPackages(mid);
    if (v >= n) right = mid;
    else left = mid;
  }

  return right;
}
