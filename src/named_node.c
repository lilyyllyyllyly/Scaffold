#include <stdlib.h>

#include "node.h"
#include "named_node.h"

struct node* create_named_node(char* name) {
	struct node* new_named_node = calloc(1, sizeof(struct node));

	new_named_node->destroy = node_base_destroy;
	new_named_node->data = name;

	return new_named_node;
}

