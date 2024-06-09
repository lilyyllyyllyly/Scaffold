#include <stdio.h>
#include <stdlib.h>

#include "scaffold_vector.h"
#include "scaffold_node.h"

int scaffold_root_type = NODE_TYPE_UNASSIGNED;

// Creates a root node and returns it
struct scaffold_node* scaffold_initialize() {
	return scaffold_node_create(
		&scaffold_root_type,
		NULL,
		(struct scaffold_vector2){0, 0},
		NULL,
		NULL
	);
}

// TODO: account for process function messing with direct children of branch
void scaffold_process_branch(struct scaffold_node* branch, double delta) {
	branch->global_pos = branch->local_pos;
	if (branch->parent != NULL) {
		branch->global_pos = scaffold_vector2_add(branch->global_pos, branch->parent->global_pos);
	}

	if (branch->process != NULL) {
		branch->process(branch, delta);
	}

	struct scaffold_node* child = branch->first_child;
	while (child != NULL) {
		scaffold_process_branch(child, delta);
		child = child->next_sibling;
	}
}

