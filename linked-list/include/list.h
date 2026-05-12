
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

/* opaue structure */
typedef struct List List;

/* Lifecycle */
List *list_init(void);
void list_destroy(List **list);

/* Capacity */
bool is_empty_list(List *list);
size_t list_length(List *list);

/* utilities */
int list_clear(List *list);
int list_print(List *list);

/* modifiers */
int list_push_front(List *list, int data);
int list_push_back(List *list, int data);

int list_pop_front(List *list, int *out_value);
int list_pop_back(List *list, int *out_value);

int list_delete_elem_left(List *list, int elem);
int list_delete_elem_right(List *list, int elem);
int list_delete_elements(List *list, int elem); /// @TODO: TO complete

#endif /* LIST_H */
