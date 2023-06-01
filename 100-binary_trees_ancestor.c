#include "binary_trees.h"

/**
 * binary_trees_ancestor -  function that finds
 * the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *temp;

	if (first == NULL || second == NULL)
		return (NULL);
	while (first != NULL)
	{
		temp = (binary_tree_t *)second;
		while (temp != NULL)
		{
			if (first == temp)
			{
				return (temp);
			}
			temp = temp->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
