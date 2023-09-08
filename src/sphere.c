#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../include/sphere.h"

/* Creates a new sphere */
sphere *
create_sphere(vec3 *cen, float r)
{
    sphere *sph = malloc(sizeof(sphere));

    sph->center = cen;
    sph->radius = r;

    return sph;
}

/* Creates an empty sphere */
sphere *
create_empty_sphere(void)
{
    sphere *sph = malloc(sizeof(sphere));

    sph->center = create_empty_vector();
    sph->radius = 0;
    
    return sph;
}

/* Initializes a sphere */
void
init_sphere(sphere *sph, vec3 *cen, float r)
{
    sph->center = cen;
    sph->radius = r;
}

/* Sets a sphere's center */
void
set_sphere_center(sphere *sph, vec3 *cen)
{
    sph->center = cen;
}

/* Gets a sphere's center */
vec3 *
get_sphere_center(const sphere *sph)
{
    return sph->center;
}

/* Sets a sphere's radius */
void
set_sphere_radius(sphere *sph, float r)
{
    sph->radius = r;
}

/* Gets a sphere's radius */
float
get_sphere_radius(const sphere *sph)
{
    return sph->radius;
}

/* Deletes a sphere */
void
delete_sphere(sphere *sph)
{
    delete_vector(sph->center);
    free(sph);
}

/* Detects whether a ray hits the sphere */
bool
sphere_hit(const ray *r, const sphere *sph, float t_min, float t_max, hit_record *rec)
{
    float a, b, c, discriminant, temp;
    float x, y, z;
    vec3 oc, point_vec, norm;

    x = get_x(origin(r)) - get_x(sph->center);
    y = get_y(origin(r)) - get_y(sph->center);
    z = get_z(origin(r)) - get_z(sph->center);

    set_elems(&oc, x, y, z);

    a = dot_product(direction(r), direction(r));
    b = dot_product(&oc, direction(r));
    c = dot_product(&oc, &oc) - sph->radius * sph->radius;
    discriminant = b * b - a * c;

    if (discriminant > 0) {
        temp = (-b - sqrtf(b * b - a * c)) / a;
        if (temp < t_max && temp > t_min) {
            rec->t = temp;

            point_at_parameter(r, temp, &point_vec);
            rec->p = &point_vec;

            set_x(&norm, (get_x(&point_vec) - get_x(sph->center)) / sph->radius);
            set_y(&norm, (get_y(&point_vec) - get_y(sph->center)) / sph->radius);
            set_z(&norm, (get_z(&point_vec) - get_z(sph->center)) / sph->radius);
            rec->normal = &norm;

            return true;
        } /* if */

        temp = (-b + sqrtf(b * b - a * c)) / a;
        if (temp < t_max && temp > t_min) {
            rec->t = temp;

            point_at_parameter(r, temp, &point_vec);
            rec->p = &point_vec;

            set_x(&norm, (get_x(&point_vec) - get_x(sph->center)) / sph->radius);
            set_y(&norm, (get_y(&point_vec) - get_y(sph->center)) / sph->radius);
            set_z(&norm, (get_z(&point_vec) - get_z(sph->center)) / sph->radius);
            rec->normal = &norm;

            return true;
        } /* if */
    } /* if */
    return false;
}
/* EOF */
