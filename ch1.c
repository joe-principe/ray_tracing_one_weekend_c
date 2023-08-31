#include <stdio.h>
#include <stdlib.h>

int
main( void )
{
    int i, j;
    int ir, ig, ib;
    int nx = 200;
    int ny = 100;
    float r, g, b;
    FILE *output_file;
    char *filename = "hello_world.ppm";

    output_file = fopen( filename, "w" );

    if ( !output_file ) {
        perror( "Could not open hello_world.ppm. Aborting.\n" );
        exit( EXIT_FAILURE );
    } /* if */

    fprintf( output_file, "P3\n%d %d\n255\n", nx, ny );

    for ( j = ny - 1; j >= 0; j-- ) {
        for ( i = 0; i < nx; i++ ) {
            r = ( float )( i ) / ( float )( nx );
            g = ( float )( j ) / ( float )( ny );
            b = 0.2;

            ir = ( int )( 255.99 * r );
            ig = ( int )( 255.99 * g );
            ib = ( int )( 255.99 * b );

            fprintf( output_file, "%d %d %d\n", ir, ig, ib );
        } /* for */
    } /* for */

    return 0;
}
/* EOF */
