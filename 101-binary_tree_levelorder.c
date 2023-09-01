#include "binary_trees.h"

/**
 * binary_tree_levelorder_recursive - Helper function to perform
 * levelorder traversal recursively
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to be called on each node's value
 * @level: Current level being traversed
 *
 * Return: None
 */
void binary_tree_levelorder_recursive(const binary_tree_t *tree,
		void (*func)(int), size_t level)
{
	if (binary_tree_depth(tree) == level)
		func(tree->n);

	if (tree->left && binary_tree_depth(tree) < level)
		binary_tree_levelorder_recursive(tree->left, func, level);

	if (tree->right && binary_tree_depth(tree) < level)
		binary_tree_levelorder_recursive(tree->right, func, level);
}

/**
 * binary_tree_levelorder - Performs a levelorder traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to be called on each node's value
 *
 * Return: None
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree != NULL && func != NULL)
	{
		height = binary_tree_height(tree);
		for (level = 0; level <= height; level++)
			binary_tree_levelorder_recursive(tree, func, level);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int num_subnodes_left, num_subnodes_right, height;

	num_subnodes_right = 1;
	num_subnodes_left = 1;

	if (tree)
	{
		if (tree->left)
			num_subnodes_left += binary_tree_height(tree->left);

		if (tree->right)
			num_subnodes_right += binary_tree_height(tree->right);

		if (num_subnodes_right > num_subnodes_left)
			height = num_subnodes_right;
		else
			height = num_subnodes_left;

		if (tree->left == tree->right)/* Both left and right are NULL */
			height = 0;

		return (height);
	}
	return (0);
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
