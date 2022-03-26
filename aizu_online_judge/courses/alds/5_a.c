#include <stdio.h>

#define MAX 20

int recursiveAddition(int i, int m);

int n;
int A[MAX];

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_A
 */
int main() {
  int q, M, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &M);
    if (recursiveAddition(0, M)) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}

/* Pick integers from sequence and add recursively */
int recursiveAddition(int i, int m) {
  if (m == 0) return 1;
  if (i >= n) return 0;

  int result = recursiveAddition(i+1, m) || recursiveAddition(i+1, m-A[i]);

  return result;
}
