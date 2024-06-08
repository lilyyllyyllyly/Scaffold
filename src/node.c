#include <stdlib.h>

#include "scaffold.h"
#include "node.h"

int type_count = 0;

int node_new_type() {
	return type_count++;
}

struct scaffold_vector2 scaffold_update_node_pos(struct node* node) {
	node->global_pos = node->local_pos;

	if (node->parent != NULL) {
		node->global_pos = scaffold_vector2_add(node->global_pos, scaffold_update_node_pos(node));
	}

	return node->global_pos;
}

void node_add_child(struct node* parent, struct node* child) {
	child->parent = parent;
	child->next_sibling = parent->first_child;
	parent->first_child = child;
}

struct node* node_base_create(int* type_var, void* data, struct scaffold_vector2 pos, void (*process)(struct node*), void (*destroy)(struct node*)) {
	if (*type_var == NODE_TYPE_UNASSIGNED) *type_var = node_new_type();

	struct node* new_node = calloc(1, sizeof(struct node));

	new_node->type = *type_var;
	new_node->data = data;

	new_node->local_pos = new_node->global_pos = pos;

	new_node->process = process;
	new_node->destroy = destroy == NULL? node_base_destroy : destroy;

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

