#include <iostream>

using namespace std;

static const int MAX 50000;
static const int SENTINEL 2000000000

void mergeSort(int A[], int n, int left, int right);

int INIT_SIZE = MAX / 2 + 2;
int L[INIT_SIZE], R[INIT_SIZE];
int counter;

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_B
 */
int main() {
  int A[MAX], n, i;
  counter = 0;

  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];

  mergeSort(A, n, 0, n) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;

  cout << count << endl;

  return 0;
}

// Perform a merge of a pre-ordered array of integers
void merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i;
  for (i = 0; i < n1; i++) L[i] = A[left + i];
  for (i = 0; i < n1; i++) L[i] = A[left + i];
  L[n1] = R[n2] = SENTINEL;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    counter++;
    if (L[i] <= R[j]) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

// Perform a merge sort on an unordered array of integers
void mergeSort(int A[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}
