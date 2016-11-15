#include "tp3.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void askNumber(char *input) {
  printf("Nombre à ajouter : \n");
  read(0, input, sizeof(input));
  int len = strlen(input);
  input[len-1] = '\0';
}

void free_buffer() {
  //  fflush(stdin);
  char c = '0';
  do {
    c = getchar();
  } while (!isdigit(c));
  ungetc(c, stdin);
}

int askNumberBetween(int min, int max) {
  int choice;

  fflush(stdin);
  while(!scanf("%d", &choice) || choice < min || choice > max) {
    printf("Action inconnue, réessayez :\n");
    //free_buffer();
  }

  return choice;
}

int main(int argc, char const *argv[]) {
  List *list = initialize();
  int quit = 0, choice;
  char *input = malloc(256 * sizeof(char));

  while(!quit) {
    printf("Selectionner une action :\n");
    printf("  [1] ajouter un nombre en début de liste\n");
    printf("  [2] ajouter un nombre en fin de liste\n");
    printf("  [3] ajouter un nombre à une certaine position dans la liste\n");
    printf("  [4] supprimer un nombre d’une certaine position de la liste\n");
    printf("  [5] trier la liste par ordre croissant\n");
    printf("  [6] afficher la liste\n");
    printf("  [7] détruire la liste toute entière\n");
    printf("  [8] quitter\n");

    choice = askNumberBetween(1, 8);

    switch (choice) {
      case 1:
        askNumber(input);
        if(is_empty_list(list)) {
          insert_empty_list(list, input);
        } else {
          insert_begining_list(list, input);
        }
      break;

      case 2:
        askNumber(input);
        if(is_empty_list(list)) {
          insert_empty_list(list, input);
        } else {
          insert_end_list(list, input);
        }
      break;

      case 3:
        if(is_empty_list(list)) {
          printf("Impossible, la liste est vide\n");
        } else {
          askNumber(input);
          int position;
          printf("Ajouter après la position : ");
          scanf("%d", &position);
          if(!insert_after_position(list, input, position)) {
            printf("La position %d n'existe pas\n", position);
          }
        }
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

    if(quit != 1) {
      printf("-----------------\nLISTE :\n");
      display(list);
      printf("-----------------\n");
    }
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
