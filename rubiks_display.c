#include <stdio.h>
#include <stdint.h>
#include "rubiks.h"

#include "rubiks_display.h"

static void rubiks_display_row( const rubiks_face_t* const face_a_ptr, const rubiks_face_t* const face_b_ptr, const rubiks_face_t* const face_c_ptr, const rubiks_face_t* const face_d_ptr);
static void rubiks_display_cubie( const RUBIKS_COLOUR_T colour );
static void rubiks_display_newline( void );


void rubiks_display( const rubiks_cube_t* const cube_ptr )
{
    /*
        We intend to display the cube in an unwrapped fashion, starting with the top,
        wrapping around the sides, and then finishing with the bottom.
    */
    rubiks_display_row( NULL, &cube_ptr->top, NULL, NULL );
    rubiks_display_row( &cube_ptr->left, &cube_ptr->front, &cube_ptr->right, &cube_ptr->back );
    rubiks_display_row( NULL, &cube_ptr->bottom, NULL, NULL );
}


static void rubiks_display_row( const rubiks_face_t* const face_a_ptr, const rubiks_face_t* const face_b_ptr, const rubiks_face_t* const face_c_ptr, const rubiks_face_t* const face_d_ptr)
{
    /* Alias the above pointers with an array */
    const rubiks_face_t* const face_ptr[4] =
    {
        [0] = face_a_ptr,
        [1] = face_b_ptr,
        [2] = face_c_ptr,
        [3] = face_d_ptr
    };

    for( uint8_t row=0; row<CUBE_SIZE; row++ )
    {
        for( uint8_t face=0; face<4; face++ )
        {
            for( uint8_t column=0; column<CUBE_SIZE; column++ )
            {
                if( face_ptr[face] != NULL )
                {
                    rubiks_display_cubie( face_ptr[face]->cubie[row][column] );
                }                
                else
                {
                    rubiks_display_cubie( RUBIKS_BLACK );
                }                
            }
            printf(" ");
        }
        rubiks_display_newline();
    }
}

static void rubiks_display_cubie( const RUBIKS_COLOUR_T colour )
{
    switch( colour )
    {
        case RUBIKS_RED:    { printf("\033" "[1;31m"  "#"); break; }
	    case RUBIKS_BLUE:   { printf("\033" "[1;34m"  "#"); break; }
	    case RUBIKS_YELLOW: { printf("\033" "[01;33m" "#"); break; }
	    case RUBIKS_GREEN:  { printf("\033" "[1;32m"  "#"); break; }
	    case RUBIKS_WHITE:  { printf("\033" "[0m"     "#"); break; }
	    case RUBIKS_ORANGE: { printf("\033" "[0;35m"  "#"); break; }
	    case RUBIKS_BLACK:  { printf("\033" "[0m"     " "); break; }
	    default:            { printf("\033" "[0m"     "-"); break; }
    }
}

static void rubiks_display_newline( void )
{
    printf("\033" "[0m" "\n");
}
