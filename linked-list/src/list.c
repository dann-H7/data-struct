/**
 * @file   : list.c
 * @brief  : 
 * @author : Kelvin GNANOU

 * @date  : 2026/05/16 10:12
 * @note  : 
 * @todo  : 
    complete list_delete_elements
    documented API (-1 == LIST_NOT_EXIST...) 
        and typedef enum {
            LIST_OK,
            LIST_ERR_ALLOC,
            LIST_ERR_EMPTY,
            LIST_ERR_RANGE
        } ListStatus;
    implemente:
        int list_front(List *list, int *out_value);
        int list_back(List *list, int *out_value);
        int list_insert_at(List *list, size_t index, int data);
        bool list_contains(List *list, int value);
        int list_find(List *list, int value);
        int list_get(List *list, size_t index, int *out_value);
        int list_set(List *list, size_t index, int value);
        int list_reverse(List *list);
        int list_sort(List *list);
        List *list_copy(List *list);
        int list_concat(List *dest, List *src);

 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

#include "../include/list.h"

/* Internal structs */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct List {
    Node *head;
    Node *tail;
    size_t size;
};

/* Internal helpers */
Node *node_create(int value){
    Node *node = calloc(1, sizeof(*node));
    if(!node) return NULL;

    node->data = value;
    node->next = NULL;

    return node;
}

/* Public APIs */
List *list_init(void){
    List *list = calloc(1, sizeof(*list));
    if(!list) return NULL;

    /* Don't need that by using calloc */
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}


void list_destroy(List **list){
    if(!list || !(*list)) return;

    list_clear(*list);

    free(*list);
    *list = NULL;
}


/* list state */
/// @NOTE: Head is already suf
bool is_empty_list(List *list){
    return !list || (!list->head && !list->tail && !list->size);
}


size_t list_length(List *list){
    return list ? list->size : 0;
}

/* utilities */
int list_clear(List *list){
    if(is_empty_list(list)) return 1;
    
    Node *current = list->head;

    while(current){
        Node *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return 0;
}

int list_print(List *list){
    if (!list) return -1;

    if (is_empty_list(list)){
        printf("[ ]");
        return 1;
    }

    printf("[");
    
    Node *current = list->head;
    while (current){
        printf("%d", current->data);
        if (current->next){
            printf(", ");
        }
        current = current->next;
    }

    printf("]");
    return 0;
}

/* Modification */
// add
int list_push_front(List *list, int data){
    if(!list) return -1;

    Node *node = node_create(data);
    if(!node) return -2;

    if (!list->head)
        list->tail = node;

    node->next = list->head;
    list->head = node;
    list->size ++;

    return 0;
}

int list_push_back(List *list, int data){
    if (!list) return -1;

    Node *node = node_create(data);
    if (!node) return -2;

    if (list->head) {
        list->tail->next = node;
    } else {
        list->head = node;
    }

    list->tail = node;
    list->size++;

    return 0;
}

// delete
int list_pop_front(List *list, int *out_value){
    if(is_empty_list(list)) return 1;

    Node *head = list->head;

    if(out_value) /// @NOTE: The caller must verify out_value address
        *out_value = head->data;

    if(list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    } else {
       list->head = list->head->next; 
    }
    list->size --;

    free(head);
    return 0;
}


int list_pop_back(List *list, int *out_value){
    if(is_empty_list(list)) return 1;

    Node *tail = list->tail;

    if(out_value)
        *out_value = tail->data;

    if(list->head == list->tail){
        list->head = NULL; // 
        list->tail = NULL;
    } else {
        Node *current = list->head;

        while (current->next != tail)
            current = current->next;
        
        current->next = NULL; // Being the last element
        list->tail = current;
    }
    
    free(tail);
    list->size --;
    return 0;
}


int list_delete_elem_left(List *list, int elem){
    if(is_empty_list(list)) return 1;
    
    Node *head = list->head;
    if(list->head == list->tail){
        if(list->head->data != elem) return 2;

        Node *node_of_elem = head;

        list->head = NULL;
        list->tail = NULL;
        list->size--; // list->size = 0

        free(node_of_elem);
        return 0;
    }

    Node *node_of_elem = NULL;
    if (head->data == elem){
        node_of_elem = head;
        list->head = head->next;
    } else {
        while (head->next && head->next->data != elem)
            head = head->next;

        if (!head->next) return 2;

        node_of_elem = head->next;
        head->next = head->next->next;
        
    }
    list->size--;

    if (head->next == list->tail)
        list->tail = head;
    
    free(node_of_elem);
    return 0;
}



int list_delete_elem_right(List *list, int elem){
    if(is_empty_list(list)) return 1;

    Node *head = list->head;
    if(list->head == list->tail){
        if(list->head->data != elem) return 2;

        Node *node_of_elem = head;

        list->head = NULL;
        list->tail = NULL;
        list->size--; // list->size = 0

        free(node_of_elem);
        return 0;
    }

    Node *node_of_elem = NULL;
    if (head->data == elem)
        node_of_elem = head;
    
    Node *preview = NULL;
    Node *current = head;
    while(current->next){
        if (current->next->data == elem){
            preview = current;
            node_of_elem = current->next;
        }
        current = current->next;
    }

    if (!node_of_elem) return 2;

    if (node_of_elem == head){
        list->head = head->next;
    } else {
        if (node_of_elem == list->tail)
            list->tail = preview;
        if (preview) // Can delete this
            preview->next = preview->next->next;
    }
    list->size --;
    free(node_of_elem);
    return 0;
}

/// @TODO: TO check
int list_delete_elements(List *list, int elem){
    if(is_empty_list(list)) return 1;

    Node *head = list->head;
    if(list->head == list->tail){ /// @TODO: use epsilone
        if(list->head->data != elem) return 2;

        Node *node_of_elem = head;

        list->head = NULL;
        list->tail = NULL;
        list->size--; // list->size = 0

        free(node_of_elem);
        return 0;
    }

    Node *preview = NULL;
    Node *current = head;
    while(current){
        Node *element = NULL;
        if(current->data == elem){
            element = current;
            preview->next = current->next;
        } else {
            preview = current;
        }
        current = current->next;
        free(element);
    }
    return -111111;
}
