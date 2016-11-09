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

void insert_empty_list(List *list, char *str) {
	List *new_list = create_list(str);
	Element *empty_el = create_empty_element();

	list->head = new_list->head;
	new_list->tail->next = empty_el;
	list->tail = empty_el;
}

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

int is_empty_list(List *list) {
	return list->head == NULL && list->tail == NULL;
}

int is_empty_el(Element *element) {
	return element->data[0] == '\0';
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


void insert_end_list(List *list, char *str) {
	List *new_list = create_list(str);
	Element *empty_el = create_empty_element();

	list->tail->next = new_list->head;
	new_list->tail->next = empty_el;
	list->tail = empty_el;
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
		printf("empty ? : %d\n", is_empty_el(current));
		printf("current_p ? : %d\n", current_p+1);
		printf("p ? : %d\n", p);
		if(is_empty_el(current->next) && ++current_p == p) {
				List *new_list = create_list(str);
				Element *empty_el = create_empty_element();

				current->next = new_list->head;
				new_list->tail->next = empty_el;
				empty_el->next = current->next;
				list->tail = empty_el;

				// si on ajoute à la dernière place, modifier le tail
				printf("JE PASSE ICI\n");
				if(list->tail == current->next) {
					printf("JE PASSE LÀ\n");
				}

				success = 0;
		}
		current = current->next;
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
	int i = 1;
	printf("[%d] -> ", i);
  while(list->tail != current) {
    if(is_empty_el(current)) {
			printf("\n[%d] -> ", ++i);
    } else {
      printf("%s", current->data);
    }
    current = current->next;
  }
	printf("\n");
}
