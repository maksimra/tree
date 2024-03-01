#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void node_insert (Node* node, int num);

void tree_print (Node* node);

void tree_dtor (Node* node);

void delete_node (Node* node, int num);

void search_node (Node* node, int num, Node** necessary_node);
