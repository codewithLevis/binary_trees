#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as
 * the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *Return: new/NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	if (parent->right == NULL)
		parent->right = new_node;
	/**
	*If parent already has a right-child, the new node must take its place
	* and the old right-child must be set as the right-child of the new node
	*/
	else
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
		parent->right = new_node;
	}
	return (new_node);
}
