#include "tree.h"

int total_nodes(Tree_t *root)
{

    if ( root == NULL ) return 0;

    return 1 + total_nodes(root->left) + total_nodes(root->right);

}
