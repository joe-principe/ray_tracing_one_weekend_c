#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct ray_t ray;

struct ray_t
{
    vec3 *A, *B;
};

/**
 * Creates an empty ray
 * @return An empty ray whose vectors are both the zero vector
 */
ray *create_empty_ray(void);

/**
 * Creates a ray from two given vectors
 * @param a The ray origin vector
 * @param b The ray direction vector
 * @return The ray from these vectors
 */
ray *create_ray(vec3 *a, vec3 *b);

/**
 * Points the vectors of the input ray to the parameter vectors 
 * @param a The origin vector
 * @param b The direction vector
 */
void set_ray_vectors(ray *r, vec3 *a, vec3* b);

/**
 * Deletes a ray. Should only be used if ray AND its vectors were heap allocated
 */
void delete_ray(ray *r);

/**
 * Gets the origin vector of the ray
 * @param r The ray
 * @return The origin vector
 */
vec3 *origin(const ray *r);

/**
 * Gets the direction vector of the ray
 * @param r The ray
 * @return The direction vector
 */
vec3 *direction(const ray *r);

/**
 * Points an input vector in the direction of the ray at the parameter 
 * @param r The ray
 * @param f The parameter value
 * @param vec The vector to point
 */
void point_at_parameter(const ray *r, float f, vec3 *vec);

/**
 * Creates a vector that points in the direction of the parameter
 * @param r The ray
 * @param f The parameter value
 * @return A new vector that points in the direction
 */
vec3 *point_at_parameter_new(const ray *r, float f);

#endif
/* EOF */
