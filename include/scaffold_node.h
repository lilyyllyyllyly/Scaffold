#pragma once

#include "scaffold_vector.h"

#define NODE_TYPE_UNASSIGNED -1

typedef struct scaffold_node {
	int type;
	void* data;

	scaffold_vector2 local_pos, global_pos;

	void (*process)(struct scaffold_node*, double);
	void (*destroy)(struct scaffold_node*);

	struct scaffold_node* parent;
	struct scaffold_node* first_child;
	struct scaffold_node* next_sibling;
	struct scaffold_node* prev_sibling;
} scaffold_node;

scaffold_vector2 scaffold_node_update_pos(scaffold_node* scaffold_node);
void scaffold_node_set_global_pos(scaffold_node* scaffold_node, scaffold_vector2 pos);

void scaffold_node_add_child(scaffold_node* parent, scaffold_node* child);

int scaffold_node_new_type();
scaffold_node* scaffold_node_create(int* type_var, void* data, void (*process)(scaffold_node*, double), void (*destroy)(scaffold_node*));
void scaffold_node_destroy(scaffold_node* node);

