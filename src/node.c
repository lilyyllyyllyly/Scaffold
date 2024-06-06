#include <stdlib.h>

#include "node.h"

int type_count = 0;

int node_new_type() {
	return type_count++;
}

void node_add_child(struct node* parent, struct node* child) {
	child->parent = parent;
	child->next_sibling = parent->first_child;
	parent->first_child = child;
}

struct node* node_base_create(int* type_var, void (*process)(struct node*), void (*destroy)(struct node*), void* data) {
	if (*type_var == NODE_TYPE_UNASSIGNED) *type_var = node_new_type();

	struct node* new_node = calloc(1, sizeof(struct node));

	new_node->type    = *type_var;
	new_node->process = process;
	new_node->destroy = destroy == NULL? node_base_destroy : destroy;
	new_node->data    = data;

	return new_node;
}

void node_base_destroy(struct node* node) {
	struct node* child = node->first_child;
	while (child != NULL) {
		struct node* next_child = child->next_sibling;
		child->destroy(child);
		child = next_child;
	}

	free(node);
}

