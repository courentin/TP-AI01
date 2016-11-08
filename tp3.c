#include "tp3.h"
#include <stdio.h>
#include <stdlib.h>

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

/**
 * Créer une List d'Elements à partir de str quelconque
 */
List * create_list(char *str) {
	List * list = initialize();
	Element *current = NULL, *old = NULL;

	int i = 0;

	while(str[i] != '\0') {
		if(i % N_MAX == 0) {
			old = current;
			current = malloc(sizeof(Element));

			if(i != 0)
				old->next = current;
			else
			  list->head = current;
		}
		current->data[i % N_MAX] = str[i];
		i++;
	}
	list->tail = current;

	return list;
}

Element *create_empty_element() {
	Element *element = malloc(sizeof(Element));
	element->data[0] = '\0';
	element->next = NULL;

	return element;
}

void insert_begining_list(List *list, char *str) {
	List *new_list = create_list(str);
	Element *empty_el = create_empty_element();

	new_list->tail->next = empty_el;
	empty_el->next = list->head;
	list->head = new_list->head;
}

List* initialize() {
	List *list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;

	return list;
}

int insert_after_position(List *list, char *str, int p) {
	int current_p = 0, success = -1;
	Element *current = list->head;

	while(list->tail != current && success != 0) {

		if(current->data[0] == '\0' && ++current_p == p) {
				List *new_list = create_list(str);
				Element *empty_el = create_empty_element();

				empty_el->next = current->next;
				current->next = new_list->head;
				new_list->tail->next = empty_el;

				success = 0;
		}
		current  = current->next;
	}

	return success;
}

int compare(char *str1, char *str2) {
	int int1 = atoi(str1);
	int int2 = atoi(str2);
	if(int1 > int2) {
		return 1;
	} else if(int2 > int1) {
		return 2;
	} else {
		return 0;
	}
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
