#include <stdlib.h>

#include "scaffold.h"
#include "scaffold_node.h"

int type_count = 0;

int scaffold_node_new_type() {
	return type_count++;
}

struct scaffold_vector2 scaffold_node_update_pos(struct scaffold_node* node) {
	node->global_pos = node->local_pos;

	if (node->parent != NULL) {
		node->global_pos = scaffold_vector2_add(node->global_pos, scaffold_node_update_pos(node->parent));
	}

	return node->global_pos;
}

void scaffold_node_set_global_pos(struct scaffold_node* node, struct scaffold_vector2 pos) {
	scaffold_node_update_pos(node);
	node->local_pos = scaffold_vector2_add(node->local_pos, scaffold_vector2_sub(pos, node->global_pos));
}

void scaffold_node_add_child(struct scaffold_node* parent, struct scaffold_node* child) {
	child->parent = parent;
	child->next_sibling = parent->first_child;
	parent->first_child = child;
}

struct scaffold_node* scaffold_node_create(int* type_var, void* data, struct scaffold_vector2 pos, void (*process)(struct scaffold_node*, double), void (*destroy)(struct scaffold_node*)) {
	if (*type_var == NODE_TYPE_UNASSIGNED) *type_var = scaffold_node_new_type();

	struct scaffold_node* new_node = calloc(1, sizeof(struct scaffold_node));

	new_node->type = *type_var;
	new_node->data = data;

	new_node->local_pos = new_node->global_pos = pos;

	new_node->process = process;
	new_node->destroy = destroy == NULL? scaffold_node_destroy : destroy;

	return new_node;
}

void scaffold_node_destroy(struct scaffold_node* node) {
	struct scaffold_node* child = node->first_child;
	while (child != NULL) {
		struct scaffold_node* next_child = child->next_sibling;
		child->destroy(child);
		child = next_child;
	}

	free(node);
}

