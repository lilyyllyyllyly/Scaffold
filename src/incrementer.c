#include <stdlib.h>

#include "node.h"

extern unsigned int type_count;

static void increment(struct node* incrementer) {
	++type_count;
}

struct node* create_incrementer() {
	struct node* new_incr = calloc(1, sizeof(struct node));
	
	new_incr->start = increment;
	new_incr->destroy = node_base_destroy;

	return new_incr;
}

