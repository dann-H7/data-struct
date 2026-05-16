
#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct St {
    int x;
    struct St *next;
} Stack, *Stacks;

Stacks def_new_stacks(void);
bool is_empty_stacks(Stacks pst);
Stacks push_stack(Stacks pst, int v);
void *free_stacks(Stacks pst);
void print_stacks(Stacks pst);
Stacks pop_stack(Stacks  pst);
size_t high_stacks(Stacks pst);

#endif /*_STACK_H_*/
