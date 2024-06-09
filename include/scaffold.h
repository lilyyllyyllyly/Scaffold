#pragma once

#include "scaffold_node.h"

struct scaffold_node* scaffold_initialize();
void scaffold_process_branch(struct scaffold_node* branch, double delta);

