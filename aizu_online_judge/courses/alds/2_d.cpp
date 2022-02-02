#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static const int MAX = 1000000;
long long counter;
int A[MAX];
int n;
vector<int> G;

void print(int A[]);
void insertionSort(int A[], int n, int g);
void shellSort(int A[], int n);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_D
 */
int main() {
  int i;

  cin >> n;
  for (i = 0; i < n; i++) scanf("%d", &A[i]);  // Read inputs faster

  counter = 0;
  shellSort(A, n);

  cout << G.size() << endl;
  print(A);

  return 0;
}

/* Print G and a sorted array to standard output */
void print(int A[]) {
  int i;

  for (i = G.size()-1; i >= 0; i--) {
    printf("%d", G[i]);
    if (i > 0) printf(" ");
  }

  printf("\n");
  printf("%d\n", counter);
  for (i = 0; i < n; i++) printf("%d\n", A[i]);
}

/* Perform a g-skipped insertion sort on an array */
void insertionSort(int A[], int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;

    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      counter++;
    }
    A[j + g] = v;
  }
}

/* Perform a shell sort on an array */
void shellSort(int A[], int n) {
  // Generate a sequence G = {1, 4, 13, 40, 121, ...}
  for (int h = 1; ; ) {
    if (h > n) break;
    G.push_back(h);
    h = 3 * h + 1;
  }

  for (int i = G.size()-1; i >= 0; i--) insertionSort(A, n, G[i]);
}
