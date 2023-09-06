#include <stdlib.h>
#include <tgmath.h>

#include "../include/vec3.h"

/* Creates a new vector */
vec3 *
create_vector(float f1, float f2, float f3)
{
    vec3 *vec = malloc(sizeof(vec3));

    vec->e[0] = f1;
    vec->e[1] = f2;
    vec->e[2] = f3;
    
    return vec;
}

/* Creates a new zero vector */
vec3 *
create_empty_vector(void)
{
    vec3 *vec = malloc(sizeof(vec3));

    vec->e[0] = 0;
    vec->e[1] = 0;
    vec->e[2] = 0;
    
    return vec;
}

/* Creates a unit vector from a given direction vector */
vec3 *
new_unit_vector(const vec3 *vec)
{
    vec3 *unit = malloc(sizeof(*unit));
    float l = length(vec);

    unit->e[0] = vec->e[0] / l;
    unit->e[1] = vec->e[1] / l;
    unit->e[2] = vec->e[2] / l;

    return unit;
}

/* Turns the vector into a unit vector */
void 
turn_into_unit_vector(vec3 *first, const vec3 *second)
{
    float k = 1.0f / length(second);

    first->e[0] *= k;
    first->e[1] *= k;
    first->e[2] *= k;
}

/* Sets a vector's elements from individual values */
void
set_elems(vec3 *vec, float f1, float f2, float f3)
{
    vec->e[0] = f1;
    vec->e[1] = f2;
    vec->e[2] = f3;
}

/* Sets a vector's elements to zero */
void zero_out_vector(vec3 *vec)
{
    vec->e[0] = 0;
    vec->e[1] = 0;
    vec->e[2] = 0;
}

/* Deletes a vector */
void 
delete_vector(vec3 *vec)
{
    free(vec);
}

/* Calculates the length of the vector */
float 
length(const vec3 *vec)
{
    return sqrtf(vec->e[0] * vec->e[0]
               + vec->e[1] * vec->e[1]
               + vec->e[2] * vec->e[2]);
}

/* Calculates the squared length of the vector */
float 
squared_length(const vec3 *vec)
{
    return vec->e[0] * vec->e[0]
         + vec->e[1] * vec->e[1]
         + vec->e[2] * vec->e[2];
}

/* Gets the value of the first element in the vector */
float
get_x(const vec3 *vec)
{
    return vec->e[0];
}

/* Gets the value of the second element in the vector */
float
get_y(const vec3 *vec)
{
    return vec->e[1];
}

/* Gets the value of the third element in the vector */
float
get_z(const vec3 *vec)
{
    return vec->e[2];
}

/* Gets the value of the first element in the vector */
float
get_r(const vec3 *vec)
{
    return vec->e[0];
}

/* Gets the value of the second element in the vector */
float
get_g(const vec3 *vec)
{
    return vec->e[1];
}

/* Gets the value of the third element in the vector */
float
get_b(const vec3 *vec)
{
    return vec->e[2];
}

/* Adds a scalar value to every element of the vector */
void 
add_scalar(vec3 *vec, float f)
{
    vec->e[0] += f;
    vec->e[1] += f;
    vec->e[2] += f;
}

/* Subtracts a scalar value from every element of the vector */
void 
subtract_scalar(vec3 *vec, float f)
{
    vec->e[0] -= f;
    vec->e[1] -= f;
    vec->e[2] -= f;
}

/* Multiplies every element of the vector by a scalar value */
void 
multiply_scalar(vec3 *vec, float f)
{
    vec->e[0] *= f;
    vec->e[1] *= f;
    vec->e[2] *= f;
}

/* Divides every element of the vector by a scalar value */
void 
divide_scalar(vec3 *vec, float f)
{
    vec->e[0] /= f;
    vec->e[1] /= f;
    vec->e[2] /= f;
}

/* Negates every element of the vector */
void 
negate(vec3 *vec)
{
    vec->e[0] *= -1;
    vec->e[1] *= -1;
    vec->e[2] *= -1;
}

/* Adds two vectors together and stores the sum in the array */
void
add_vec(vec3 *sum, const vec3 *first, const vec3 *second)
{
    sum->e[0] = first->e[0] + second->e[0];
    sum->e[1] = first->e[1] + second->e[1];
    sum->e[2] = first->e[2] + second->e[2];
}

/* Adds two vectors together */
vec3 *
add_vec_new(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] + second->e[0];
    vec->e[1] = first->e[1] + second->e[1];
    vec->e[2] = first->e[2] + second->e[2];

    return vec;
}

/* Subtracts two vectors and stores the sum in the array */
void
subtract_vec(vec3 *diff, const vec3 *first, const vec3 *second)
{
    diff->e[0] = first->e[0] - second->e[0];
    diff->e[1] = first->e[1] - second->e[1];
    diff->e[2] = first->e[2] - second->e[2];
}

/* Subtracts two vectors */
vec3 *
subtract_vec_new(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] - second->e[0];
    vec->e[1] = first->e[1] - second->e[1];
    vec->e[2] = first->e[2] - second->e[2];

    return vec;
}

/* Calculates the dot product of two vectors */
float 
dot_product(const vec3 *first, const vec3 *second)
{
    return first->e[0] * second->e[0] 
         + first->e[1] * second->e[1]
         + first->e[2] * second->e[2];
}

/* Calculates the cross product and stores it in an array */
void
cross_product(vec3 *prod, const vec3 *first, const vec3 *second)
{
    prod->e[0] =   first->e[1] * second->e[2] - first->e[2] * second->e[1];
    prod->e[1] = -(first->e[0] * second->e[2] - first->e[2] * second->e[0]);
    prod->e[2] =   first->e[0] * second->e[1] - first->e[1] * second->e[0];
}

/* Calculates the cross product of two vectors */
vec3 *
cross_product_new(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] =   first->e[1] * second->e[2] - second->e[1] * first->e[2];
    vec->e[1] = -(first->e[0] * second->e[2] - second->e[0] * first->e[2]);
    vec->e[2] =   first->e[0] * second->e[1] - second->e[0] * first->e[1];

    return vec;
}

/* Calculates the entrywise product and stores it into an array */
void
entrywise_product(vec3 *prod, const vec3 *first, const vec3 *second)
{
    prod->e[0] = first->e[0] * second->e[0];
    prod->e[1] = first->e[1] * second->e[1];
    prod->e[2] = first->e[2] * second->e[2];
}

/* Calculates the entrywise product and stores it in a new vector */
vec3 *
entrywise_product_new(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] * second->e[0];
    vec->e[1] = first->e[1] * second->e[1];
    vec->e[2] = first->e[2] * second->e[2];

    return vec;
}

/* Calculates the entrywise division and stores the result into an array */
void
entrywise_division(vec3 *quotient, const vec3 *first, const vec3 *second)
{
    quotient->e[0] = first->e[0] / second->e[0];
    quotient->e[1] = first->e[1] / second->e[1];
    quotient->e[2] = first->e[2] / second->e[2];
}

/* Calculates the entrywise division and stores the result into a new vector */
vec3 *
entrywise_division_new(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] / second->e[0];
    vec->e[1] = first->e[1] / second->e[1];
    vec->e[2] = first->e[2] / second->e[2];

    return vec;
}
/* EOF */