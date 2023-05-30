#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts
 *the leaves in a binary tree
 * @tree: pointer to the root node of
 * The tree to count the number of leaves
 * A NULL pointer is not a leaf
 * Return: total leaves
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_count = 0;

	if (tree->left == NULL || tree->right == NULL)
		return (1);
	if (tree == NULL)
		return (0);
	leaf_count += binary_tree_leaves(tree->right);
	leaf_count +=  binary_tree_leaves(tree->left);
	return (leaf_count);
}
