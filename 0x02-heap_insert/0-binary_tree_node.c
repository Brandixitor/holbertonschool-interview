#include "binary_trees.h"	
/**	
 * binary_tree_node - function that creates a binary tree node.	
 * @parent: is a pointer to the parent node of the node to create	
 * @value: is the value to put in the new node	
 * Return: returns a pointer to the new node, or NULL on failure	
**/	
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)	
{	
    binary_tree_t *new;	

    new = malloc(sizeof(binary_tree_t));	
    if (new == NULL)	
        return NULL;	
    new->parent = parent;	
    new->n = value;	
    new->left = NULL;	
    new->right = NULL;	

    if (parent != NULL)	
    {	
        if (parent->n > value)	
            parent->left = new;	
        else	
            parent->right = new;	
    }	
    return new;	
} 