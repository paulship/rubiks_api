#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"
#include "rubiks_move.h"

int main( void )
{
    printf("Starting Rubik's simulator.\n");

    /* Allocate memory for the cube */
    rubiks_cube_t* my_cube = malloc( sizeof(rubiks_cube_t) );

    /* Initialise and display the cube */
    rubiks_initialise( my_cube );
    rubiks_show( my_cube );
    rubiks_move_front_cw( my_cube );
    rubiks_move_right_cw( my_cube );
    rubiks_show( my_cube );

    if( rubiks_is_solved( my_cube ) )
    {
        printf("Cube is currently solved.\n");
    }
    else
    {
        printf("Cube is currently not solved.\n");
    }


    /* Free memory */
    free( my_cube );

    printf("All done - exiting now.\n");
    return 0;
}
