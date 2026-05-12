#ifndef __QUEUE_H__
#define __QUEUE_H__

// NOTE: Ne peut que gerer une file a la fois - usage de variable static !

/* include of .h utils */
#include <stddef.h>  // size_t
#include <stdbool.h> // bool

/* queue structure */
typedef struct QUEUE Queue, *Pqueue;

/* define api fonctions */
void init_queue(void);
size_t queue_length(void);
bool is_empty_queue(void);
bool enqueue(int new_element);
bool dequeue(void);
bool print_queue(void);
void empty_queue(void);
// TODO - fonctions de gestion du n-ieme element

#endif /*__QUEUE_H__*/
