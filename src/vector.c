#include <math.h>

#include "scaffold_vector.h"

struct scaffold_vector2 scaffold_vector2_add(struct scaffold_vector2 a, struct scaffold_vector2 b) {
	return (struct scaffold_vector2){a.x + b.x, a.y + b.y};
}

struct scaffold_vector2 scaffold_vector2_sub(struct scaffold_vector2 a, struct scaffold_vector2 b) {
	return (struct scaffold_vector2){a.x - b.x, a.y - b.y};
}

struct scaffold_vector2 scaffold_vector2_scale(struct scaffold_vector2 vec, float factor) {
	return (struct scaffold_vector2){vec.x * factor, vec.y * factor};
}

struct scaffold_vector2 scaffold_vector2_divide(struct scaffold_vector2 vec, float factor) {
	return factor == 0? (struct scaffold_vector2){0, 0} : (struct scaffold_vector2){vec.x / factor, vec.y / factor};
}

float scaffold_vector2_square_mag(struct scaffold_vector2 vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

float scaffold_vector2_magnitude(struct scaffold_vector2 vec) {
	return sqrtf(scaffold_vector2_square_mag(vec));
}

struct scaffold_vector2 scaffold_vector2_normalized(struct scaffold_vector2 vec) {
	float mag = scaffold_vector2_magnitude(vec);
	return scaffold_vector2_divide(vec, mag);
}

struct scaffold_vector2 scaffold_vector2_clamp_mag(struct scaffold_vector2 vec, float min, float max) {
	float square_mag = scaffold_vector2_square_mag(vec);
	float square_min = min*min;
	float square_max = max*max;

	float scale = 0;

	if (square_mag < square_min) {
		scale = min;
	} else if (square_mag > square_max) {
		scale = max;
	} else return vec;

	float mag = sqrtf(square_mag);
	struct scaffold_vector2 normal = scaffold_vector2_divide(vec, mag);
	return scaffold_vector2_scale(normal, scale);
}

