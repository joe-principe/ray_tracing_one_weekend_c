#ifndef VEC3_H
#define VEC3_H

#include <stdlib.h>

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
 * Creates a new vector from an array of values
 * @param values An array of values corresponding to the x, y, and z components
 * @param len The length of the values array
 */
vec3 *create_vector_from_array(const float *values, size_t len);

/**
 * Creates a new zero vector
 * @return The new zero vector
 */
vec3 *create_empty_vector(void);

/**
 * Sets a vector's elements from individual values
 * @param vec The vector
 * @param f1 The x (aka r) component
 * @param f2 The y (aka g) component
 * @param f3 The z (aka b) component
 */
void set_elems(vec3 *vec, float f1, float f2, float f3);

/**
 * Sets a vector's elements from an array of values
 * @param vec The vector
 * @param values An array of values corresponding to the x, y, and z components
 * @param len The length of the values array
 */
void set_elems_from_array(vec3 *vec, const float *values, size_t len);

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
 * Gets the value of the first element in the vector
 * @param vec The vector
 * @return The value of the first element in the vector
 */
float x(const vec3 *vec);

/**
 * Gets the value of the second element in the vector
 * @param vec The vector
 * @return The value of the second element in the vector
 */
float y(const vec3 *vec);

/**
 * Gets the value of the third element in the vector
 * @param vec The vector
 * @return The value of the third element in the vector
 */
float z(const vec3 *vec);

/**
 * Gets the value of the first element in the vector
 * @param vec The vector
 * @return The value of the first element in the vector
 */
float r(const vec3 *vec);

/**
 * Gets the value of the second element in the vector
 * @param vec The vector
 * @return The value of the second element in the vector
 */
float g(const vec3 *vec);

/**
 * Gets the value of the third element in the vector
 * @param vec The vector
 * @return The value of the third element in the vector
 */
float b(const vec3 *vec);

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
 * Adds two vectors together, returning a pointer to the sum vector
 * @param first The first vector to add
 * @param second The second vector to add
 * @return A new array containing the result of the addition
 */
vec3 *add_vec(const vec3 *first, const vec3 *second);

/**
 * Adds two vectors together and stores the sum into elems
 * @param elems Stores the sum of the addition
 * @param len The length of the result array
 * @param first The first vector to add
 * @param second The second vector to add
 */
void add_vec_arr(float *elems, size_t len, const vec3 *first,
                 const vec3 *second);

/**
 * Adds two vectors together without creating a new vector
 * The sum is stored into the first vector
 * @param first The first vector to add (stores the sum)
 * @param second The second vector to add
 */
void add_vec_self(vec3 *first, const vec3 *second);

/** 
 * Subtracts two vectors, returning a pointer to the difference vector
 * @param first The vector being subtracted from (minued)
 * @param second The vector subtracting (subtrahend)
 * @return A new vector containing the result of the subtraction
 */
vec3 *subtract_vec(const vec3 *first, const vec3 *second);

/**
 * Subtracts two vectors without creating a new vector
 * @param elems Stores the difference of the subtraction
 * @param len The length of the result array
 * @param first The vector being subtracted from
 * @param second The vector subtracting
 */
void subtract_vec_arr(float *elems, size_t len, const vec3 *first,
                      const vec3 *second);

/**
 * Adds two vectors together without creating a new vector
 * The difference is stored into the first vector
 * @param first The vector being subtracted from (stores the difference)
 * @param second The vector subtracting
 */
void subtract_vec_self(vec3 *first, const vec3 *second);

/** 
 * Calculates the dot product of two vectors
 * @param first The first vector of the product
 * @param second The second vector of the product
 * @return The dot product
 */
float dot_product(const vec3 *first, const vec3 *second);

/**
 * Calculates the cross product of two vectors
 * @param first The first vector of the product
 * @param second The second vector of the product
 * @return The cross product
 */
vec3 *cross_product(const vec3 *first, const vec3 *second);

/**
 * Calculates the cross prouct of two vectors and stores the result in elems
 * @param elems Stores the result of the cross product
 * @param len The length of the result array
 * @param first The first vector of the product
 * @param second The second vector of the product
 */
void cross_product_arr(float *elems, size_t len, const vec3 *first,
                       const vec3 *second);

/**
 * Calculates the entrywise product of two vectors
 * @param first The first vector of the product
 * @param second The second vector of the product
 * @return The entrywise product
 */
vec3 *entrywise_product(const vec3 *first, const vec3 *second);

/**
 * Calculates the entrywise product of two vectors and stores it in an array
 * @param elems The result of the entrywise product
 * @param len The length of the result array
 * @param first The first vector of the product
 * @param second The second vector of the product
 */
void entrywise_product_arr(float *elems, size_t len, const vec3 *first,
                           const vec3 *second);

/**
 * Calculates the entrywise product of two vectors without creating a new vector
 * The product is stored into the first vector
 * @param first The first vector of the product (stores the product)
 * @param second The second vector of the product
 */
void entrywise_product_self(vec3 *first, const vec3 *second);

/**
 * Calculates the entrywise division of two vectors
 * @param first The first vector of the division
 * @param second The second vector of the division
 * @return The entrywise quotient
 */
vec3 *entrywise_division(const vec3 *first, const vec3 *second);

/**
 * Calculates the entrywise division of two vectors and stores the result in an
 * array
 * @param elems The result of the entrywise division
 * @param len The length of the result array
 * @param first The first vector of the division
 * @param second The second vector of the division
 */
void entrywise_division_arr(float *elems, size_t len, const vec3 *first,
                            const vec3 *second);

/**
 * Calculates the entrywise division of two vectors without creating a new
 * vector
 * The quotient is stored into the first vector
 * @param first The first vector of the division (stores the quotient)
 * @param second The second vector of the division
 */
void entrywise_division_self(vec3 *first, const vec3 *second);

/**
 * Calculates the length of the vector
 * @param vec The vector whose length is being calculated
 * @return The length of the vector
 */
float length(const vec3 *vec);

/**
 * Calculates the length of a vector given by an array
 * @param arr The vector array
 * @param len The length of the array
 * @return The length of the vector
 */
float length_arr(const float *arr, size_t len);

/**
 * Calculates the squared length of the vector
 * @param vec The vector whose squared length is being calculated
 * @return The squared length of the vector
 */
float squared_length(const vec3 *vec);

/**
 * Creates a new unit vector from a given vector
 * @param vec The original vector
 * @return A new vector that is equal to the unit vector of the input
 */
vec3 *unit_vector(const vec3 *vec);

/**
 * Sets an array to the unit vector from a given vector
 * @param vec The original vector
 * @param elems The result array
 * @param len The length of the result array
 */
void unit_vector_arr(const vec3 *vec, float *elems, size_t len);

/**
 * Turns the vector into a unit vector
 * @param vec The vector being converted
 */
void make_unit_vector(vec3 *vec);

/**
 * Prints the values of a vector to stdout
 * @param vec The vector to be printed
 */
void print_vector(const vec3 *vec);

#endif
/* EOF */
