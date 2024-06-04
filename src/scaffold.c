#include <stdio.h>
#include <stdlib.h>

#include "node.h"

// Creates a root node and returns it
struct node* scaffold_initialize() {
	struct node* root = calloc(1, sizeof(struct node));

	root->destroy = node_base_destroy;
	root->type = node_new_type();

	return root;
}

// TODO: account for process function messing with direct children of branch
void scaffold_process_branch(struct node* branch) {
	if (branch->process != NULL) branch->process(branch);

	struct node* child = branch->first_child;
	while (child != NULL) {
		scaffold_process_branch(child);
		child = child->next_sibling;
	}
}

