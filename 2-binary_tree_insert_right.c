#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right
 * child of a parent node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);

	right_child = binary_tree_node(parent, value);
	if (right_child == NULL)
		return (NULL);

	right_child->right = parent->right;
	if (right_child->right != NULL)
		right_child->right->parent = right_child;
	parent->right = right_child;

	return (right_child);
}
