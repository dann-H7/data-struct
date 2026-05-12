/**
 * @file   : main.c
 * @brief  : List implementation
 * @author : Kelvin GNANOU

 * @date  : 2026/04/09 00:01
 * @note  : 
 * @todo  : 
 */

#include <stdio.h>
#include "../include/list.h"


int main(void){
    List *list = list_init();
    list_print(list); putchar('\n');

    list_push_front(list, 0);
    list_push_front(list, 4);
    list_push_front(list, 9);
    list_push_front(list, 4);
    list_push_front(list, -8);
    list_print(list); putchar('\n');

    list_delete_elem_right(list, 4);
    list_print(list); putchar('\n');

    list_destroy(&list);
    return 0;
}
