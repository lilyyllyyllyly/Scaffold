#pragma once

#include "scaffold_vector.h"
#include "scaffold_list.h"
#include "scaffold_node.h"

scaffold_node* scaffold_initialize();
void scaffold_process_cleanup(scaffold_node* branch, double delta);
void scaffold_queue_destroy(scaffold_node* node);
void scaffold_dequeue_destroy(scaffold_node* node);

