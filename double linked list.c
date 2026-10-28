 1 #include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct node {
  5     int data;
  6     struct node *prev, *next; };
  7
  8 struct node *head = NULL;
  9
 10 void insertBegin(int x) {
 11     struct node *n = malloc(sizeof(struct node));
 12     n->data = x;
 13     n->prev = NULL;
 14     n->next = head;
 15
 16     if (head != NULL)
 17         head->prev = n;
 18
 19     head = n;
 20 }
 21
 22 void insertEnd(int x) {
 23     struct node *n = malloc(sizeof(struct node));
 24     n->data = x;
 25     n->next = NULL;
 26
 27     if (head == NULL) {
 28         n->prev = NULL;
 29         head = n;
 30         return;
 31     }
 32
 33     struct node *t = head;
 34     while (t->next != NULL)
 35         t = t->next;
 36
 37     t->next = n;
 38     n->prev = t;
 39 }
 40
 41 void displayForward() {
 42     struct node *t = head;
 43
 44     while (t != NULL) {
 45         printf("%d ", t->data);
 46         t = t->next;
 47     }
 48     printf("\n");
 49 }
 50
