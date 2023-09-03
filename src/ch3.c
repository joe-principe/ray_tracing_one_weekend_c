#include <stdio.h>
#include <stdlib.h>

#include "../include/ray.h"

/**
 * Linearly interpolates between a soft blue and white color
 * @param r The ray in which the camera is looking
 * @return A vector containing the colors at that coordinate
 */
vec3 *
color(const ray *r)
{
    vec3 *unit_direction = unit_vector(direction(r));
    vec3 first = { 1.0f, 1.0f, 1.0f };
    vec3 second = { 0.5f, 0.7f, 1.0f };
    vec3 *result;
    float t = 0.5f * (y(unit_direction) + 1.0f);

    multiply_scalar(&first, (1.0f - t));
    multiply_scalar(&second, t);
    result = add_vec(&first, &second);

    delete_vector(unit_direction);

    return unit_direction;
}

int
main(void)
{
    int i, j;
    int ir, ig, ib;
    int nx = 200;
    int ny = 100;
    float u, v;
    FILE *output_file;
    char *filename = "ch3.ppm";
    vec3 horizontal = { 4.0f, 0, 0 };
    vec3 vertical = { 0, 2.0f, 0 };
    vec3 lower_left_corner = { -2.0f, -1.0f, -1.0f };
    vec3 origin = { 0, 0, 0 };
    vec3 scr_coord = { 0, 0, 0 };
    vec3 *col = create_empty_vector();
    ray r;

    output_file = fopen(filename, "w");

    if (!output_file) {
        perror("Could not open ch3.ppm. Aborting.\n");
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
