#include "tp3.h"
#include <stdlib.h>
#include <stdio.h>

char *askNumber() {
  printf("Nombre à ajouter : ");

}

int main(int argc, char const *argv[]) {
  List *list = initialize();
  int quit = 0, choice;

  while(quit != 1) {
    printf("Selectionner une action :\n");
    printf("  [1] ajouter un nombre en début de liste\n");
    printf("  [2] ajouter un nombre en fin de liste\n");
    printf("  [3] ajouter un nombre à une certaine position dans la liste\n");
    printf("  [4] supprimer un nombre d’une certaine position de la liste\n");
    printf("  [5] trier la liste par ordre croissant\n");
    printf("  [6] afficher la liste\n");
    printf("  [7] détruire la liste toute entière\n");
    printf("  [8] quitter\n");

    fflush(stdin);
    scanf("%d", &choice);
    while(choice < 1 || choice > 8) {
      printf("Action inconnue, réessayez :\n");
      fflush(stdin);
      scanf("%d", &choice);
    }

    switch (choice) {
      case 1:
        //char *input;


        //scanf("%s\n", );
      break;

      case 6: // Est affiché à chaque itérations
      break;

      case 8:
        quit = 1;
      break;

      default:
        printf("Program error, exit.\n");
        return 1;
    }

    if(quit != 1)
      display(list);
  }

  return 0;

  insert_empty_list(list, "77777");
  insert_begining_list(list, "123456789");
  insert_begining_list(list, "123");
  insert_end_list(list, "5555555");

  display(list);

  insert_after_position(list, "0000", 2);
  //display(list);

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
