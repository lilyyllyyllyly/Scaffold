#pragma once

struct scaffold_vector2 {
	float x,y;
};

struct scaffold_vector2 scaffold_vector2_add(struct scaffold_vector2 a, struct scaffold_vector2 b);

struct scaffold_vector2 scaffold_vector2_sub(struct scaffold_vector2 a, struct scaffold_vector2 b);

struct scaffold_vector2 scaffold_vector2_scale(struct scaffold_vector2 vec, float factor);

struct scaffold_vector2 scaffold_vector2_divide(struct scaffold_vector2 vec, float factor);

float scaffold_vector2_square_mag(struct scaffold_vector2 vec);

float scaffold_vector2_magnitude(struct scaffold_vector2 vec);

struct scaffold_vector2 scaffold_vector2_normalized(struct scaffold_vector2 vec);

struct scaffold_vector2 scaffold_vector2_clamp_mag(struct scaffold_vector2 vec, float min, float max);

