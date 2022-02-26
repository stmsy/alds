#include <stdio.h>

#define MAX 1000000

int binarySearch(int key);

int A[MAX];
int n;

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
 */
int main() {
  int i, q, key;
  int total;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &key);
    if (binarySearch(key)) total++;
  }

  printf("%d\n", total);

  return 0;
}

/* Perform a binary search on the sequence of pre-sorted integers in
   increasing order */
int binarySearch(int key) {
  int left = 0;
  int right = n;
  int mid;

  while (left < right) {
    mid = (left + right) / 2;
    if (A[mid] == key) return 1;  // key found in sequence
    if (A[mid] < key) left = mid + 1;  // searched from latter half of sequence
    else if (key < A[mid]) right = mid;  // searched from first half of sequence
  }

  return 0;  // key not found in sequence
}
