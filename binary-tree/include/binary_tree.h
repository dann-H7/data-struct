
#ifndef BINARY_TREE
#define BINARY_TREE

#include <stddef.h>
#include <stdbool.h>

/* Internal struct */
typedef struct Node *Tree;

/* Lyfe cycle */
Tree *create_tree(void);
void destroy_tree(Tree **root);

/* Traversal */
void inorder(Tree *root);   // In-Order taversal
void preorder(Tree *root);  // Pre-Order traversal
void postorder(Tree *root); // Post-Order traversal
void print_tree(Tree *root, int mode);

/* Getters */
size_t leaf_numbers(Tree *root);
size_t tree_depth(Tree *root);
size_t tree_height(Tree *root);

/* setters */
Tree insert_bst(Tree *root, int data);

/* utils */
Tree create_node(int data);
void clear_tree(Tree *root);
bool is_empty_tree(Tree *root);

#endif /* BINARY_TREE */
