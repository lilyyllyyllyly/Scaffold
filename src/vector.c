#include <math.h>

#include "vector.h"

struct scaffold_vector2 scaffold_vector2_add(struct scaffold_vector2 a, struct scaffold_vector2 b) {
	return (struct scaffold_vector2){a.x + b.x, a.y + b.y};
}

struct scaffold_vector2 scaffold_vector2_sub(struct scaffold_vector2 a, struct scaffold_vector2 b) {
	return (struct scaffold_vector2){a.x - b.x, a.y - b.y};
}

struct scaffold_vector2 scaffold_vector2_scale(struct scaffold_vector2 vec, float factor) {
	return (struct scaffold_vector2){vec.x * factor, vec.y * factor};
}

float scaffold_vector2_square_mag(struct scaffold_vector2 vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

float scaffold_vector2_magnitude(struct scaffold_vector2 vec) {
	return sqrtf(scaffold_vector2_square_mag(vec));
}

struct scaffold_vector2 scaffold_vector2_normalized(struct scaffold_vector2 vec) {
	float mag = scaffold_vector2_magnitude(vec);
	return mag > 0? (struct scaffold_vector2){vec.x/mag, vec.y/mag} : (struct scaffold_vector2){0, 0};
}

