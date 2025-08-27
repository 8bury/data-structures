#include <stdio.h>
#define MAX 5

typedef struct {
  int data[MAX];
  int size;
} Array;

void init(Array *a) { a->size = 0; }

void insert_end(Array *a, int value) {
  if (a->size >= MAX)
    return;
  a->data[a->size] = value;
  a->size++;
  return;
}

void remove_last(Array *a) {
  if (a->size == 0)
    return;
  a->size--;
  return;
}

void print(Array *a) {
  for (int i = 0; i < a->size; i++) {
    printf("[%d] - %d\n", i, a->data[i]);
  }
  return;
}

int main() {
  Array arr;
  init(&arr);

  insert_end(&arr, 10);
  insert_end(&arr, 20);
  insert_end(&arr, 40);
  insert_end(&arr, 30);
  insert_end(&arr, 90);

  print(&arr);

  remove_last(&arr);

  print(&arr);

  return 0;
}
