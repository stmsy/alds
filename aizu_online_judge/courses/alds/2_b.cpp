#include <iostream>

using namespace std;

static const int MAX = 100;

void print(int A[], int N);
int selectionSort(int A[], int N);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_B
 */
int main() {
  int N;
  int A[MAX];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  int num_swapped = selectionSort(A, N);
  print(A, N);

  cout << num_swapped << endl;

  return 0;
}

/* Print all entries in single line to standard output */
void print(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";  // Print a white space right to an entry
    cout << A[i];
  }
  cout << endl;
}

/* Perform a selection sort on an array */
int selectionSort(int A[], int N) {
  int min_j;
  int num_swapped = 0;

  for (int i = 0; i < N - 1; i++) {
    min_j = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[min_j]) min_j = j;
    }
    swap(A[i], a[min_j]);
    if (i != min_j) num_swapped++;
  }

  return num_swapped;
}
