#include <stdlib.h>

#include "../include/ray.h"

/* Creates an empty ray */
ray *
empty_ray( void )
{
    ray *r = malloc( sizeof( *r ) );

    r->A = empty_vector();
    r->B = empty_vector();

    return r;
}

/* Creates a ray from the given vectors */
ray *
create_ray( vec3 *a, vec3 *b )
{
    ray *r = malloc( sizeof( *r ) );

    r->A = a;
    r->B = b;

    return r;
}

/* Deletes a ray */
void
delete_ray( ray *r )
{
    delete_vector( r->A );
    delete_vector( r->B );
    free( r );
}

/* Gets the origin vector of a ray */
vec3 *
origin( const ray *r )
{
    return r->A;
}

/* Gets the direction vector of a ray */
vec3 *
direction( const ray *r )
{
    return r->B;
}

/* Points the ray in the direction of the parameter */
vec3 *
point_at_parameter( const ray *r, float f )
{
    vec3 *vec = malloc( sizeof( vec3 * ) );

    vec->e0 = r->A->e0 + f * r->B->e0;
    vec->e1 = r->A->e1 + f * r->B->e1;
    vec->e2 = r->A->e2 + f * r->B->e2;

    return vec;
}
