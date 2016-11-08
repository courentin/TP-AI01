#include "tp3.h"
#include <stdio.h>

/*
void insert_empty_list(List *list, char *str){
	int indice;
	char* chaine = str;
	char new_chaine;
	char chiffre;
	Element *elem;

	elem = malloc(sizeof(Element));
	list->head = elem;

	while(chiffre != '\0'){

		if(elem->next != NULL)
			elem = elem->next;

		chiffre = chaine[0];
		new_chaine = malloc(5*sizeof(char));
		for(indice=0; indice < N_MAX && chiffre != '\0'; indice++){
			new_chaine[indice] = chiffre;
			chiffre = chaine[1];
		}

		elem->data = new_chaine;
		elem->next = malloc(sizeof(Element));
	}


	list->tail = elem;
}
*/

void insert_begining_list(List *list, char *str) {
	
}

void initialize(List *list) {
  list->head = NULL;
  list->tail = NULL;
}

void display(List *list) {
  if(list->head == NULL) {
    printf("EMPTY LIST\n");
    return;
  }
  Element *current = list->head;

  while(list->tail != current) {
    if(current->data[0] == '\0') {
      printf("\n");
    } else {
      printf("%s", current->data);
    }
    current = current->next;
  }
}
