
/**
 * @file   : tree.c
 * @brief  : tree implemante
 * @author : Kelvin GNANOU

 * @date  : 2026/04/22 19:37
 * @note  : 
 * @todo  : 
    Tree search_bst(Tree *root, int data); 
    bool contains(Tree *root, int data);
    bool remove_bst(Tree *root, int data);
    Tree min_node(Tree *root);
    Tree max_node(Tree *root);
    size_t tree_size(Tree *root);
    bool is_bst(Tree *root);
    bool is_bst(Tree *root);   
 */


#include "../include/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>


/* Internal struct */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


/* lifecycle */
Tree *create_tree(void){
    Tree *tree = malloc(sizeof(*tree));
    if(!tree) return NULL;

    *tree = NULL;
    return tree;
}


void destroy_tree(Tree **root){
    if(!root || !(*root)) return;

    clear_tree(*root);
    *root = NULL;
}


/* traversal */
void inorder(Tree *root){
    if(is_empty_tree(root)) return;

    inorder(&(*root)->left);
    printf("%d` ", (*root)->data);
    inorder(&(*root)->right);
}


void preorder(Tree *root){
    if(is_empty_tree(root)) return;

    printf("%d` ", (*root)->data);
    preorder(&(*root)->left);
    preorder(&(*root)->right);  
}


void postorder(Tree *root){
    if(is_empty_tree(root)) return;

    postorder(&(*root)->left);
    postorder(&(*root)->right);  
    printf("%d` ", (*root)->data);
}


Node *create_node(int data){
    Node *node = malloc(sizeof(*node));
    if(!node) return NULL;

    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return node;
}


void print_tree(Tree *root, int mode){
    if(!root) return;

    printf("{ ");
    switch (mode) {
        case -1:
            preorder(root); break;
        case 1:
            postorder(root); break;
        default:
            inorder(root); break;
    }
    printf("}");
}

/* utils */
void clear_tree(Tree *root){
    if(is_empty_tree(root)) return;

    clear_tree(&(*root)->left);
    clear_tree(&(*root)->right);

    free(*root);
}

bool is_empty_tree(Tree *root){
    return !root || !(*root);
}


size_t leaf_numbers(Tree *root){
    if(is_empty_tree(root))
        return 0;

    if(is_empty_tree(&(*root)->left) && is_empty_tree(&(*root)->right))
        return 1;

    return leaf_numbers(&(*root)->left) + leaf_numbers(&(*root)->right);
}


size_t node_numbers(Tree *root){
    if(is_empty_tree(root)) return 0;
    return 1 + node_numbers(&(*root)->left) + node_numbers(&(*root)->right);
}


int tree_height(Tree *root){
    if(is_empty_tree(root))  return -1;

    int height_left  = tree_height(&(*root)->left);
    int height_right = tree_height(&(*root)->right);

    return 1 + (height_left > height_right ? height_left : height_right);
}


/// @NOTE: data == node->data is not take in to account
Tree insert_bst(Tree *root, int data){
    if (!root)
        return NULL;
    if(!(*root))
        return create_node(data);

    Tree node = *root;

    if(data < node->data)
        node->left = insert_bst(&node->left, data);
    else if(node->data <data)
        node->right = insert_bst(&node->right, data);

    return *root;
}
