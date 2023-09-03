#include <stdio.h>
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

vec3 *
create_vector_from_array(const float *values, size_t len)
{
    vec3 *vec = malloc(sizeof(vec3));

    if (len != 3) {
        perror("Length of values in \"create_vector_from_array\""
               "must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    vec->e[0] = values[0];
    vec->e[1] = values[1];
    vec->e[2] = values[2];

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

/* Sets a vector's elements from individual values */
void
set_elems(vec3 *vec, float f1, float f2, float f3)
{
    vec->e[0] = f1;
    vec->e[1] = f2;
    vec->e[2] = f3;
}

/* Sets a vector's elements from an array of values */
void
set_elems_from_array(vec3 *vec, const float *values, size_t len)
{
    if (len != 3) {
        perror("Length of values in \"set_elems_from_array\" must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    vec->e[0] = values[0];
    vec->e[1] = values[1];
    vec->e[2] = values[2];
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

/* Gets the value of the first element in the vector */
float
x(const vec3 *vec)
{
    return vec->e[0];
}

/* Gets the value of the second element in the vector */
float
y(const vec3 *vec)
{
    return vec->e[1];
}

/* Gets the value of the third element in the vector */
float
z(const vec3 *vec)
{
    return vec->e[2];
}

/* Gets the value of the first element in the vector */
float
r(const vec3 *vec)
{
    return vec->e[0];
}

/* Gets the value of the second element in the vector */
float
g(const vec3 *vec)
{
    return vec->e[1];
}

/* Gets the value of the third element in the vector */
float
b(const vec3 *vec)
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

/* Adds two vectors together */
vec3 *
add_vec(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] + second->e[0];
    vec->e[1] = first->e[1] + second->e[1];
    vec->e[2] = first->e[2] + second->e[2];

    return vec;
}

/* Adds two vectors together and stores the sum in the array */
void
add_vec_arr(float *elems, size_t len, const vec3 *first, const vec3 *second)
{
    if (len != 3) {
        perror("Length of values in \"add_vec_arr\" must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    elems[0] = first->e[0] + second->e[0];
    elems[1] = first->e[1] + second->e[1];
    elems[2] = first->e[2] + second->e[2];
}

/* Adds two vectors and stores the sum in the first vector */
void
add_vec_self(vec3 *first, const vec3 *second)
{
    first->e[0] += second->e[0];
    first->e[1] += second->e[1];
    first->e[2] += second->e[2];
}

/* Subtracts two vectors */
vec3 *
subtract_vec(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] - second->e[0];
    vec->e[1] = first->e[1] - second->e[1];
    vec->e[2] = first->e[2] - second->e[2];

    return vec;
}

/* Subtracts two vectors and stores the sum in the array */
void
subtract_vec_arr(float *elems, size_t len, const vec3 *first,
                 const vec3 *second)
{
    if (len != 3) {
        perror("Length of values in \"subtract_vec_arr\" must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    elems[0] = first->e[0] - second->e[0];
    elems[1] = first->e[1] - second->e[1];
    elems[2] = first->e[2] - second->e[2];
}

/* Subtracts two vectors and stores the difference in the first vector */
void
subtract_vec_self(vec3 *first, const vec3 *second)
{
    first->e[0] -= second->e[0];
    first->e[1] -= second->e[1];
    first->e[2] -= second->e[2];
}

/* Calculates the dot product of two vectors */
float 
dot_product(const vec3 *first, const vec3 *second)
{
    return first->e[0] * second->e[0] 
         + first->e[1] * second->e[1]
         + first->e[2] * second->e[2];
}

/* Calculates the cross product of two vectors */
vec3 *
cross_product(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] =   first->e[1] * second->e[2] - second->e[1] * first->e[2];
    vec->e[1] = -(first->e[0] * second->e[2] - second->e[0] * first->e[2]);
    vec->e[2] =   first->e[0] * second->e[1] - second->e[0] * first->e[1];

    return vec;
}

/* Calculates the cross product and stores it in an array */
void
cross_product_arr(float *elems, size_t len, const vec3 *first,
                  const vec3 *second)
{
    if (len != 3) {
        perror("Length of values in \"cross_product_arr\""
                "must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    elems[0] =   first->e[1] * second->e[2] - first->e[2] * second->e[1];
    elems[1] = -(first->e[0] * second->e[2] - first->e[2] * second->e[0]);
    elems[2] =   first->e[0] * second->e[1] - first->e[1] * second->e[0];
}

/* Calculates the entrywise product and stores it in a new vector */
vec3 *
entrywise_product(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] * second->e[0];
    vec->e[1] = first->e[1] * second->e[1];
    vec->e[2] = first->e[2] * second->e[2];

    return vec;
}

/* Calculates the entrywise product and stores it into an array */
void
entrywise_product_arr(float *elems, size_t len, const vec3 *first,
                      const vec3 *second)
{
    if (len != 3) {
        perror("Length of values in \"entrywise_product_arr\""
                "must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    elems[0] = first->e[0] * second->e[0];
    elems[1] = first->e[1] * second->e[1];
    elems[2] = first->e[2] * second->e[2];
}

/* Calculates the entrywise product and stores into the first vector */
void
entrywise_product_self(vec3 *first, const vec3 *second)
{
    first->e[0] *= second->e[0];
    first->e[1] *= second->e[1];
    first->e[2] *= second->e[2];
}

/* Calculates the entrywise division and stores the result into a new vector */
vec3 *
entrywise_division(const vec3 *first, const vec3 *second)
{
    vec3 *vec = malloc(sizeof(*vec));

    vec->e[0] = first->e[0] / second->e[0];
    vec->e[1] = first->e[1] / second->e[1];
    vec->e[2] = first->e[2] / second->e[2];

    return vec;
}

/* Calculates the entrywise division and stores the result into an array */
void
entrywise_division_arr(float *elems, size_t len, const vec3 *first,
                       const vec3 *second)
{
    if (len != 3) {
        perror("Length of values in \"entrywise_division_arr\""
                "must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    elems[0] = first->e[0] / second->e[0];
    elems[1] = first->e[1] / second->e[1];
    elems[2] = first->e[2] / second->e[2];
}

/* Calculates the entrywise division and stores into the first vector */
void
entrywise_division_self(vec3 *first, const vec3 *second)
{
    first->e[0] /= second->e[0];
    first->e[1] /= second->e[1];
    first->e[2] /= second->e[2];
}

/* Calculates the length of the vector */
float 
length(const vec3 *vec)
{
    return sqrtf(vec->e[0] * vec->e[0]
               + vec->e[1] * vec->e[1]
               + vec->e[2] * vec->e[2]);
}

/* Calculates the length of a vector as an array */
float
length_arr(const float *elems, size_t len)
{
    if (len != 3) {
        perror("Length of values in \"length_arr\""
                "must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    return sqrtf(elems[0] * elems[0]
               + elems[1] * elems[1]
               + elems[2] * elems[2]);
}

/* Calculates the squared length of the vector */
float 
squared_length(const vec3 *vec)
{
    return vec->e[0] * vec->e[0]
         + vec->e[1] * vec->e[1]
         + vec->e[2] * vec->e[2];
}

/* Creates a unit vector from a given vector */
vec3 *
unit_vector(const vec3 *vec)
{
    vec3 *unit = malloc(sizeof(*unit));
    float l = length(vec);

    unit->e[0] = vec->e[0] / l;
    unit->e[1] = vec->e[1] / l;
    unit->e[2] = vec->e[2] / l;

    return unit;
}

/* Sets an array to the unit vector from a given vector */
void
unit_vector_arr(const vec3 *vec, float *elems, size_t len)
{
    float l = length(vec);
    
    elems[0] = vec->e[0] / l;
    elems[1] = vec->e[1] / l;
    elems[2] = vec->e[2] / l;
}

/* Turns the vector into a unit vector */
void 
make_unit_vector(vec3 *vec)
{
    float k = 1.0f / length(vec);

    vec->e[0] *= k;
    vec->e[1] *= k;
    vec->e[2] *= k;
}

/* Prints the values of a vector to stdout */
void
print_vector(const vec3 *vec)
{
    printf("%.2f %.2f %.2f\n", vec->e[0], vec->e[1], vec->e[2]);
}

/* Prints the values of an array to stdout */
void
print_arr(const float *elems, size_t len)
{
    if (len != 3) {
        perror("Length of values in \"print_arr\""
                "must be equal to 3\n");
        exit(EXIT_FAILURE);
    } /* if */

    printf("%.2f %.2f %.2f\n", elems[0], elems[1], elems[2]);
}
/* EOF */
