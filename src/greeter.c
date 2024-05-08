#include <stdio.h>
#include <stdlib.h>

#include "greeter.h"

static void start(struct component* greeter) {
	printf("%s\n", ((struct greeter_data*)(greeter->data))->greeting);
}

static void destroy(struct component* greeter) {
	free(((struct greeter_data*)(greeter->data))->greeting);
	free(greeter->data);
	free(greeter);
}

struct component* create_greeter(char* greeting) {
	struct component* new_greeter = malloc(sizeof(struct component));
	struct greeter_data* data = malloc(sizeof(struct greeter_data));
	data->greeting = greeting;

	new_greeter->start   = start;
	new_greeter->process = NULL;
	new_greeter->destroy = destroy;
	new_greeter->data = data;

	return new_greeter;
}

