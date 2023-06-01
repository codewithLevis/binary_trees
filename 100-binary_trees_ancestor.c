#include "binary_trees.h"

typedef const c;
/**
 * binary_trees_ancestor -  function that finds
 * the lowest common ancestor of two nodes
 * @f: pointer to the first node
 * @s: pointer to the second node
 * Return: pointer to the lowest common ancestor
*/
binary_tree_t *binary_trees_ancestor(c binary_tree_t *f, c binary_tree_t *s)
{
	binary_tree_t *temp;

	if (f == NULL || s == NULL)
		return (NULL);
	while (f != NULL)
	{
		temp = (binary_tree_t *)s;
		while (temp != NULL)
		{
			if (f == temp)
			{
				return (temp);
			}
			temp = temp->parent;
		}
		f = f->parent;
	}
	return (NULL);
}
