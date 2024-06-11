#include <stdio.h>
#include <stdlib.h>

#include "scaffold_vector.h"
#include "scaffold_list.h"
#include "scaffold_node.h"

int scaffold_root_type = NODE_TYPE_UNASSIGNED;

scaffold_list* destroy_list = NULL;

// Creates a root node and returns it
scaffold_node* scaffold_initialize() {
	return scaffold_node_create(
		&scaffold_root_type,
		NULL,
		NULL,
		NULL
	);
}

// Calls process function for all nodes on branch and update transforms
static void scaffold_process_branch(scaffold_node* branch, double delta) {
	// calculate global pos
	branch->global_pos = branch->local_pos;
	if (branch->parent != NULL) {
		branch->global_pos = scaffold_vector2_add(branch->global_pos, branch->parent->global_pos);
	}

	// process
	if (branch->process != NULL) {
		branch->process(branch, delta);
	}

	// children
	scaffold_node* child = branch->first_child;
	while (child != NULL) {
		scaffold_process_branch(child, delta);
		child = child->next_sibling;
	}
}

// Meant to be called with root node, processes root branch and destroys nodes in the destroy list
void scaffold_process_cleanup(scaffold_node* root, double delta) {
	scaffold_process_branch(root, delta);

	scaffold_list* elem = destroy_list;
	while (elem != NULL) {
		scaffold_list* next_elem = elem->next;

		scaffold_node* node = (scaffold_node*)(elem->data);
		node->destroy(node);
		free(elem);

		elem = next_elem;
	}
	destroy_list = NULL;
}

// Pushes a node to the top of the destroy list to be destroyed after process
// Technically not a queue but no one needs to know that
void scaffold_queue_destroy(scaffold_node* node) {
	destroy_list = scaffold_list_insert(destroy_list, node);
}

