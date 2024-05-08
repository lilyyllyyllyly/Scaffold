#pragma once

struct component {
	void (*start)(struct component*);
	void (*process)(struct component*);
	void (*destroy)(struct component*);
	void* data;
};

