#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/ray.h"
#include "../include/vec3.h"

/* Determines whether a ray hits a sphere */
bool
hit_sphere(const vec3 *center, float radius, const ray *r)
{
    vec3 oc;
    float a, b, c;
    float discriminant;

    oc.e[0] = origin(r)->e[0] - center->e[0];
    oc.e[1] = origin(r)->e[1] - center->e[1];
    oc.e[2] = origin(r)->e[2] - center->e[2];

    a = dot_product(direction(r), direction(r));
    b = 2.0f * dot_product(&oc, direction(r));
    c = dot_product(&oc, &oc) - radius * radius;
    discriminant = b * b - 4 * a * c;

    return discriminant > 0;
}

/* Gets the color of a pixel pointed to by a ray */
vec3 *
color(const ray *r)
{
    vec3 *pixel_color = create_empty_vector();
    vec3 *unit_direction;
    vec3 *red = create_vector(1.0f, 0, 0);
    vec3 center;
    float t;

    set_elems(&center, 0, 0, -1.0f);
    
    if (hit_sphere(&center, 0.5f, r)) { return red; }

    unit_direction = unit_vector(direction(r));
    t = 0.5f * (y(unit_direction) + 1.0f);
    free(red);
    free(unit_direction);

    pixel_color->e[0] = (1.0f - t) + t * 0.5f;
    pixel_color->e[1] = (1.0f - t) + t * 0.7f;
    pixel_color->e[2] = (1.0f - t) + t * 0.7f;
    return pixel_color;
}

int
main(void)
{
    int i, j;
    int ir, ig, ib;
    int nx = 200, ny = 100;
    float u, v;
    FILE *output_file;
    char *filename = "ch4.ppm";
    vec3 horizontal, vertical, lower_left_corner, origin, scr_coord;
    set_elems(&horizontal, 4.0f, 0, 0);
    set_elems(&vertical, 2.0f, 0, 0);
    set_elems(&lower_left_corner, -2.0f, -1.0f, -1.0f);
    set_elems(&origin, 0, 0, 0);
    set_elems(&scr_coord, 0, 0, 0);
    vec3 *col;
    ray r;

    output_file = fopen(filename, "w");

    if (!output_file) {
        fprintf(stderr, "Could not open %s. Aborting.\n", filename);
        exit(EXIT_FAILURE);
    } /* if */

    fprintf(output_file, "P3\n%d %d\n255\n", nx, ny);

    for (j = ny - 1; j >= 0; j--) {
        for (i = 0; i < nx; i++) {
            u = (float)i / (float)nx;
            v = (float)j / (float)ny;
            scr_coord.e[0] = lower_left_corner.e[0]
                           + u * horizontal.e[0] + v * vertical.e[0];
            scr_coord.e[1] = lower_left_corner.e[1]
                           + u * horizontal.e[1] + v * vertical.e[1];
            scr_coord.e[2] = lower_left_corner.e[2]
                           + u * horizontal.e[2] + v * vertical.e[2];

            r.A = &origin;
            r.B = &scr_coord;
            col = color(&r);

            ir = (int)(255.99 * col->e[0]);
            ig = (int)(255.99 * col->e[1]);
            ib = (int)(255.99 * col->e[2]);

            fprintf(output_file, "%d %d %d\n", ir, ig, ib);
            delete_vector(col);
        } /* for */
    } /* for */

    fclose(output_file);
    return 0;
}
/* EOF */
