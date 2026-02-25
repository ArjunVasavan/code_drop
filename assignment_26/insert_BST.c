#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{

    if ( *root == NULL ) {
        Tree_t *new = malloc(sizeof(Tree_t));
        if ( new == NULL ) return FAILURE;
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        *root = new;
        return  SUCCESS;

    }

    if ( data < (*root)->data ) {
        return insert_into_BST(&((*root)->left), data);

    } else if ( data > (*root)->data) {
    
        return insert_into_BST(&((*root)->right), data);

    } else {
        return DUPLICATE;
    }


}
