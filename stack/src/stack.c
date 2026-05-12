/**
*@file : stack.c
*@brief: prototype of function
*/

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h> //NULL, size_t
#include <stdlib.h> //allo
#include "..\include\stack.h"

Stacks def_new_stacks(void){
    return NULL;
}

bool is_empty_stacks(Stacks pst){
    return (pst == def_new_stacks());
}

Stacks push_stack(Stacks pst, int v){
    Stack *ns = calloc(1, sizeof(*ns));

    if(!ns){
        fputs("In func push_stack: Echec of allo ns !\n",
            stderr);
        free(ns);
        ns = NULL;
    }

    if(!ns)
        return pst;

    ns->x    = v;
    ns->next = pst;

    return ns;
}


void *free_stacks(Stacks pst){
    if (is_empty_stacks(pst))
        return NULL;
    /*Peu etre ameliorer avec pop*/
    Stacks tmp = pst->next;
    free(pst);

    return free_stacks(tmp);
}


void print_stacks(Stacks pst){
    if(is_empty_stacks(pst)){
        puts("[STACK EMPTY]");
        return;
    }

    printf("[%d] -> ", pst->x);
    pst = pst->next;

    print_stacks(pst);
}

Stacks pop_stack(Stacks  pst){
    if(is_empty_stacks(pst)){
        return pst;
    }

    Stacks tmp = pst;
    pst = pst->next;
    free(tmp);

    return pst;
}

size_t high_stacks(Stacks pst){
    if(is_empty_stacks(pst))
        return 0;

    size_t len = 0;
    while(!is_empty_stacks(pst)){
        len ++;
        pst = pst->next;
    }

    return len;
}
