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
* binary_tree_is_perfect - a function that checks if
*a binary tree is perfect
* @tree: pointer to the root node of the tree to check
* Return: 0/1
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height(tree->left) == height(tree->right));
}
