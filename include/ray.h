#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct ray_t ray;

struct ray_t {
    vec3 *A, *B;
};

/**
 * Creates an empty ray
 */
ray *empty_ray( void );

/**
 * Creates a ray from two given vectors
 * @param a The ray origin vector
 * @param b The ray direction vector
 * @return The ray from these vectors
 */
ray *create_ray( vec3 *a, vec3 *b );

/**
 * Deletes a ray
 */
void delete_ray( ray *r );

/**
 * Gets the origin vector of the ray
 * @param r The ray
 */
vec3 *origin( const ray *r );

/**
 * Gets the direction vector of the ray
 * @param r The ray
 */
vec3 *direction( const ray *r );

/**
 * Points the ray in the direction of the parameter
 * @param f The parameter value
 */
vec3 *point_at_parameter( const ray *r, float f );

#endif
/* EOF */
