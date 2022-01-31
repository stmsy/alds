#include <iostream>

using namespace std;

static const int MAX = 100;

int bubbleSort(int A[], int N);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_A
 */
int main() {
  int A[MAX], N, num_swapped;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  num_swapped = bubbleSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << num_swapped << endl;

  return 0;
}

/* Perform a bubble sort on an array */
int bubbleSort(int A[], int N) {
  int num_swapped = 0;
  bool is_reversed = 1;

  for (int i = 0; is_reversed; i++) {
    is_reversed = 0;
    for (int j = N-1; j > i; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        is_reversed = 1;
        num_swapped++;
      }
    }
  }

  return num_swapped;
}
