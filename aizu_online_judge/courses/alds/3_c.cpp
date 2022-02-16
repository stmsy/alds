#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
  int key;
  Node *next, *prev;
};

// Define a pointer for a sentinel
Node *nil;

void init();
Node* listSearch(int key);
void printList();
void deleteNode(Node *t);
void deleteFirstNode();
void deleteLastNode();
void deleteKey(int key);
void insertNode(int key);

/**
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_C
 */
int main() {
  int key, n;
  char command[20];

  scanf("%d", &n);
  init();
  for (int i = 0; i < n; i++) {
    scanf("%s %d", command, &key);  // Faster than 'cin'
    if (command[0] == 'i') insertNode(key);
    else if (command[0] == 'd') {
      if (strlen(command) > 6) {
        if (command[6] == 'F') deleteFirstNode();
        else if (command[6] == 'L') deleteLastNode();
      } else {
        deleteKey(key);
      }
    }
  }

  printList();

  return 0;
}

/* Initialize a sentinel for a doubly-linked list */
void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

/* Perform a search and return the first node with the specified key */
Node* listSearch(int key) {
  Node *cur = nil->next;  // Start from the beginning;
  while (cur != nil && cur->key != key) cur = cur->next;

  return cur;
}

/* Print all the nodes in the list */
void printList() {
  Node *cur = nil->next;
  int is_not_first = 0;

  while (true) {
    if (cur == nil) break;
    if (is_not_first++ > 0) printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

/* Delete the specified node in the list */
void deleteNode(Node *t) {
  if (t == nil) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

/* Delete the first node in the list */
void deleteFirstNode() {
  deleteNode(nil->next);
}

/* Delete the last node in the list */
void deleteLastNode() {
  deleteNode(nil->prev);
}

/* Delete the first node with specified key */
void deleteKey(int key) {
  deleteNode(listSearch(key));
}

/* Insert the node at the beginning of a list */
void insertNode(int key) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->key = key;
  // Insert the node right after the sentinel
  node->next = nil->next;
  nil->next->prev = node;
  nil->next = node;
  node->prev = nil;
}
