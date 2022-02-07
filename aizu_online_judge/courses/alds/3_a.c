#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int x);
int pop();

int top;
int S[1000];

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_A
 */
int main() {
  int a, b;
  char s[100];  // Sting to store operand or operation

  top = 0;
  while (scanf("%s", s) != EOF) {
    // '+', '-', and '*' are string of length 1
    if (s[0] == '+') {
      b = pop();
      a = pop();
      push(a + b);
    } else if (s[0] == '-') {
      b = pop();
      a = pop();
      push(a - b);
    } else if (s[0] == '*') {
      b = pop();
      a = pop();
      push(a * b);
    } else {
      push(atoi(s));
    }
  }

  printf("%d\n", pop());

  return 0;
}

/* Store the value at the end of array */
void push(int x) {
  // Increment top by one and store x at top
  S[++top] = x;
}

int pop() {
  // Decrement top by one and return the value stored at top
  top--;

  return S[top+1];
}
