#ifndef VEC3_H
#define VEC3_H

typedef struct vec3_t vec3;

struct vec3_t{
    float e0, e1, e2;
};

/**
 * Creates a new vector
 * @param f1 The x (aka r) component
 * @param f2 The y (aka g) component
 * @param f3 The z (aka b) component
 */
vec3 *create_vector( float f1, float f2, float f3 );

/**
 * Creates a new zero vector
 */
vec3 *empty_vector( void );

/**
 * Copies the values from one vector into a new vector
 * @param vec The vector whose values are copied
 */
vec3 *copy_vector( vec3 *vec );

/**
 * Deletes a vector
 * @param vec The vector to delete
 */
void delete_vector( vec3 *vec );

/**
 * Gets the value of the first element in the vector
 * @param vec The vector
 * @return The valueu of the first element in the vector
 */
float x( const vec3 *vec );

/**
 * Gets the value of the second element in the vector
 * @param vec The vector
 * @return The value of the second element in the vector
 */
float y( const vec3 *vec );

/**
 * Gets the value of the third element in the vector
 * @param vec The vector
 * @return The value of the third element in the vector
 */
float z( const vec3 *vec );

/**
 * Gets the value of the first element in the vector
 * @param vec The vector
 * @return The valueu of the first element in the vector
 */
float r( const vec3 *vec );

/**
 * Gets the value of the second element in the vector
 * @param vec The vector
 * @return The value of the second element in the vector
 */
float g( const vec3 *vec );

/**
 * Gets the value of the third element in the vector
 * @param vec The vector
 * @return The value of the third element in the vector
 */
float b( const vec3 *vec );

/**
 * Adds a scalar value to every element of the vector
 * @param vec The vector being added to
 * @param f The scalar value to add
 */
void add_scalar( vec3 *vec, float f );

/**
 * Subtracts a scalar value from every element of the vector
 * @param vec The vector being subtracted from
 * @param f The scalar value to subtract
 */
void subtract_scalar( vec3 *vec, float f );

/**
 * Multiplies every element of the vector by a scalar value
 * @param vec The vector being multiplied
 * @param f The scalar value to multiply
 */
void multiply_scalar( vec3 *vec, float f );

/**
 * Divides every element of the vector by a scalar value
 * @param vec The vector being divided
 * @param f The scalar value to divide
 */
void divide_scalar( vec3 *vec, float f );

/**
 * Negates every element of the vector
 * @param vec The vector to negate
 */
void negate( vec3 *vec );

/**
 * Adds two vectors together
 * @param vec1 The first vector to add
 * @param vec2 The second vector to add
 * @return A new vector containing the result of the addition
 */
vec3 *add_vec( const vec3 *vec1, const vec3 *vec2 );

/**
 * Adds two vectors together without creating a new vector
 * The sum is stored into the first vector
 * @param vec1 The first vector to add (stores the sum)
 * @param vec2 The second vector to add
 */
void add_vec_self( vec3 *vec1, const vec3 *vec2 );

/** 
 * Subtracts two vectors
 * @param vec1 The vector being subtracted from (minued)
 * @param vec2 The vector subtracting (subtrahend)
 * @return A new vector containing the result of the subtraction
 */
vec3 *subtract_vec( const vec3 *vec1, const vec3 *vec2 );

/**
 * Adds two vectors together without creating a new vector
 * The difference is stored into the first vector
 * @param vec1 The vector being subtracted from (stores the difference)
 * @param vec2 The vector subtracting
 */
void subtract_vec_self( vec3 *vec1, const vec3 *vec2 );

/** 
 * Calculates the dot product of two vectors
 * @param vec1 The first vector of the product
 * @param vec2 The second vector of the product
 * @return The dot product
 */
float dot_product( const vec3 *vec1, const vec3 *vec2 );

/**
 * Calculates the cross product of two vectors
 * @param vec1 The first vector of the product
 * @param vec2 The second vector of the product
 * @return The cross product
 */
vec3 *cross_product( const vec3 *vec1, const vec3 *vec2 );

/**
 * Calculates the entrywise product of two vectors
 * @param vec1 The first vector of the product
 * @param vec2 The second vector of the product
 * @return The entrywise product
 */
vec3 *entrywise_product( const vec3 *vec1, const vec3 *vec2 );

/**
 * Calculates the entrywise product of two vectors without creating a new vector
 * The product is stored into the first vector
 * @param vec1 The first vector of the product (stores the product)
 * @param vec2 The second vector of the product
 */
void entrywise_product_self( vec3 *vec1, const vec3 *vec2 );

/**
 * Calculates the entrywise division of two vectors
 * @param vec1 The first vector of the division
 * @param vec2 The second vector of the division
 * @return The entrywise quotient
 */
vec3 *entrywise_division( const vec3 *vec1, const vec3 *vec2 );

/**
 * Calculates the entrywise division of two vectors without creating a new
 * vector
 * The quotient is stored into the first vector
 * @param vec1 The first vector of the division (stores the quotient)
 * @param vec2 The second vector of the division
 */
void entrywise_division_self( vec3 *vec1, const vec3 *vec2 );

/**
 * Calculates the length of the vector
 * @param vec The vector whose length is being calculated
 */
float length( const vec3 *vec );

/**
 * Calculates the squared length of the vector
 * @param vec The vector whose squared length is being calculated
 */
float squared_length( const vec3 *vec );

/**
 * Creates a unit vector from a given vector
 * @param vec The original vector
 */
vec3 *unit_vector( const vec3 *vec );

/**
 * Turns the vector into a unit vector
 * @param vec The vector being converted
 */
void make_unit_vector( vec3 *vec );

/**
 * Prints the values of a vector to stdout
 * @param vec The vector to be printed
 */
void print_vector( const vec3 *vec );

#endif
/* EOF */
