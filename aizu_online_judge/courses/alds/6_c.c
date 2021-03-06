#include <stdbool.h>
#include <stdio.h>

#define MAX 100000
#define SENTINEL 200000000

struct Card {
  char suit;
  int value;
};

struct Card LEFT[MAX/2 + 2], RIGHT[MAX/2 + 2];

void merge(struct Card A[], int n, int left, int mid, int right);
void mergeSort(struct Card A[], int n, int left, int right);
int partition(struct Card A[], int n, int p, int r);
void quickSort(struct Card A[], int n, int p, int r);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_C
 */
int main() {
  int n, i, value;
  struct Card A[MAX], B[MAX];
  char suit[10];
  bool stable = true;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s %d", suit, &value);
    A[i].suit = B[i].suit = suit[0];
    A[i].value = B[i].value = value;
  }

  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n-1);

  for (i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) stable = false;
  }

  if (stable) printf("Stable\n");
  else printf("Not stable\n");

  for (i = 0; i < n; i++) printf("%c %d\n", B[i].suit, B[i].value);

  return 0;
}

// Perform a merge of two ordered arrays
void merge(struct Card A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i;

  // Partition A to left/right halves
  for (i = 0; i < n1; i++) LEFT[i] = A[left + i];
  for (i = 0; i < n2; i++) RIGHT[i] = A[mid + i];

  // Set sentinel at both ends
  LEFT[n1].value = RIGHT[n2].value = SENTINEL;

  int j = 0, k = 0;
  for (int l = left; l < right; l++) {
    // Add element from the left half and increment the index
    if (LEFT[j].value <= RIGHT[k].value) A[l] = LEFT[j++];
    // Add element from the right half and increment the index
    else A[l] = RIGHT[k++];
  }
}

// Perform a merge sort on an array of structs
void mergeSort(struct Card A[], int n, int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

// Partition an array of structs by the last-indexed element
int partition(struct Card A[], int n, int p, int r) {
  int i, j;
  struct Card target, tmp;

  target = A[r];

  i = p - 1;
  for (j = p; j < r; j++) {
    if (A[j].value <= target.value) {
      i++;
      tmp = A[i]; A[i] = A[j]; A[j] = tmp;
    }
  }
  tmp = A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;

  return i + 1;
}

// Perform a quick sort on an array of structs
void quickSort(struct Card A[], int n, int p, int r) {
  int q;
  if (p < r) {
    q = partition(A, n, p, r);
    quickSort(A, n, p, q-1);
    quickSort(A, n, q+1, r);
  }
}
