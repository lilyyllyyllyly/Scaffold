#include <stdio.h>

#include "node.h"
#include "named_node.h"

void print_branch(struct node* branch, int curr_depth) {
	for (int i = 0; i < curr_depth; ++i) putchar(' ');
	printf("%s\n", (char*)(branch->data));

	struct node* child = branch->first_child;
	while (child != NULL) {
		print_branch(child, curr_depth + 1);
		child = child->next_sibling;
	}
}

int main() {
	// -- Test Node Structure --
	// tree
	//   alice
	//     a0
	//     a1
	//   bethany
	//     b0
	//   chloe
	// -------------------------

	struct node* tree = create_named_node("tree");

	// alice branch
	struct node* alice = create_named_node("alice");
	node_add_child(tree, alice);

	struct node* a0 = create_named_node("a0");
	node_add_child(alice, a0);

	struct node* a1 = create_named_node("a1");
	node_add_child(alice, a1);

	// bethany branch
	struct node* bethany = create_named_node("bethany");
	node_add_child(tree, bethany);

	struct node* b0 = create_named_node("b0");
	node_add_child(bethany, b0);

	// chloe branch
	struct node* chloe = create_named_node("chloe");
	node_add_child(tree, chloe);

	// printing
	print_branch(tree, 0);

	// free
	tree->destroy(tree);
}

