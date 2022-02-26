#include <stdio.h>

int linearSearch(int S[], int n, int key);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_A
 */
int main() {
  int i, n, q, key;
  int S[10000+1];
  int sum = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &key);
    if (linearSearch(S, n, key)) sum++;
  }

  printf("%d\n", sum);

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
