#pragma once

#include "component.h"

struct greeter_data {
	char* greeting;
};

struct component* create_greeter(char* greeting);

