#include <string.h>
#include <stdlib.h>

#include "component.h"
#include "greeter.h"

#define GREETING "halo"

int main() {
	char* msg = malloc(strlen(GREETING) + 1);
	strcpy(msg, GREETING);

	struct component* greeter = create_greeter(msg);

	greeter->start(greeter);

	greeter->destroy(greeter);
}

