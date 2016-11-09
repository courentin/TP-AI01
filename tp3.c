#include "tp3.h"
#include <stdio.h>
#include <stdlib.h>


void insert_empty_list(List *list, char *str) {
	List *new_list = create_list(str);
	Element *empty_el = create_empty_element();

	new_list->tail->next = empty_el;
	empty_el->next = list->head;
	list->head = new_list->head;
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

		if(is_empty_el(current) && ++current_p == p) {
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

void destruct_element(Element* el){
	free(el);
}

int remove_element(List *list, int p){
	int i;
	Element *debut = list->head, *fin, *enCours = list->head;

	if(is_empty_list(list))
		return -1;
	
	for(i = 1; i < p;){
		if(enCours != list->tail)
			return -1;
		if(is_empty_el(enCours)){
			debut = enCours;
			i++;
		}
		enCours = enCours->next;
	}
	
	for(i = 0; !is_empty_el(enCours);){
		fin = enCours;	
		enCours = enCours->next;
		destruct_element(fin);
	}
	
	debut->next = enCours->next;
	if(enCours == list->tail){
		list->tail = debut;
		destruct_element(enCours);
	}
	return 0;
}

int remove_el(List *list, int p) {
	int success = -1;
	/*
	Element *current = list->head;

	if(p == 1) {
		list->head = list->head->next;
		succes = 0;
	} else {
			while(list->tail != current && success != 0) {

				if(current->next != NULL && current->next->data[0] == '\0' && ++current_p == p)
					Element *before = current;

					while(current->next != NULL && success != 0) {
						current = current->next;
						if(current->next->data[0] == '\0') {

							succes = 0;
						} else {
							current = current->next;
						}
					}

					before->next = current;
				}
			}
	}
	*/
	return success;
}

void display(List *list) {
  if(list->head == NULL) {
    printf("EMPTY LIST\n");
    return;
  }
  Element *current = list->head;

  while(list->tail != current) {
    if(is_empty_el(current)) {
      printf("\n");
    } else {
      printf("%s", current->data);
    }
    current = current->next;
  }
}
