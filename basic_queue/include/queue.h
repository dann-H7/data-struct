
#ifndef _QUEUE_H_
#define _QUEUE_H_

/// @NOTE: Can manage only on one file once

/* include of .h utils */
#include <stddef.h>  // size_t
#include <stdbool.h> // bool

/* queue structure */
typedef struct QUEUE Queue, *Pqueue;

/* APIs */
void init_queue(void);
size_t queue_length(void);
bool is_empty_queue(void);
bool enqueue(int new_element);
bool dequeue(void);
bool print_queue(void);
void empty_queue(void);

#endif /*_QUEUE_H_*/
