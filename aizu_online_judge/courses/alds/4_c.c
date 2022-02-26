#include <stdio.h>
#include <string.h>

#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];

int getChar(char ch);
long long createKey(char str[]);
int hash_1(int key);
int hash_2(int key);
int insert(char str[]);
int search(char str[]);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_C
 */
int main() {
  int i, n, h;
  char str[L], command[9];

  for (i = 0; i < M; i++) H[i][0] = '\0';

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", command, str);
    if (command[0] == 'i') insert(str);
    else {
      if (search(str)) printf("yes\n");
      else printf("no\n");
    }
  }

  return 0;
}

/* Convert character to integer */
int getChar(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;

  return 0;
}

long long createKey(char str[]) {
  long long sum = 0, p = 1;
  for (int i = 0; i < strlen(str); i++) {
    sum += p*(getChar(str[i]));
    p *= 5;
  }
}

int hash_1(int key) {return key % M;}
int hash_2(int key) {return 1 + (key % (M-1));}

int insert(char str[]) {
  long long key, h;
  key = createKey(str);  // convert string to integer
  for (int i = 0; ; i++) {
    h = (hash_1(key) + i*hash_2(key)) % M;
    if (strcmp(H[h], str) == 0) return 1;  // string or key already stored
    else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}

int search(char str[]) {
  long long key, h;
  key = createKey(str);  // convert string to integer
  for (int i = 0; ; i++) {
    h = (hash_1(key) + i*hash_2(key)) % M;
    if (strcmp(H[h], str) == 0) return 1;  // string or key already stored
    else if (strlen(H[h]) == 0) return 0;  // string or key not found
  }
  return 0;
}
