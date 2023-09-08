#ifndef SPHERE_H
#define SPHERE_H

#include <stdbool.h>

#include "hitable.h"

typedef struct sphere_t sphere;

struct sphere_t
{
    vec3 *center;
    float radius;
};

/**
 * Creates a new sphere
 * @param cen The coordinates of the center of the sphere
 * @param r The radius of the sphere
 * @return A sphere of radius r centered at cen
 */
sphere *create_sphere(vec3 *cen, float r);

/**
 * Creates an empty sphere
 * @return A sphere of radius 0 centered at the origin
 */
sphere *create_empty_sphere(void);

/**
 * Initializes a sphere with the given center and radius
 * @param sph The sphere to initialize
 * @param cen The coordinates of the center of the sphere
 * @param r The radius of the sphere
 */
void init_sphere(sphere *sph, vec3 *cen, float r);

/**
 * Sets the center of a sphere
 * @param sph The sphere
 * @param cen The coordinates of the center of the sphere
 */
void set_sphere_center(sphere* sph, vec3 *cen);

/**
 * Gets the center of a sphere
 * @param sph The sphere
 * @return A vec3 containing the coordinates of the sphere's center
 */
vec3 *get_sphere_center(const sphere *sph);

/**
 * Sets the radius of a sphere
 * @param sph The sphere
 * @param r The new radius of the sphere
 */
void set_sphere_radius(sphere *sph, float r);

/**
 * Gets the radius of a sphere
 * @param sph The sphere
 * @return The radius of the sphere
 */
float get_sphere_radius(const sphere *sph);

/**
 * Deletes a sphere
 * @param sph The sphere to delete
 */
void delete_sphere(sphere *sph);

/**
 * Detects if the ray hits the sphere
 * @param r The ray
 * @param t_min The minimum value of the parameter interval
 * @param t_max The maximum value of the parameter interval
 * @param rec The information about the ray hit
 * @return Whether or not the ray hits the sphere
 */
bool sphere_hit(const ray *r, const sphere *sph, float t_min, float t_max, hit_record *rec);

#endif
/* EOF */
