#include <stdio.h>

#define MAX 100000

int n;
int A[MAX];

int partition(int p, int r);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_B
 */
int main() {
  int i, q;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);

  q = partition(0, n-1);

  for (i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    if (i == q) printf("[");
    printf("%d", A[i]);
    if (i == q) printf("]");
  }
  printf("\n");

  return 0;
}

// Partition an array of integers by the last-indexed element
int partition(int p, int r) {
  int target, i, j, tmp;

  target = A[r];

  i = p - 1;
  for (j = p; j < r; j++) {
    if (A[j] <= target) {
      i++;
      tmp = A[i]; A[i] = A[j]; A[j] = tmp;
    }
  }
  tmp = A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;

  return i + 1;
}
