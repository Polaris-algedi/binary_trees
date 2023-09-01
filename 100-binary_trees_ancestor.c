#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if nodes are invalid
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int depth1, depth2, diff;
	const binary_tree_t *ancestor, *closest, *furthest;

	if (first == NULL || second == NULL)
		return (NULL);
	depth1 = binary_tree_depth(first);
	depth2 = binary_tree_depth(second);

	diff = depth1 >= depth2 ? depth1 - depth2 : depth2 - depth1;

	closest = depth1 >= depth2 ? second : first;
	furthest = depth1 >= depth2 ? first : second;

	/* Find an ancestor of the furthest node that has the same level */
	/* of depth as the closest */
	ancestor = furthest;

	while (diff > 0)
	{
		ancestor = ancestor->parent;
		--diff;
	}

	while (ancestor != closest)
	{
		ancestor = ancestor->parent;
		closest = closest->parent;
	}

	return ((binary_tree_t *)ancestor);
}


/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth of
 *
 * Return: Depth of the node, or 0 if the node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;
	const binary_tree_t *node;

	node = tree;
	if (tree)
	{
		while (node->parent)
		{
			depth++;
			node = node->parent;
		}
	}
	return (depth);
}
