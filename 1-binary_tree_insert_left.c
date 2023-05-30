#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node
 * as the left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: new/NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);
	new = binary_tree_node(parent, value);

	if (new_node = NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;
	/**
	*If parent already has a left-child, the new node must take its place
	*and the old left-child must be set as the left-child of the new node
	*/
	else
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
		parent->left = new_node;
	}
	return (new_node);
}
