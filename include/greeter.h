#pragma once

#include "node.h"

struct greeter_data {
	char* greeting;
};

struct node* create_greeter(char* greeting);

