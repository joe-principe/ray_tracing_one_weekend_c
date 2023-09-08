#include <stdbool.h>
#include <stdlib.h>

#include "../include/hitablelist.h"

/* Creates a new sphere list */
sphere_list *
create_sphere_list(sphere **l, int n)
{
    sphere_list *sl = malloc(sizeof(sphere_list));

    sl->list = l;
    sl->list_size = n;

    return sl;
}

/* Creates an empty sphere list */
sphere_list *
create_empty_sphere_list(void)
{
    sphere_list *sl = malloc(sizeof(sphere_list));

    sl->list = NULL;
    sl->list_size = 0;

    return sl;
}

/* Deletes a sphere list */
void
delete_sphere_list(sphere_list *sl)
{
    int i;

    for (i = 0; i < sl->list_size; i++) {
        delete_sphere(sl->list[i]);
    } /* for */

    free(sl);
}

sphere **
get_sphere_list(const sphere_list *sl)
{
    return sl->list;
}

void
set_sphere_list(sphere_list *sl, sphere **l)
{
    sl->list = l;
}

int
get_sphere_list_size(const sphere_list *sl)
{
    return sl->list_size;
}

sphere *
get_sphere_at_index(sphere_list *sl, int index)
{
    return sl->list[index];
}

void
append_sphere(sphere_list *sl)
{

}

void
prepend_sphere(sphere_list *sl)
{

}

void
insert_sphere(sphere_list *sl, int index)
{

}

sphere *
remove_sphere(sphere_list *sl, int index)
{
    sphere *sp = sl->list[index];

    return sp;
}
