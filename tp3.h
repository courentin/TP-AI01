#define N_MAX 5

typedef struct Element {
  char data[N_MAX];
  struct Element * next;
}Element;

typedef struct List {
  Element * head;
  Element * tail;
}List;
