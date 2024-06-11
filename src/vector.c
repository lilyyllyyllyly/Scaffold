#include <math.h>

#include "scaffold_vector.h"

scaffold_vector2 scaffold_vector2_add(scaffold_vector2 a, scaffold_vector2 b) {
	return (scaffold_vector2){a.x + b.x, a.y + b.y};
}

scaffold_vector2 scaffold_vector2_sub(scaffold_vector2 a, scaffold_vector2 b) {
	return (scaffold_vector2){a.x - b.x, a.y - b.y};
}

scaffold_vector2 scaffold_vector2_scale(scaffold_vector2 vec, float factor) {
	return (scaffold_vector2){vec.x * factor, vec.y * factor};
}

scaffold_vector2 scaffold_vector2_divide(scaffold_vector2 vec, float factor) {
	return factor == 0? (scaffold_vector2){0, 0} : (scaffold_vector2){vec.x / factor, vec.y / factor};
}

float scaffold_vector2_square_mag(scaffold_vector2 vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

float scaffold_vector2_magnitude(scaffold_vector2 vec) {
	return sqrtf(scaffold_vector2_square_mag(vec));
}

scaffold_vector2 scaffold_vector2_normalized(scaffold_vector2 vec) {
	float mag = scaffold_vector2_magnitude(vec);
	return scaffold_vector2_divide(vec, mag);
}

scaffold_vector2 scaffold_vector2_clamp_mag(scaffold_vector2 vec, float min, float max) {
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
	scaffold_vector2 normal = scaffold_vector2_divide(vec, mag);
	return scaffold_vector2_scale(normal, scale);
}

float scaffold_vector2_distance(scaffold_vector2 a, scaffold_vector2 b) {
	return scaffold_vector2_magnitude(scaffold_vector2_sub(b, a));
}

