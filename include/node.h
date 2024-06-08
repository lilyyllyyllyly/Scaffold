#pragma once

#include "vector.h"
#include "scaffold.h"

#define NODE_TYPE_UNASSIGNED -1

struct node {
	int type;
	void* data;

	struct scaffold_vector2 local_pos, global_pos;

	void (*process)(struct node*);
	void (*destroy)(struct node*);

	struct node* parent;
	struct node* first_child;
	struct node* next_sibling;
};

struct scaffold_vector2 scaffold_update_node_pos(struct node* node);
void node_set_global_pos(struct node* node, struct scaffold_vector2 pos);

int node_new_type();
void node_add_child(struct node* parent, struct node* child);
struct node* node_base_create(int* type_var, void* data, struct scaffold_vector2 pos, void (*process)(struct node*), void (*destroy)(struct node*));
void node_base_destroy(struct node* node);

