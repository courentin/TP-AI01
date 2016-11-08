#include "tp3.h"
#include <stdio.h>
// 1
void initialize(List *list) {
  list->head = NULL;
  list->tail = NULL;
}

void display(List *list) {
  if(list->head == NULL) {
    printf("EMPTY LIST\n");
  }
  Element *current = list->head;

  while(list->tail != current) {
    if(current == NULL) {
      printf("\n");
    }
    printf("%s", current->data);
    current = current->next;
  }

}
