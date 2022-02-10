#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

/* Struct to reprent a process */
typedef struct process {
  char name[100];
  int t;
} P;

void enqueue(P x);
P dequeue();
int min(int a, int b);

P Q[MAX];
int head, tail, n;

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_B
 */
int main() {
  int accum_time_elapsed = 0, temp_time_elapsed;
  int q;
  P p;

  scanf("%d %d", &n, &q);

  for (int i = 1; i <= n; i++) {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }
  head = 1;
  tail = n + 1;

  while (head != tail) {
    p = dequeue();
    temp_time_elapsed = min(q, p.t);
    p.t -= temp_time_elapsed;
    accum_time_elapsed += temp_time_elapsed;
    if (p.t > 0) enqueue(p);  // Add to queue if process not completed
    else printf("%s %d\n", p.name, accum_time_elapsed);
  }

  return 0;
}

void enqueue(P x) {
  Q[tail] = x;
  tail = (tail + 1) % MAX;
}

P dequeue() {
  P x = Q[head];
  head = (head + 1) % MAX;

  return x;
}

int min(int a, int b) {return a < b ? a : b;}
