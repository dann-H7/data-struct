/**
*@file : main.c
*@brief: the main file of stack implementation
*/

#include <stdio.h>
#include "..\include\stack.h"

int main(void){
    puts("\n[START OF PROGRAM]\n");

    Stacks pst = def_new_stacks();
    print_stacks(pst);
    printf(">>> Longeur de la pile actuelle: %zu \n\n",
         high_stacks(pst));

    pst = push_stack(pst,  11);
    pst = push_stack(pst, -13);
    pst = push_stack(pst,  15);
    pst = push_stack(pst, 123);
    print_stacks(pst);
    printf(">>> Longeur de la pile actuelle: %zu \n\n",
         high_stacks(pst));

    pst = pop_stack(pst);
    print_stacks(pst);
    printf(">>> Longeur de la pile actuelle: %zu \n\n",
         high_stacks(pst));

    pst = free_stacks(pst);
    print_stacks(pst);
    printf(">>> Longeur de la pile actuelle: %zu \n\n",
         high_stacks(pst));
    puts("\n[END  OF  PROGRAM]\n");
    return 0;
}
