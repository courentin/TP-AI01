#include "tp3.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  List *list = initialize();


  insert_begining_list(list, "123456789");
  insert_begining_list(list, "123");

  display(list);

  return 0;
}
