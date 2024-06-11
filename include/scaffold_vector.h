#pragma once

typedef struct {
	float x,y;
} scaffold_vector2;

scaffold_vector2 scaffold_vector2_add(scaffold_vector2 a, scaffold_vector2 b);

scaffold_vector2 scaffold_vector2_sub(scaffold_vector2 a, scaffold_vector2 b);

scaffold_vector2 scaffold_vector2_scale(scaffold_vector2 vec, float factor);

scaffold_vector2 scaffold_vector2_divide(scaffold_vector2 vec, float factor);

float scaffold_vector2_square_mag(scaffold_vector2 vec);

float scaffold_vector2_magnitude(scaffold_vector2 vec);

scaffold_vector2 scaffold_vector2_normalized(scaffold_vector2 vec);

scaffold_vector2 scaffold_vector2_clamp_mag(scaffold_vector2 vec, float min, float max);

float scaffold_vector2_distance(scaffold_vector2 a, scaffold_vector2 b);

