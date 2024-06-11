#include <stdio.h>
#include <stdlib.h>

#include "scaffold.h"
#include "scaffold_node.h"

int type_count = 0;

int scaffold_node_new_type() {
	return type_count++;
}

scaffold_vector2 scaffold_node_update_pos(scaffold_node* node) {
	node->global_pos = node->local_pos;

	if (node->parent != NULL) {
		node->global_pos = scaffold_vector2_add(node->global_pos, scaffold_node_update_pos(node->parent));
	}

	return node->global_pos;
}

void scaffold_node_set_global_pos(scaffold_node* node, scaffold_vector2 pos) {
	scaffold_node_update_pos(node);
	node->local_pos = scaffold_vector2_add(node->local_pos, scaffold_vector2_sub(pos, node->global_pos));
}

void scaffold_node_add_child(scaffold_node* parent, scaffold_node* child) {
	child->parent = parent;
	child->next_sibling = parent->first_child;
	parent->first_child = child;
}

scaffold_node* scaffold_node_create(int* type_var, void* data, void (*process)(scaffold_node*, double), void (*destroy)(scaffold_node*)) {
	if (*type_var == NODE_TYPE_UNASSIGNED) *type_var = scaffold_node_new_type();

	scaffold_node* new_node = calloc(1, sizeof(scaffold_node));

	new_node->type = *type_var;
	new_node->data = data;

	new_node->local_pos = new_node->global_pos = (scaffold_vector2){0, 0};

	new_node->process = process;
	new_node->destroy = destroy == NULL? scaffold_node_destroy : destroy;

	return new_node;
}

void scaffold_node_destroy(scaffold_node* node) {
	printf("{ [%d]\n", node->type);
	scaffold_node* child = node->first_child;
	while (child != NULL) {
		scaffold_node* next_child = child->next_sibling;
		child->destroy(child);
		child = next_child;
	}

	free(node);
	puts("}");
}

