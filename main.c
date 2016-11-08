#include "tp3.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  List *list = initialize();


  insert_begining_list(list, "123456789");
  insert_begining_list(list, "123");

  display(list);

  int aa = insert_after_position(list, "0000", 2);
  printf("%d\n", aa);
  display(list);

  // #7
  int comp1 = compare("1234", "1234");
  int comp2 = compare("2234", "1234");
  int comp3 = compare("1234", "2234");

  if(comp1 == 0 && comp2 == 1 && comp3 == 2)
    printf("[7] OK\n");
  else
    printf("[7] KO\n");

    

  return 0;
}
