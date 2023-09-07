#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/ray.h"
#include "../include/vec3.h"

/**
 * Detects whether a ray hits the sphere
 * @param center The center of the circle
 * @param radius The radius of the circle
 * @param r The ray
 * @return Whether or not the ray hits the sphere
 */
bool
hit_sphere(const vec3 *center, float radius, const ray *r )
{
    float a, b, c, discriminant;
    float x, y, z;
    vec3 oc;

    x = get_x(origin(r)) - get_x(center);
    y = get_y(origin(r)) - get_y(center);
    z = get_z(origin(r)) - get_z(center);

    set_elems(&oc, x, y, z);

    a = dot_product(direction(r), direction(r));
    b = 2.0f * dot_product(&oc, direction(r));
    c = dot_product(&oc, &oc) - radius * radius;
    discriminant = b * b - 4 * a * c;

    return discriminant > 0;
}

/**
 * Sets the color of a pixel at the given vector
 * @param r The ray in which the camera is looking
 * @param vec The color vector
 */
void
color(const ray *r, vec3 *vec)
{
    vec3 unit_dir, first, second, center;

    set_elems(&first, 1.0f, 1.0f, 1.0f);
    set_elems(&second, 0.5f, 0.7f, 1.0f);
    set_elems(&center, 0, 0, -1);

    if (hit_sphere(&center, 0.5, r)) {
        set_elems(vec, 1, 0, 0);
        return;
    } /* if */

    turn_into_unit_vector(&unit_dir, direction(r));

    float t = 0.5f * (get_y(&unit_dir) + 1.0f);

    multiply_scalar(&first, (1.0f - t));
    multiply_scalar(&second, t);
    add_vec(vec, &first, &second);
}

int
main(void)
{
    int i, j;
    int ir, ig, ib;
    int nx = 200;
    int ny = 100;
    float u, v;
    float x, y, z;
    FILE *output_file;
    char *filename = "ch4.ppm";
    vec3 lower_left_corner, horizontal, vertical, origin;
    vec3 scr_coord, pixel_color;
    ray r;

    set_elems(&lower_left_corner, -2.0f, -1.0f, -1.0f);
    set_elems(&horizontal, 4.0f, 0, 0);
    set_elems(&vertical, 0, 2.0f, 0);
    zero_out_vector(&origin);

    output_file = fopen(filename, "w");

    if (!output_file) {
        perror("Could not open ch4.ppm. Aborting.\n");
        exit(EXIT_FAILURE);
    } /* if */

    fprintf(output_file, "P3\n%d %d\n255\n", nx, ny);

    for (j = ny - 1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            u = (float)i / (float)nx;
            v = (float)j / (float)ny;
            x = get_x(&lower_left_corner) + u * get_x(&horizontal)
                + v * get_x(&vertical);
            y = get_y(&lower_left_corner) + u * get_y(&horizontal)
                + v * get_y(&vertical);
            z = get_z(&lower_left_corner) + u * get_z(&horizontal)
                + v * get_z(&vertical);

            set_elems(&scr_coord, x, y, z);

            set_ray_vectors(&r, &origin, &scr_coord);
            color(&r, &pixel_color);

            ir = (int)(255.99 * get_x(&pixel_color));
            ig = (int)(255.99 * get_y(&pixel_color));
            ib = (int)(255.99 * get_z(&pixel_color));

            fprintf(output_file, "%d %d %d\n", ir, ig, ib);
        } /* for */
    } /* for */

    fclose(output_file);

    return 0;
}
/* EOF */
