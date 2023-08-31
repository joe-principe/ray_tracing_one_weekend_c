#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>

#include "vec3.h"

/* Creates a new vector */
vec3 *
create_vector( float f1, float f2, float f3 )
{
    vec3 *vec = malloc( sizeof( *vec ) );

    vec->e0 = f1;
    vec->e1 = f2;
    vec->e2 = f3;
    
    return vec;
}

/* Creates a new zero vector */
vec3 *
empty_vector( void )
{
    vec3 *vec = malloc( sizeof( *vec ) );

    vec->e0 = 0;
    vec->e1 = 0;
    vec->e2 = 0;
    
    return vec;
}

/* Copies the values from one vector into a new vector */
vec3 *
copy_vector( vec3 *vec )
{
    vec3 *dupe = malloc( sizeof( *dupe ) );

    dupe->e0 = vec->e0;
    dupe->e1 = vec->e1;
    dupe->e2 = vec->e2;

    return dupe;
}

/* Deletes a vector */
void 
delete_vector( vec3 *vec )
{
    free( vec );
}

/* Gets the value of the first element in the vector */
float
x( const vec3 *vec )
{
    return vec->e0;
}

/* Gets the value of the second element in the vector */
float
y( const vec3 *vec )
{
    return vec->e1;
}

/* Gets the value of the third element in the vector */
float
z( const vec3 *vec )
{
    return vec->e2;
}

/* Gets the value of the first element in the vector */
float
r( const vec3 *vec )
{
    return vec->e0;
}

/* Gets the value of the second element in the vector */
float
g( const vec3 *vec )
{
    return vec->e1;
}

/* Gets the value of the third element in the vector */
float
b( const vec3 *vec )
{
    return vec->e2;
}

/* Adds a scalar value to every element of the vector */
void 
add_scalar( vec3 *vec, float f )
{
    vec->e0 += f;
    vec->e1 += f;
    vec->e2 += f;
}

/* Subtracts a scalar value from every element of the vector */
void 
subtract_scalar( vec3 *vec, float f )
{
    vec->e0 -= f;
    vec->e1 -= f;
    vec->e2 -= f;
}

/* Multiplies every element of the vector by a scalar value */
void 
multiply_scalar( vec3 *vec, float f )
{
    vec->e0 *= f;
    vec->e1 *= f;
    vec->e2 *= f;
}

/* Divides every element of the vector by a scalar value */
void 
divide_scalar( vec3 *vec, float f )
{
    vec->e0 /= f;
    vec->e1 /= f;
    vec->e2 /= f;
}

/* Negates every element of the vector */
void 
negate( vec3 *vec )
{
    vec->e0 *= -1;
    vec->e1 *= -1;
    vec->e2 *= -1;
}

/* Adds two vectors together */
vec3 *
add_vec( const vec3 *vec1, const vec3 *vec2 )
{
    vec3 *vec = malloc( sizeof( *vec ) );

    vec->e0 = vec1->e0 + vec2->e0;
    vec->e1 = vec1->e1 + vec2->e1;
    vec->e2 = vec1->e2 + vec2->e2;

    return vec;
}

/* Subtracts two vectors */
vec3 *
subtract_vec( const vec3 *vec1, const vec3 *vec2 )
{
    vec3 *vec = malloc( sizeof( *vec ) );

    vec->e0 = vec1->e0 - vec2->e0;
    vec->e1 = vec1->e1 - vec2->e1;
    vec->e2 = vec1->e2 - vec2->e2;

    return vec;
}

/* Calculates the dot product of two vectors */
float 
dot_product( const vec3 *vec1, const vec3 *vec2 )
{
    return ( vec1->e0 * vec2->e0 ) + ( vec1->e1 * vec2->e1 ) + 
           ( vec1->e2 * vec2->e2 );
}

/* Calculates the cross product of two vectors */
vec3 *
cross_product( const vec3 *vec1, const vec3 *vec2 )
{
    vec3 *vec = malloc( sizeof( *vec ) );

    vec->e0 =    vec1->e1 * vec2->e2 - vec2->e1 * vec1->e2;
    vec->e1 = -( vec1->e0 * vec2->e2 - vec2->e0 * vec1->e2 );
    vec->e2 =    vec1->e0 * vec2->e1 - vec2->e0 * vec1->e1;

    return vec;
}

/* Calculates the entrywise product of two vectors */
vec3 *
entrywise_product( const vec3 *vec1, const vec3 *vec2 )
{
    vec3 *vec = malloc( sizeof( *vec ) );

    vec->e0 = vec1->e0 * vec2->e0;
    vec->e1 = vec1->e1 * vec2->e1;
    vec->e2 = vec1->e2 * vec2->e2;

    return vec;
}

/* Calculates the length of the vector */
float 
length( const vec3 *vec )
{
    return sqrtf( vec->e0 * vec->e0 + vec->e1 * vec->e1 + vec->e2 * vec->e2 );
}

/* Calculates the squared length of the vector */
float 
squared_length( const vec3 *vec )
{
    return ( vec->e0 * vec->e0 + vec->e1 * vec->e1 + vec->e2 * vec->e2 );
}

/* Creates a unit vector from a given vector */
vec3 *
unit_vector( const vec3 *vec )
{
    vec3 *unit = malloc( sizeof( *unit ) );
    float l = length( vec );

    unit->e0 = vec->e0 / l;
    unit->e1 = vec->e1 / l;
    unit->e2 = vec->e2 / l;

    return unit;
}

/* Turns the vector into a unit vector */
void 
make_unit_vector( vec3 *vec )
{
    float k = 1.0f / length( vec );

    vec->e0 *= k;
    vec->e1 *= k;
    vec->e2 *= k;
}

/* Prints the values of a vector to stdout */
void
print_vector( const vec3 *vec )
{
    printf( "%.2f %.2f %.2f\n", vec->e0, vec->e1, vec->e2 );
}
/* EOF */
