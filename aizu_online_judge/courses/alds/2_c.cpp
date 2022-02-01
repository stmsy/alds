#include <iostream>

using namespace std;

static const int MAX = 100;
struct Card { char suit, value; };

void print(struct Card C[], int N);
void bubbleSort(struct Card C[], int N);
void selectionSort(struct Card C[], int N);
bool isStable(struct Card C1[], struct Card C2[], int N);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_C
 */
int main() {
  int i, N;
  struct Card C1[MAX], C2[MAX];

  cin >> N;
  for (i = 0; i < N; i++) cin >> C1[i].suit >> C1[i].value;

  for (i = 0; i < N; i++) C2[i] = C1[i];

  bubbleSort(C1, N);
  print(C1, N);
  cout << "Stable" << endl;

  selectionSort(C2, N);
  print(C2, N);
  if (isStable(C1, C2, N)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  return 0;
}

/* Print all entries in single line to standard output */
void print(struct Card C[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";  // Print a white space right to an entry
    cout << C[i].suit << C[i].value;
  }
  cout << endl;
}

/* Perform a bubble sort on an array */
void bubbleSort(struct Card C[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = N-1; j > i; j--) {
      if (C[j].value < C[j-1].value) {
        swap(C[j], C[j-1]);
      }
    }
  }
}

/* Perform a selection sort on an array */
void selectionSort(struct Card C[], int N) {
  int min_j;

  for (int i = 0; i < N - 1; i++) {
    min_j = i;
    for (int j = i; j < N; j++) {
      if (C[j].value < C[min_j].value ) min_j = j;
    }
    swap(C[i], C[min_j]);
  }
}

/* Check whether or not a selection sort is stable */
bool isStable(struct Card C1[], struct Card C2[], int N) {
  for (int i = 0; i < N; i++) {
    if ( C1[i].suit != C2[i].suit ) return false;
  }

  return true;
}
