#pragma once

struct scaffold_vector2 {
	int x,y;
};

#include "node.h"

struct scaffold_vector2 scaffold_vector2_add(struct scaffold_vector2 a, struct scaffold_vector2 b);

struct node* scaffold_initialize();
void scaffold_process_branch(struct node* branch);

