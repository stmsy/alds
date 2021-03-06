#include <iostream>

using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int LEFT[MAX/2 + 2], RIGHT[MAX/2 + 2];
int counter;

void merge(int A[], int n, int left, int mid, int right);
void mergeSort(int A[], int n, int left, int right);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_B
 */
int main() {
  int A[MAX], n, i;
  counter = 0;

  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];

  mergeSort(A, n, 0, n);

  for (i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;

  cout << counter << endl;

  return 0;
}

// Perform a merge of two ordered arrays
void merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i;

  // Partition A to left/right halves
  for (i = 0; i < n1; i++) LEFT[i] = A[left + i];
  for (i = 0; i < n2; i++) RIGHT[i] = A[mid + i];

  // Set sentinel at both ends
  LEFT[n1] = RIGHT[n2] = SENTINEL;

  int j = 0, k = 0;
  for (int l = left; l < right; l++) {
    counter++;
    // Add element from the left half and increment the index
    if (LEFT[j] <= RIGHT[k]) A[l] = LEFT[j++];
    // Add element from the right half and increment the index
    else A[l] = RIGHT[k++];
  }
}

// Perform a merge sort on an array of integers
void mergeSort(int A[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}
