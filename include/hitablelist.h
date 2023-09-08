#ifndef HITABLELIST_H
#define HITABLELIST_H

#include "sphere.h"

typedef struct sphere_list_t sphere_list;

struct sphere_list_t
{
    sphere **list;
    int list_size;
};

/**
 * Creates a new list of spheres
 * @param l The sphere array
 * @param n The size of the list
 * @return The new sphere list
 */
sphere_list *create_sphere_list(sphere **l, int n);

/**
 * Creates an empty sphere list
 * @return An empty sphere lis
 */
sphere_list *create_empty_sphere_list(void);

/**
 * Deletes a sphere list
 * @param sl The sphere list
 */
void delete_sphere_list(sphere_list *sl);

/**
 * Gets the list of spheres from a sphere list
 * @param sl The sphere list
 * @return The sphere array
 */
sphere **get_sphere_list(const sphere_list *sl);

/**
 * Sets the list of spheres for a sphere list
 * @param sl The sphere list
 * @param l The sphere array
 */
void set_sphere_list(sphere_list *sl, sphere **l);

/**
 * Gets the size of the sphere list
 * @param sl The sphere list
 * @return The size of the list
 */
int get_sphere_list_size(const sphere_list *sl);

/**
 * Gets the sphere at a given index
 * @param sl The sphere list
 * @param index The index of the sphere to retrieve
 * @return A pointer to the sphere at the given index
 */
sphere *get_sphere_at_index(sphere_list *sl, int index);

/**
 * Appends a sphere to the list
 * @param sl The sphere list to add to
 */
void append_sphere(sphere_list *sl);

/**
 * Prepends a sphere to the list
 * @param sl The sphere list to add to
 */
void prepend_sphere(sphere_list *sl);

/**
 * Inserts a sphere at the given index
 * @note If index is outside bounds, sphere will be appended/prepended appropriately
 * @param sl The sphere list to add to
 * @param index The index to insert the sphere
 */
void insert_sphere(sphere_list *sl, int index);

/**
 * Removes a sphere from a given index
 * @note If the index is outside bounds, does nothing
 * @param sl The sphere list to remove from
 * @param index The index of the sphere to remove
 * @return The removed sphere
 */
sphere *remove_sphere(sphere_list *sl, int index);

/**
 * Removes a sphere from the end of the list
 * @param sl The sphere list to remove from
 * @return The sphere removed
 */
sphere *pop_sphere(sphere_list *sl);

/**
 * Clones the sphere at a given index
 * @param clone The sphere clone
 * @param sl The sphere list
 * @param index The index of the sphere to clone
 */
void clone_sphere_at_index(sphere *clone, const sphere_list *sl, int index);

/**
 * Creates a new clone of the sphere at a given index
 * @param sl The sphere list
 * @param index The index of the sphere to clone
 * @return The clone sphere
 */
sphere *clone_sphere_at_index_new(const sphere_list *sl, int index);

/**
 * Determines if the ray hits any of the spheres within the list
 * @param r The ray
 * @param sl The sphere list
 * @param t_min The minimum value of the parameter interval
 * @param t_max The maximum value of the parameter interval
 * @param rec The information about what the ray hit
 * @return Whether the ray hits any of the spheres
 */
bool sphere_list_hit(const ray *r, float t_min, float t_max, hit_record *rec);

#endif
/* EOF */
