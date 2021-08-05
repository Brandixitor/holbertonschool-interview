#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent:pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new  == NULL)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->right = NULL;
	new->left = NULL;
	return (new);
}
