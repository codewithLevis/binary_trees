#include "binary_trees.h"

/**
 * tree_size - a function that measures
 * the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: number of nods
*/

size_t tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	size = binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right);
	return (size);
}

/**
 * tree_leaves - Function that counts the leaves in a binary tree
 * @tree: pointer to the root node of
 * the tree to count the number of leaves
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 * Return: total leaves
*/

size_t tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL || tree->right == NULL)
		return (1);
	leaf_count += binary_tree_leaves(tree->right);
	leaf_count +=  binary_tree_leaves(tree->left);
	return (leaf_count);
}

/**
 * binary_tree_nodes - function that counts
 * the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of
 * the tree to count the number of nodes
 *Return: non-leaf nodes
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	return (tree_size(tree) - tree_leaves(tree));
}
