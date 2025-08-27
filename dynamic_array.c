#include <stdio.h>

typedef struct {
  int *data;
  int capacity;
  int size;
} Array;

void init(Array *a) {
  a->data = malloc(3 * sizeof(int));
  a->capacity = 3;
  a->size = 0;
}

void insert_end(Array *a, int value) {
  if (a->size == a->capacity) {
    a->capacity *= 2;
    a->data = realloc(a->data, sizeof(int) * a->capacity);
  }
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
  printf("%d\n", arr.capacity);
  insert_end(&arr, 30);
  printf("%d\n", arr.capacity);
  insert_end(&arr, 90);

  print(&arr);

  remove_last(&arr);

  print(&arr);

  free(arr.data);
  return 0;
}
