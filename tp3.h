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

List *create_list(char *str);

void insert_begining_list(List *list, char *str);

int insert_after_position(List *list, char *str, int p);

int remove_el(List *list, int p);

void display(List *list);

int compare(char *str1, char *str2);

Element *get_element_at_position(List *list, int p);

#endif
