
#include <stdio.h>
#include "../include/binary_tree.h"

int main(void){
    Tree* mytree = create_tree();

    print_tree(mytree, 0); putchar('\n');

    *mytree = insert_bst(mytree, 6);
    *mytree = insert_bst(mytree, 9);
    *mytree = insert_bst(mytree, 0);
    *mytree = insert_bst(mytree, -4);

    print_tree(mytree, 0);

    printf("\nleafs  : %zu\n", leaf_numbers(mytree));
    printf("\nnodes  : %zu\n", node_numbers(mytree));
    printf("\nheaoght: %d\n", tree_height(mytree));

    destroy_tree(&mytree);
    return 0;
}
