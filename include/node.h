#pragma once

#include <stdint.h>

struct node {
	void (*start)(struct node*);
	void (*process)(struct node*);
	void (*destroy)(struct node*);

	unsigned int type;
	void* data;

	struct node* parent;
	struct node* first_child;
	struct node* next_sibling;
};

void node_base_destroy(struct node* node);
void node_add_child(struct node* parent, struct node* child);

