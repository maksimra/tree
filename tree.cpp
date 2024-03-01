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

void delete_node (Node* node, int num)
{
    Node* necessary_node = NULL;
    Node* parent_node = NULL;
    search_node (node, num, &necessary_node);
    search_parent_node (node, num, &parent_node);

    if (necessary_node->data > parent_node->data)
        parent_node->right = necessary_node->right;

    else
        parent_node->left = necessary_node->right;

    Node*
    necessary_node = necessary_node->right;

    while (necessary_node->left != NULL)
        necessary_node = necessary_node->left;

    necessary_node->left =

}

void search_node (Node* node, int num, Node** necessary_node)
{
    while (1)
    {
        if (num > node->data)
        {
            if (node->right != NULL)
            {
                node = node->right;
                continue;
            }
        }
        else if (num < node->data)
        {
            if (node->left != NULL)
            {
                node = node->left;
                continue;
            }
        }
        else
        {
            *necessary_node = node;
            break;
        }
    }
}

void search_parent_node (Node* node, int num, Node** parent_node)
{
    Node* prev_node = NULL;
    while (1)
    {
        if (num > node->data)
        {
            if (node->right != NULL)
            {
                prev_node = node;
                node = node->right;
                continue;
            }
        }
        else if (num < node->data)
        {
            if (node->left != NULL)
            {
                prev_node = node;
                node = node->left;
                continue;
            }
        }
        else
        {
            *parent_node = prev_node;
            break;
        }
    }
}
