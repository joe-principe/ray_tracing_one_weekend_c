#ifndef VEC3_H
#define VEC3_H

typedef struct vec3_t vec3;

struct vec3_t
{
    float e[3];
};

/**
 * Creates a new vector from individual values
 * @param f1 The x (aka r) component
 * @param f2 The y (aka g) component
 * @param f3 The z (aka b) component
 */
vec3 *create_vector(float f1, float f2, float f3);

/**
 * Creates a new zero vector
 * @return The new zero vector
 */
vec3 *create_empty_vector(void);

/**
 * Creates a new vector that is the unit vector of a given direction vector
 * @param vec The original direction vector
 * @return A new vector that is equal to the unit vector of the input
 */
vec3 *new_unit_vector(const vec3 *dir);

/**
 * Turns the first vector into the unit vector of the second vector
 * @param first The vector being converted
 * @param second The direction vector
 */
void turn_into_unit_vector(vec3 *first, const vec3 *second);

/**
 * Sets a vector's elements from individual values
 * @param vec The vector being passed in
 * @param f1 The x (aka r) component
 * @param f2 The y (aka g) component
 * @param f3 The z (aka b) component
 */
void set_elems(vec3 *vec, float f1, float f2, float f3);

/**
 * Sets all of a vector's elements to zero
 * @param vec The vector
 */
void zero_out_vector(vec3 *vec);

/**
 * Deletes a vector
 * @param vec The vector to delete
 */
void delete_vector(vec3 *vec);

/**
 * Calculates the length of the vector
 * @param vec The vector whose length is being calculated
 * @return The length of the vector
 */
float length(const vec3 *vec);

/**
 * Calculates the squared length of the vector
 * @param vec The vector whose squared length is being calculated
 * @return The squared length of the vector
 */
float squared_length(const vec3 *vec);

/**
 * Gets the value of the first element in the vector
 * @param vec The vector
 * @return The value of the first element in the vector
 */
float get_x(const vec3 *vec);

/**
 * Gets the value of the second element in the vector
 * @param vec The vector
 * @return The value of the second element in the vector
 */
float get_y(const vec3 *vec);

/**
 * Gets the value of the third element in the vector
 * @param vec The vector
 * @return The value of the third element in the vector
 */
float get_z(const vec3 *vec);

/**
 * Gets the value of the first element in the vector
 * @param vec The vector
 * @return The value of the first element in the vector
 */
float get_r(const vec3 *vec);

/**
 * Gets the value of the second element in the vector
 * @param vec The vector
 * @return The value of the second element in the vector
 */
float get_g(const vec3 *vec);

/**
 * Gets the value of the third element in the vector
 * @param vec The vector
 * @return The value of the third element in the vector
 */
float get_b(const vec3 *vec);

/**
 * Adds a scalar value to every element of the vector
 * @param vec The vector being added to
 * @param f The scalar value to add
 */
void add_scalar(vec3 *vec, float f);

/**
 * Subtracts a scalar value from every element of the vector
 * @param vec The vector being subtracted from
 * @param f The scalar value to subtract
 */
void subtract_scalar(vec3 *vec, float f);

/**
 * Multiplies every element of the vector by a scalar value
 * @param vec The vector being multiplied
 * @param f The scalar value to multiply
 */
void multiply_scalar(vec3 *vec, float f);

/**
 * Divides every element of the vector by a scalar value
 * @param vec The vector being divided
 * @param f The scalar value to divide
 */
void divide_scalar(vec3 *vec, float f);

/**
 * Negates every element of the vector
 * @param vec The vector to negate
 */
void negate(vec3 *vec);

/**
 * Adds two vectors together and stores the sum into a parameter vector
 * @param sum The sum vector
 * @param first The first vector to add
 * @param second The second vector to add
 */
void add_vec(vec3 *sum, const vec3 *first, const vec3 *second);

/**
 * Adds two vectors together and stores the sum into a new vector
 * @param first The first vector to add
 * @param second The second vector to add
 * @return A new vector containing the result of the addition
 */
vec3 *add_vec_new(const vec3 *first, const vec3 *second);

/**
 * Subtracts two vectors and stores the difference into a parameter vector
 * @param elems Stores the difference of the subtraction
 * @param first The vector being subtracted from
 * @param second The vector subtracting
 */
void subtract_vec(vec3 *diff, const vec3 *first, const vec3 *second);

/** 
 * Subtracts two vectors and stores the difference into a new vector
 * @param first The vector being subtracted from (minued)
 * @param second The vector subtracting (subtrahend)
 * @return A new vector containing the result of the subtraction
 */
vec3 *subtract_vec_new(const vec3 *first, const vec3 *second);

/** 
 * Calculates the dot product of two vectors
 * @param first The first vector of the product
 * @param second The second vector of the product
 * @return The dot product
 */
float dot_product(const vec3 *first, const vec3 *second);

/**
 * Calculates the cross prouct of two vectors and stores the result into a
 * parameter vector
 * @param prod The cross product vector
 * @param first The first vector of the product
 * @param second The second vector of the product
 */
void cross_product(vec3 *prod, const vec3 *first, const vec3 *second);

/**
 * Calculates the cross product of two vectors and stores the result into a new
 * vector
 * @param first The first vector of the product
 * @param second The second vector of the product
 * @return The cross product vector
 */
vec3 *cross_product_new(const vec3 *first, const vec3 *second);

/**
 * Calculates the entrywise product of two vectors and stores it into a
 * parameter vector
 * @param prod The result of the entrywise product
 * @param first The first vector of the product
 * @param second The second vector of the product
 */
void entrywise_product(vec3 *prod, const vec3 *first, const vec3 *second);

/**
 * Calculates the entrywise product of two vectors and stores the result into
 * a new vector
 * @param first The first vector of the product
 * @param second The second vector of the product
 * @return The entrywise product
 */
vec3 *entrywise_product_new(const vec3 *first, const vec3 *second);

/**
 * Calculates the entrywise division of two vectors and stores the result into
 * a parameter vector
 * @param quotient The result of the entrywise division
 * @param first The first vector of the division
 * @param second The second vector of the division
 */
void entrywise_division(vec3 *quotient, const vec3 *first, const vec3 *second);

/**
 * Calculates the entrywise division of two vectors and stores the result into
 * a new vector
 * @param first The first vector of the division
 * @param second The second vector of the division
 * @return The entrywise quotient
 */
vec3 *entrywise_division_new(const vec3 *first, const vec3 *second);

#endif
/* EOF */