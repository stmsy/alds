#include <stdio.h>

void print(int A[], int N);
int selectionSort(int A[], int N);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_B
 */
int main() {
  int N;
  int A[100];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);

  int num_swapped = selectionSort(A, N);
  print(A, N);

  printf("%d\n", num_swapped);

  return 0;
}

/* Print all entries in single line to standard output */
void print(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) printf(" ");  // Print a white space right to an entry
    printf("%d", A[i]);
  }
  printf("\n");
}

/* Perform a selection sort on an array */
int selectionSort(int A[], int N) {
  int min_j, tmp;
  int num_swapped = 0;

  for (int i = 0; i < N - 1; i++) {
    min_j = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[min_j]) min_j = j;
    }
    tmp = A[i]; A[i] = A[min_j]; A[min_j] = tmp;
    if (i != min_j) num_swapped++;
  }

  return num_swapped;
}
