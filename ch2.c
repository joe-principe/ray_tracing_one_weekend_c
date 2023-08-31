#include <stdio.h>
#include <stdlib.h>

#include "vec3.h"

int
main( void )
{
    int i, j;
    int ir, ig, ib;
    int nx = 200;
    int ny = 100;
    FILE *output_file;
    char *filename = "ch2.ppm";

    vec3 *col = empty_vector();

    output_file = fopen( filename, "w" );

    if ( !output_file ) {
        perror( "Could not open hello_world.ppm. Aborting.\n" );
        exit( EXIT_FAILURE );
    } /* if */

    fprintf( output_file, "P3\n%d %d\n255\n", nx, ny );

    for ( j = ny - 1; j >= 0; j-- ) {
        for ( i = 0; i < nx; i++ ) {
            col->e0 = ( float )( i ) / ( float )( nx );
            col->e1 = ( float )( j ) / ( float )( ny );
            col->e2 = 0.2;

            ir = ( int )( 255.99 * col->e0 );
            ig = ( int )( 255.99 * col->e1 );
            ib = ( int )( 255.99 * col->e2 );

            fprintf( output_file, "%d %d %d\n", ir, ig, ib );
        } /* for */
    } /* for */

    delete_vector( col );
    fclose( output_file );
    return 0;
}
/* EOF */
