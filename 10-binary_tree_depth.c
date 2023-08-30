#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth of
 *
 * Return: Depth of the node, or 0 if the node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;
	binary_tree_t *node = tree->parent;

	if (tree)
	{
		while (node)
		{
			depth++;
			node = node->parent;
		}
		return (depth);
	}
	return (0);
}
