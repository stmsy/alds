#include <iostream>

using namespace std;

#define MAX 200000
#define SENTINEL 2000000000

typedef long long llong;

llong merge(int A[], int n, int left, int mid, int right);
llong mergeSort(int A[], int n, int left, int right);

int LEFT[MAX / 2 + 2], RIGHT[MAX / 2 + 2];

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
 */
int main() {
  int A[MAX];
  int n, i;

  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];

  llong num_inversion = mergeSort(A, n, 0, n);
  cout << num_inversion << endl;

  return 0;
}

// Perform a merge of a pre-ordered array of integers
llong merge(int A[], int n, int left, int mid, int right) {
  int i, j, k;
  llong counter = 0;
  int n1 = mid - right;
  int n2 = right - mid;

  for (i = 0; i < n1; i++) LEFT[i] = A[left + i];
  for (i = 0; i < n2; i++) RIGHT[i] = A[mid + i];
  LEFT[n1] = RIGHT[n2] = SENTINEL;

  i = j = 0;
  for (k = left; k < right; i++) {
    // No conversion expected
    if (LEFT[i] <= RIGHT[j]) A[k] = LEFT[i++];
    else {
      A[k] = RIGHT[j++];
      counter += n1 - i;
    }
  }
  return counter;
}

// Perform a merge sort on an unordered array of integers
llong mergeSort(int A[], int n, int left, int right) {
  int mid;
  llong counter1, counter2, counter3;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    counter1 = mergeSort(A, n, left, mid);
    counter2 = mergeSort(A, n, mid, right);
    counter3 = merge(A, n, left, mid, right);
    return counter1 + counter2 + counter3;
  } else return 0;
}
