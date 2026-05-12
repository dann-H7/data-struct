

#include "../include/binary_tree.h"

int main(void){
    Tree* mytree = create_tree();

    print_tree(mytree, 0);

    *mytree = insert_bst(mytree, 6);
    *mytree = insert_bst(mytree, 9);
    *mytree = insert_bst(mytree, 0);
    *mytree = insert_bst(mytree, -4);

    print_tree(mytree, 0);

    destroy_tree(&mytree);
    print_tree(mytree, 0);
}
