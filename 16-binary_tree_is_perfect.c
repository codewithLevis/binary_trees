#include "binary_trees.h"


/**
 * nodes_count - function that counts the number of nodes in a binary tree
 *@tree: a pointer to a binary tree
 * Return: nodes count
*/

int nodes_count(binary_tree_t *tree)
{
	int count = 0;

	if (!tree)
		return (0);
	count = 1 + nodes_count(tree->left) + nodes_count((tree->right));
	return (count);
}

/**
* binary_tree_is_perfect - a function that checks if
*a binary tree is perfect
* @tree: pointer to the root node of the tree to check
* Return: 0/1
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (nodes_count(tree->left) == nodes_count(tree->right));
}
