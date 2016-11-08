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

void display(List *list);

#endif
