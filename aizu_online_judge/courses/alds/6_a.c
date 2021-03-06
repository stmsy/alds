#include <stdio.h>
#include <stdlib.h>

void bucketSort();

unsigned short *A, *B;
int n;

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A
 */
int main() {
  int i;

  scanf("%d", &n);

  /* A = malloc(sizeof(short) * n + 1); */
  /* B = malloc(sizeof(short) * n + 1); */

  bucketSort();

  for (i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  /* free(A); */
  /* free(B); */

  return 0;
}

// Perform a bucket sort on an unsorted array
void bucketSort() {
  int i;
  int C[n+1];

  // Initialize the counter array
  for (i = 0; i <= n; i++) C[i] = 0;

  for (i = 0; i < n; i++) {
    scanf("%hu", &A[i+1]);
    // Keep track of the number of occurrences
    C[A[i+1]]++;
  }

  // Compute the cumulative sum of occurrences
  for (i = 1; i <= n; i++) C[i] = C[i] + C[i-1];

  for (i = n; i > 0; i--) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}
