#include <stdlib.h>
#include <stdint.h>
#include "rubiks_display.h"
#include "rubiks_move.h"
#include "rubiks.h"

static void rubiks_set_face( rubiks_face_t* const face_ptr, const RUBIKS_COLOUR_T colour );
static bool rubiks_side_is_one_colour( const rubiks_face_t* const face_ptr );

void rubiks_initialise( rubiks_cube_t* const cube_ptr )
{
    /* This is the standard cube layout according to Wikipedia. */
    rubiks_set_face( &cube_ptr->top, RUBIKS_WHITE );
    rubiks_set_face( &cube_ptr->front, RUBIKS_RED );
    rubiks_set_face( &cube_ptr->left, RUBIKS_GREEN );
    rubiks_set_face( &cube_ptr->right, RUBIKS_BLUE );
    rubiks_set_face( &cube_ptr->back, RUBIKS_ORANGE );
    rubiks_set_face( &cube_ptr->bottom, RUBIKS_YELLOW );
}

/*
    Determine if the cube is solved.
*/
bool rubiks_is_solved( const rubiks_cube_t* const cube_ptr )
{
    /*
        Consider the cube solved if all cubies on a side are the same
        colour, and all sides are a different colour.
    */
    return
    (
        rubiks_side_is_one_colour( &cube_ptr->top )
     && rubiks_side_is_one_colour( &cube_ptr->front )
     && rubiks_side_is_one_colour( &cube_ptr->left )
     && rubiks_side_is_one_colour( &cube_ptr->right )
     && rubiks_side_is_one_colour( &cube_ptr->back )
     && rubiks_side_is_one_colour( &cube_ptr->bottom )
     && ( cube_ptr->top.cubie[0][0] != cube_ptr->front.cubie[0][0] )
     && ( cube_ptr->top.cubie[0][0] != cube_ptr->left.cubie[0][0] )
     && ( cube_ptr->top.cubie[0][0] != cube_ptr->right.cubie[0][0] )
     && ( cube_ptr->top.cubie[0][0] != cube_ptr->back.cubie[0][0] )
     && ( cube_ptr->top.cubie[0][0] != cube_ptr->bottom.cubie[0][0] )
     && ( cube_ptr->front.cubie[0][0] != cube_ptr->left.cubie[0][0] )
     && ( cube_ptr->front.cubie[0][0] != cube_ptr->right.cubie[0][0] )
     && ( cube_ptr->front.cubie[0][0] != cube_ptr->back.cubie[0][0] )
     && ( cube_ptr->front.cubie[0][0] != cube_ptr->bottom.cubie[0][0] )
     && ( cube_ptr->left.cubie[0][0] != cube_ptr->right.cubie[0][0] )
     && ( cube_ptr->left.cubie[0][0] != cube_ptr->back.cubie[0][0] )
     && ( cube_ptr->left.cubie[0][0] != cube_ptr->bottom.cubie[0][0] )
     && ( cube_ptr->right.cubie[0][0] != cube_ptr->back.cubie[0][0] )
     && ( cube_ptr->right.cubie[0][0] != cube_ptr->bottom.cubie[0][0] )
     && ( cube_ptr->back.cubie[0][0] != cube_ptr->bottom.cubie[0][0] )
    );
}

void rubiks_show( const rubiks_cube_t* const cube_ptr )
{
    /*
    	Functionality here is completely farmed out to a module designed specifically
    	for display purposes.
    */
    rubiks_display( cube_ptr );
}

void rubiks_move( rubiks_cube_t* const cube_ptr, const RUBIKS_MOVE_T move )
{
    static void (*const funcs[])(rubiks_cube_t* const cube_ptr) =
    {
        [RUBIKS_MOVE_TOP_CW] = rubiks_move_top_cw,
        [RUBIKS_MOVE_TOP_AW] = rubiks_move_top_aw,
        [RUBIKS_MOVE_BOTTOM_CW] = rubiks_move_bottom_cw,
        [RUBIKS_MOVE_BOTTOM_AW] = rubiks_move_bottom_aw,
        [RUBIKS_MOVE_LEFT_CW] = rubiks_move_left_cw,
        [RUBIKS_MOVE_LEFT_AW] = rubiks_move_left_aw,
        [RUBIKS_MOVE_RIGHT_CW] = rubiks_move_right_cw,
        [RUBIKS_MOVE_RIGHT_AW] = rubiks_move_right_aw,
        [RUBIKS_MOVE_FRONT_CW] = rubiks_move_front_cw,
        [RUBIKS_MOVE_FRONT_AW] = rubiks_move_front_aw,
        [RUBIKS_MOVE_BACK_CW] = rubiks_move_back_cw,
        [RUBIKS_MOVE_BACK_AW] = rubiks_move_back_aw,
    };

    static const unsigned int n_funcs = (sizeof(funcs)) / (sizeof(funcs[0]));

    if( move < n_funcs )
    {
        if( funcs[move] != NULL )
        {
            funcs[move](cube_ptr);
        }
    }
}

/*
    Set an entire cube face to the same colour.
*/
static void rubiks_set_face( rubiks_face_t* const face_ptr, const RUBIKS_COLOUR_T colour )
{
    for( uint8_t m=0; m<CUBE_SIZE; m++ )
    {
        for( uint8_t n=0; n<CUBE_SIZE; n++ )
        {
            face_ptr->cubie[m][n] = colour;
        }
    }
}

/*
	Determine if all cubies on a face are of the same colour.
*/
static bool rubiks_side_is_one_colour( const rubiks_face_t* const face_ptr )
{
    /* Identify first cubie on that face */
    const RUBIKS_COLOUR_T expected_colour = face_ptr->cubie[0][0];
    
    /* All other cubies must eb the same colour */
    for( uint8_t a=0; a<CUBE_SIZE; a++ )
    {
        for( uint8_t b=0; b<CUBE_SIZE; b++ )
        {
            if( face_ptr->cubie[a][b] != expected_colour )
            {
                /* If there is a mis-match, just abort the check here. */
                return false;
            }
        }
    }

    /* If we get through all cubies on the face, then we're good. */
    return true;
}

