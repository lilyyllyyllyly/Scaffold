#pragma once

#include <stdint.h>

#define NODE_TYPE_UNASSIGNED -1

struct node {
	void (*process)(struct node*);
	void (*destroy)(struct node*);

	int type;
	void* data;

	struct node* parent;
	struct node* first_child;
	struct node* next_sibling;
};

int node_new_type();
void node_add_child(struct node* parent, struct node* child);
struct node* node_base_create(int* type_var, void (*process)(struct node*), void (*destroy)(struct node*), void* data);
void node_base_destroy(struct node* node);

