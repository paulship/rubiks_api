/*
    Definitions of functions used to manipulate the cube in different ways.
    Functions provided here can either rotate a face, or rotate the entire cube.
    The convention for any rotation is that clockwise or anticlockwise applies
    when looking directly at the face being manipulated.
*/

#include "rubiks.h"
#include "rubiks_move.h"

static void rubiks_move_rotate_four( RUBIKS_COLOUR_T* const a_ptr, RUBIKS_COLOUR_T* const b_ptr, RUBIKS_COLOUR_T* const c_ptr, RUBIKS_COLOUR_T* const d_ptr );


void rubiks_move_top_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[0][1]), &(cube_ptr->top.cubie[1][2]), &(cube_ptr->top.cubie[2][1]), &(cube_ptr->top.cubie[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[0][0]), &(cube_ptr->top.cubie[0][2]), &(cube_ptr->top.cubie[2][2]), &(cube_ptr->top.cubie[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[0][0]), &(cube_ptr->left.cubie[0][0]), &(cube_ptr->back.cubie[0][0]), &(cube_ptr->right.cubie[0][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[0][1]), &(cube_ptr->left.cubie[0][1]), &(cube_ptr->back.cubie[0][1]), &(cube_ptr->right.cubie[0][1]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[0][2]), &(cube_ptr->left.cubie[0][2]), &(cube_ptr->back.cubie[0][2]), &(cube_ptr->right.cubie[0][2]) );    
}

void rubiks_move_top_aw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_top_cw( cube_ptr );
    rubiks_move_top_cw( cube_ptr );
    rubiks_move_top_cw( cube_ptr );
}

void rubiks_move_bottom_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->bottom.cubie[0][1]), &(cube_ptr->bottom.cubie[1][2]), &(cube_ptr->bottom.cubie[2][1]), &(cube_ptr->bottom.cubie[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->bottom.cubie[0][0]), &(cube_ptr->bottom.cubie[0][2]), &(cube_ptr->bottom.cubie[2][2]), &(cube_ptr->bottom.cubie[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[2][0]), &(cube_ptr->right.cubie[2][0]), &(cube_ptr->back.cubie[2][0]), &(cube_ptr->left.cubie[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[2][1]), &(cube_ptr->right.cubie[2][1]), &(cube_ptr->back.cubie[2][1]), &(cube_ptr->left.cubie[2][1]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[2][2]), &(cube_ptr->right.cubie[2][2]), &(cube_ptr->back.cubie[2][2]), &(cube_ptr->left.cubie[2][2]) );
}

void rubiks_move_bottom_aw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_bottom_cw( cube_ptr );
    rubiks_move_bottom_cw( cube_ptr );
    rubiks_move_bottom_cw( cube_ptr );
}

void rubiks_move_left_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->left.cubie[0][1]), &(cube_ptr->left.cubie[1][2]), &(cube_ptr->left.cubie[2][1]), &(cube_ptr->left.cubie[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->left.cubie[0][0]), &(cube_ptr->left.cubie[0][2]), &(cube_ptr->left.cubie[2][2]), &(cube_ptr->left.cubie[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[0][0]), &(cube_ptr->bottom.cubie[0][0]), &(cube_ptr->back.cubie[2][2]), &(cube_ptr->top.cubie[0][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[1][0]), &(cube_ptr->bottom.cubie[1][0]), &(cube_ptr->back.cubie[1][2]), &(cube_ptr->top.cubie[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[2][0]), &(cube_ptr->bottom.cubie[2][0]), &(cube_ptr->back.cubie[0][2]), &(cube_ptr->top.cubie[2][0]) );
}

void rubiks_move_left_aw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_left_cw( cube_ptr );
    rubiks_move_left_cw( cube_ptr );
    rubiks_move_left_cw( cube_ptr );
}

void rubiks_move_right_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->right.cubie[0][1]), &(cube_ptr->right.cubie[1][2]), &(cube_ptr->right.cubie[2][1]), &(cube_ptr->right.cubie[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->right.cubie[0][0]), &(cube_ptr->right.cubie[0][2]), &(cube_ptr->right.cubie[2][2]), &(cube_ptr->right.cubie[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[0][2]), &(cube_ptr->top.cubie[0][2]), &(cube_ptr->back.cubie[2][0]), &(cube_ptr->bottom.cubie[0][2]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[1][2]), &(cube_ptr->top.cubie[1][2]), &(cube_ptr->back.cubie[1][0]), &(cube_ptr->bottom.cubie[1][2]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[2][2]), &(cube_ptr->top.cubie[2][2]), &(cube_ptr->back.cubie[0][0]), &(cube_ptr->bottom.cubie[2][2]) );
}

void rubiks_move_right_aw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_right_cw( cube_ptr );
    rubiks_move_right_cw( cube_ptr );
    rubiks_move_right_cw( cube_ptr );
}

void rubiks_move_front_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[0][1]), &(cube_ptr->front.cubie[1][2]), &(cube_ptr->front.cubie[2][1]), &(cube_ptr->front.cubie[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front.cubie[0][0]), &(cube_ptr->front.cubie[0][2]), &(cube_ptr->front.cubie[2][2]), &(cube_ptr->front.cubie[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[2][0]), &(cube_ptr->right.cubie[0][0]), &(cube_ptr->bottom.cubie[0][2]), &(cube_ptr->left.cubie[2][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[2][1]), &(cube_ptr->right.cubie[1][0]), &(cube_ptr->bottom.cubie[0][1]), &(cube_ptr->left.cubie[1][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[2][2]), &(cube_ptr->right.cubie[2][0]), &(cube_ptr->bottom.cubie[0][0]), &(cube_ptr->left.cubie[0][2]) );
}

void rubiks_move_front_aw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_front_cw( cube_ptr );
    rubiks_move_front_cw( cube_ptr );
    rubiks_move_front_cw( cube_ptr );
}

void rubiks_move_back_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->back.cubie[0][1]), &(cube_ptr->back.cubie[1][2]), &(cube_ptr->back.cubie[2][1]), &(cube_ptr->back.cubie[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->back.cubie[0][0]), &(cube_ptr->back.cubie[0][2]), &(cube_ptr->back.cubie[2][2]), &(cube_ptr->back.cubie[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[0][2]), &(cube_ptr->left.cubie[0][0]), &(cube_ptr->bottom.cubie[2][0]), &(cube_ptr->right.cubie[2][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[0][1]), &(cube_ptr->left.cubie[1][0]), &(cube_ptr->bottom.cubie[2][1]), &(cube_ptr->right.cubie[1][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top.cubie[0][0]), &(cube_ptr->left.cubie[2][0]), &(cube_ptr->bottom.cubie[2][2]), &(cube_ptr->right.cubie[0][2]) );
}

void rubiks_move_back_aw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_back_cw( cube_ptr );
    rubiks_move_back_cw( cube_ptr );
    rubiks_move_back_cw( cube_ptr );
}

/*
    This function will rotate four cubies around themselves. Each cube manipulation
    can be broken down a series of rotations of four cubie faces. This function performs
    a rotation of a group of four of these.
*/
static void rubiks_move_rotate_four( RUBIKS_COLOUR_T* const a_ptr, RUBIKS_COLOUR_T* const b_ptr, RUBIKS_COLOUR_T* const c_ptr, RUBIKS_COLOUR_T* const d_ptr )
{
    RUBIKS_COLOUR_T temp = *d_ptr;
    *d_ptr = *c_ptr;
    *c_ptr = *b_ptr;
    *b_ptr = *a_ptr;
    *a_ptr = temp;
}

