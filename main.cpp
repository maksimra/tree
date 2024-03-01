#include "tree.h"

int main (void)
{
    Node* tree = (Node*) calloc (1, sizeof (Node));
    tree->data = 100;
    node_insert (tree, 50);
    node_insert (tree, 60);
    node_insert (tree, 55);
    node_insert (tree, 120);
    node_insert (tree, 130);
    node_insert (tree, 10);
    node_insert (tree, 64);
    node_insert (tree, 71);
    node_insert (tree, 105);
    tree_print (tree);
    return 0;
}
