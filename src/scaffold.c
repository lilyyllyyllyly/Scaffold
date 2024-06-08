#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "node.h"

int root_type = NODE_TYPE_UNASSIGNED;

// Creates a root node and returns it
struct node* scaffold_initialize() {
	return node_base_create(
		&root_type,
		NULL,
		(struct scaffold_vector2){0, 0},
		NULL,
		NULL
	);
}

// TODO: account for process function messing with direct children of branch
void scaffold_process_branch(struct node* branch) {
	branch->global_pos = branch->local_pos;
	if (branch->parent != NULL) {
		branch->global_pos = scaffold_vector2_add(branch->global_pos, branch->parent->global_pos);
	}

	if (branch->process != NULL) {
		branch->process(branch);
	}

	struct node* child = branch->first_child;
	while (child != NULL) {
		scaffold_process_branch(child);
		child = child->next_sibling;
	}
}

