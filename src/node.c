#include <stdlib.h>

#include "node.h"

int type_count = 0;

int node_new_type() {
	return type_count++;
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

void node_add_child(struct node* parent, struct node* child) {
	child->parent = parent;
	child->next_sibling = parent->first_child;
	parent->first_child = child;
}

