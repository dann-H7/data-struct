#ifndef __STACK_H__
#define __STACK_H__

/**
 * @file  : stack.h
 * @brief : prototype of function
 * @author: Kelvin A.GNANOU
 * @date  : 2025-11-18 17:40
 */

#include <stdbool.h>
#include <stddef.h>

typedef struct St {
    int x;
    struct St *next;
} Stack, *Stacks;

/** *@TODO: Commenter les APIs */
Stacks def_new_stacks(void);/*Return NULL*/
bool is_empty_stacks(Stacks pst);
Stacks push_stack(Stacks pst, int v);
void *free_stacks(Stacks pst);
void print_stacks(Stacks pst);
Stacks pop_stack(Stacks  pst);
size_t high_stacks(Stacks pst);

#endif /*__STACK_H__*/
