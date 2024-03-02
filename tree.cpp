#include "tree.h"

static FILE* log_file = stderr;

void tree_set_log_file (FILE* file)
{
    log_file = file;
}

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
    fprintf (log_file, "{ %d\n", node->data);
    if (node->left != NULL)
        tree_print (node->left);
    else
        fprintf (log_file, "0\n");
    if (node->right != NULL)
        tree_print (node->right);
    else
        fprintf (log_file, "0");
    fprintf (log_file, "\n}\n");
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
    {
        if (necessary_node->right != NULL)
            parent_node->right = necessary_node->right;
        else if (necessary_node->left != NULL)
            parent_node->right = necessary_node->left;
        else
            parent_node->right = NULL;
    }
    else
    {
        if (necessary_node->right != NULL)
            parent_node->left = necessary_node->right;
        else if (necessary_node->left != NULL)
            parent_node->left = necessary_node->left;
        else
            parent_node->left = NULL;
    }

    if (necessary_node->right == NULL || necessary_node->left == NULL)
        return;

    Node* current_node = necessary_node->right;

    while (current_node->left != NULL)
        current_node = current_node->left;

    current_node->left = necessary_node->left;
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
