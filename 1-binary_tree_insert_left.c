#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left
 * child of a parent node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	if (parent == NULL)
		return (NULL);

	left_child = binary_tree_node(parent, value);
	if (left_child == NULL)
		return (NULL);

	left_child->left = parent->left;
	if (left_child->left != NULL)
		left_child->left->parent = left_child;
	parent->left = left_child;

	return (left_child);
}
