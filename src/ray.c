#include <stdlib.h>

#include "../include/ray.h"

/* Creates an empty ray */
ray *
create_empty_ray(void)
{
    ray *r = malloc(sizeof(*r));

    r->A = create_empty_vector();
    r->B = create_empty_vector();

    return r;
}

/* Creates a ray from the given vectors */
ray *
create_ray(vec3 *a, vec3 *b)
{
    ray *r = malloc(sizeof(*r));

    r->A = a;
    r->B = b;

    return r;
}

/* Sets the vectors of the input ray */
void
set_ray_vectors(ray *r, vec3 *a, vec3 *b)
{
    r->A = a;
    r->B = b;
}

/* Deletes a ray */
void
delete_ray(ray *r)
{
    delete_vector(r->A);
    delete_vector(r->B);
    free(r);
}

/* Gets the origin vector of a ray */
vec3 *
origin(const ray *r)
{
    return r->A;
}

/* Gets the direction vector of a ray */
vec3 *
direction(const ray *r)
{
    return r->B;
}

/* Points an input vector in the direction of the ray at the parameter */
void
point_at_parameter(const ray *r, float f, vec3 *vec)
{
    vec->e[0] = r->A->e[0] + f * r->B->e[0];
    vec->e[1] = r->A->e[1] + f * r->B->e[1];
    vec->e[2] = r->A->e[2] + f * r->B->e[2];

}

/* Creates a vector that points in the direction of the ray at parameter */
vec3 *
point_at_parameter_new(const ray *r, float f)
{
    vec3 *vec = malloc(sizeof(vec3 *));

    vec->e[0] = r->A->e[0] + f * r->B->e[0];
    vec->e[1] = r->A->e[1] + f * r->B->e[1];
    vec->e[2] = r->A->e[2] + f * r->B->e[2];

    return vec;
}
/* EOF */