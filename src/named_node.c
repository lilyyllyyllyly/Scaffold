#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "named_node.h"

int named_node_type = NODE_TYPE_UNASSIGNED;

void named_node_print_branch(struct node* branch, int curr_depth) {
	for (int i = 0; i < curr_depth; ++i) putchar(' ');
	if (branch->type == named_node_type) printf("%s\n", (char*)(branch->data));
	else printf("<unnamed node [type: %d]>\n", branch->type);

	struct node* child = branch->first_child;
	while (child != NULL) {
		named_node_print_branch(child, curr_depth + 1);
		child = child->next_sibling;
	}
}

struct node* create_named_node(char* name) {
	if (named_node_type == NODE_TYPE_UNASSIGNED) named_node_type = node_new_type();

	struct node* new_named_node = calloc(1, sizeof(struct node));

	new_named_node->destroy = node_base_destroy;
	new_named_node->type    = named_node_type;
	new_named_node->data    = name;

	return new_named_node;
}

