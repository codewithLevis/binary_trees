#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 *power - calculates power of a number
 *@base: number base
 *@exponent: raised to digit
 *Return: power
 */
double power(double base, int exponent)
{
	double result = 1.0;
	int i;

	if (exponent >= 0)
	{
		for (i = 0; i < exponent; i++)
			result *= base;
	}
	else
	{
		base = 1.0 / base;
		exponent = -exponent;

		for (i = 0; i < exponent; i++)
			result *= base;
	}
	return (result);
}

/**
 * height - function that measures
 *the height of a binary tree
 *@tree: pointer to a node
 * Return: height
*/
int height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 *  enqueue - function to enqueue a node in an array
 * @array: pointer to the queue
 * @rear: pointer to the back
 * @node: pointer to the node to add into the queue
 */
void enqueue(binary_tree_t **array, int *rear, binary_tree_t *node)
{
	array[*rear] = node;
	(*rear)++;
}

/**
 * dequeue - function to dequeue a node from an array
 * @array: pointer to the queue
 * @front: pointer to the front of the queue
 * Return: current node
 */
binary_tree_t *dequeue(binary_tree_t **array, int *front)
{
	binary_tree_t *node = array[*front];
	(*front)++;
	return (node);
}

/**
 * binary_tree_levelorder - function that goes through
 * a binary tree using level-order traversal
 * @tree: pointer to root node
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **array = NULL;
	int front = 0, rear = 0;
	binary_tree_t *node = NULL;
	int max_nodes = power(2, (height(tree) + 1));

	if (tree == NULL || func == NULL)
		return;

	array = malloc(sizeof(binary_tree_t *) * max_nodes);
	if (array == NULL)
		return;
	enqueue(array, &rear, (binary_tree_t *)tree);

	while (front != rear)
	{
		node = dequeue(array, &front);
		func(node->n);

		/* Enqueue the left child if it exists */
		if (node->left != NULL)
			enqueue(array, &rear, node->left);

		/* Enqueue the right child if it exists */
		if (node->right != NULL)
			enqueue(array, &rear, node->right);
	}

	free(array);
}
