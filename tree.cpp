#include "tree.h"

void node_insert (Node* node, int num)
{
    Node* temp = (Node*) calloc (1, sizeof (Node)); // динамический массив подвязывать
    temp->data = num;
    while (1)
    {
        if (num >= node->data)
        {
            if (node->right == NULL)
            {
                node->right = temp;
                break;
            }
            else
                node = node->right;
        }
        else
        {
            if (node->left == NULL)
            {
                node->left = temp;
                break;
            }
            else
                node = node->left;
        }
    }
}

void tree_print (Node* node)
{
    printf ("{ %d\n", node->data);
    if (node->left != NULL)
        tree_print (node->left);
    else
        printf ("0\n");
    if (node->right != NULL)
        tree_print (node->right);
    else
        printf ("0");
    printf ("\n}\n");
}

void tree_dtor (Node* node)
{
    if (node->left != NULL)
        tree_dtor (node->left);
    if (node->right != NULL)
        tree_dtor (node->right);
    free (node);
}
