#include "binary_trees.h"

/**
* tree_height - function that measures the height of a binary tree
*@tree: pointer to the node of the tree
* to measure the balance factor
* Return: height of tree
*/

int tree_height(binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
* binary_tree_balance - function that measures
* the balance factor of a binary tree
* @tree: pointer to the node of the tree
* to measure the balance factor
* Return: 0/>0<
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree->left) - tree_height(tree->right));
}
