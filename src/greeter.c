#include <stdio.h>
#include <stdlib.h>

#include "greeter.h"

static void start(struct node* greeter) {
	printf("%s\n", ((struct greeter_data*)(greeter->data))->greeting);
}

static void destroy(struct node* greeter) {
	free(((struct greeter_data*)(greeter->data))->greeting);
	free(greeter->data);
	node_base_destroy(greeter);
}

struct node* create_greeter(char* greeting) {
	struct node* new_greeter = calloc(1, sizeof(struct node));

	struct greeter_data* data = calloc(1, sizeof(struct greeter_data));
	data->greeting = greeting;

	new_greeter->start   = start;
	new_greeter->destroy = destroy;
	new_greeter->data    = data;

	return new_greeter;
}

