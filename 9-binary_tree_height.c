#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * If tree is NULL, your function must return 0
 * @tree: pointer to a binary tree node
 * Return: height of tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	return (right_height > left_height ? right_height : left_height);
}
