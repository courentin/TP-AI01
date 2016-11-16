#ifndef TP3
#define TP3
#define N_MAX 5

typedef struct Element {
  char data[N_MAX];
  struct Element * next;
}Element;

typedef struct List {
  Element * head;
  Element * tail;
}List;

List *initialize();

Element *create_empty_element();

List *create_list(char *str);

int is_empty_list(List *list);

/**
 * Retourne 0 si l'element est un element vide, -1 sinon
 */
int is_empty_el(Element *element);

int remove_element(List *list, int p);

void destruct_element(Element* el);

void insert_empty_list(List *list, char *str);

void insert_begining_list(List *list, char *str);

void insert_end_list(List *list, char *str);

int insert_after_position(List *list, char *str, int p);

void display(List *list);

int compare(char *str1, char *str2);

void destruct(List* list);

void insert_empty_list (List *list, char *str);

Element *get_element_at_position(List *list, int p);

#endif
