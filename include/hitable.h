#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"

typedef struct hit_record_t hit_record;

struct hit_record_t
{
    float t;
    vec3 *p;
    vec3 *normal;
};

#endif
/* EOF */
