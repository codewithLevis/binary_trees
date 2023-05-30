#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * If tree is NULL, your function must return 0
 * Return: height of tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	return (right_height > left_height ? right_height : left_height);
}
