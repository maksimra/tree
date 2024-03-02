#include "tree.h"

int main (void)
{
    Node* tree = (Node*) calloc (1, sizeof (Node));
    tree->data = 100;
    tree_print (tree);
    node_insert (tree, 80);
    printf ("Вставил 80:\n");
    tree_print (tree);
    node_insert (tree, 70);
    printf ("Вставил 70:\n");
    tree_print (tree);
    node_insert (tree, 50);
    printf ("Вставил 50:\n");
    tree_print (tree);
    node_insert (tree, 60);
    printf ("Вставил 60:\n");
    tree_print (tree);
    delete_node (tree, 80);
    printf ("Удалил 80:\n");
    tree_print (tree);
    return 0;
}
