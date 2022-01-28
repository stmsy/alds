#include <iostream>

using namespace std;

static const int N = 100;

void print(int A[], int N);
void insertionSort(int A[], int N);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_A
 */
int main() {
  int N;
  int A[100];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  print(A, N);
  insertionSort(A, N);

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

/* Perform an insertion sort on an array */
void insertionSort(int A[], int N) {
  int i, j, v;
  for (i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print(A, N);
  }
}
