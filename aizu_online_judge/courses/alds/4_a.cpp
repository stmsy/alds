#include <iostream>

using namespace std;

static const int MAX = 10000;

int linearSearch(int S[], int n, int key);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_A
 */
int main() {
  int i, n, q, key;
  int S[MAX+1];
  int sum = 0;

  cin >> n;
  for (i = 0; i < n; i++) cin >> S[i];

  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> key;
    if (linearSearch(S, n, key)) sum++;
  }

  cout << sum << endl;

  return 0;
}

/* Perform a linear search on an array */
int linearSearch(int S[], int n, int key) {
  int i = 0;

  S[n] = key;

  while (S[i] != key) i++;

  // Return true if not equal, equivalently key found in array
  return i != n;
}
