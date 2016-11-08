#include "tp3.h"
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  List *list = malloc(sizeof(List));
  initialize(list);

  insert_begining_list(list, "123456789");
  insert_begining_list(list, "12345678910");

  display(list);

  return 0;
}
