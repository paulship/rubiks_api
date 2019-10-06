#include "rubiks.h"
#include "rubiks_move.h"

static void rubiks_move_rotate_four( RUBIKS_COLOUR_T* const a_ptr, RUBIKS_COLOUR_T* const b_ptr, RUBIKS_COLOUR_T* const c_ptr, RUBIKS_COLOUR_T* const d_ptr );


void rubiks_move_top_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->top[0][1]), &(cube_ptr->top[1][2]), &(cube_ptr->top[2][1]), &(cube_ptr->top[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->top[0][0]), &(cube_ptr->top[0][2]), &(cube_ptr->top[2][2]), &(cube_ptr->top[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[0][0]), &(cube_ptr->left[0][0]), &(cube_ptr->back[0][0]), &(cube_ptr->right[0][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[0][1]), &(cube_ptr->left[0][1]), &(cube_ptr->back[0][1]), &(cube_ptr->right[0][1]) );
    rubiks_move_rotate_four( &(cube_ptr->front[0][2]), &(cube_ptr->left[0][2]), &(cube_ptr->back[0][2]), &(cube_ptr->right[0][2]) );    
}

void rubiks_move_top_aw( rubiks_cube_t* const cube_ptr )
{
}

void rubiks_move_bottom_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->bottom[0][1]), &(cube_ptr->bottom[1][2]), &(cube_ptr->bottom[2][1]), &(cube_ptr->bottom[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->bottom[0][0]), &(cube_ptr->bottom[0][2]), &(cube_ptr->bottom[2][2]), &(cube_ptr->bottom[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[2][0]), &(cube_ptr->right[2][0]), &(cube_ptr->back[2][0]), &(cube_ptr->left[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[2][1]), &(cube_ptr->right[2][1]), &(cube_ptr->back[2][1]), &(cube_ptr->left[2][1]) );
    rubiks_move_rotate_four( &(cube_ptr->front[2][2]), &(cube_ptr->right[2][2]), &(cube_ptr->back[2][2]), &(cube_ptr->left[2][2]) );
}

void rubiks_move_bottom_aw( rubiks_cube_t* const cube_ptr )
{
}

void rubiks_move_left_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->left[0][1]), &(cube_ptr->left[1][2]), &(cube_ptr->left[2][1]), &(cube_ptr->left[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->left[0][0]), &(cube_ptr->left[0][2]), &(cube_ptr->left[2][2]), &(cube_ptr->left[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[0][0]), &(cube_ptr->bottom[0][0]), &(cube_ptr->back[2][2]), &(cube_ptr->top[0][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[1][0]), &(cube_ptr->bottom[1][0]), &(cube_ptr->back[1][2]), &(cube_ptr->top[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[2][0]), &(cube_ptr->bottom[2][0]), &(cube_ptr->back[0][2]), &(cube_ptr->top[2][0]) );
}

void rubiks_move_left_aw( rubiks_cube_t* const cube_ptr )
{
}

void rubiks_move_right_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->right[0][1]), &(cube_ptr->right[1][2]), &(cube_ptr->right[2][1]), &(cube_ptr->right[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->right[0][0]), &(cube_ptr->right[0][2]), &(cube_ptr->right[2][2]), &(cube_ptr->right[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[0][2]), &(cube_ptr->top[0][2]), &(cube_ptr->back[2][0]), &(cube_ptr->bottom[0][2]) );
    rubiks_move_rotate_four( &(cube_ptr->front[1][2]), &(cube_ptr->top[1][2]), &(cube_ptr->back[1][0]), &(cube_ptr->bottom[1][2]) );
    rubiks_move_rotate_four( &(cube_ptr->front[2][2]), &(cube_ptr->top[2][2]), &(cube_ptr->back[0][0]), &(cube_ptr->bottom[2][2]) );
}

void rubiks_move_right_aw( rubiks_cube_t* const cube_ptr )
{
}

void rubiks_move_front_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->front[0][1]), &(cube_ptr->front[1][2]), &(cube_ptr->front[2][1]), &(cube_ptr->front[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->front[0][0]), &(cube_ptr->front[0][2]), &(cube_ptr->front[2][2]), &(cube_ptr->front[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->top[2][0]), &(cube_ptr->right[0][0]), &(cube_ptr->bottom[0][2]), &(cube_ptr->left[2][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top[2][1]), &(cube_ptr->right[1][0]), &(cube_ptr->bottom[0][1]), &(cube_ptr->left[1][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top[2][2]), &(cube_ptr->right[2][0]), &(cube_ptr->bottom[0][0]), &(cube_ptr->left[0][2]) );
}

void rubiks_move_front_aw( rubiks_cube_t* const cube_ptr )
{
}

void rubiks_move_back_cw( rubiks_cube_t* const cube_ptr )
{
    rubiks_move_rotate_four( &(cube_ptr->back[0][1]), &(cube_ptr->back[1][2]), &(cube_ptr->back[2][1]), &(cube_ptr->back[1][0]) );
    rubiks_move_rotate_four( &(cube_ptr->back[0][0]), &(cube_ptr->back[0][2]), &(cube_ptr->back[2][2]), &(cube_ptr->back[2][0]) );
    rubiks_move_rotate_four( &(cube_ptr->top[0][2]), &(cube_ptr->left[0][0]), &(cube_ptr->bottom[2][0]), &(cube_ptr->right[2][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top[0][1]), &(cube_ptr->left[1][0]), &(cube_ptr->bottom[2][1]), &(cube_ptr->right[1][2]) );
    rubiks_move_rotate_four( &(cube_ptr->top[0][0]), &(cube_ptr->left[2][0]), &(cube_ptr->bottom[2][2]), &(cube_ptr->right[0][2]) );
}

void rubiks_move_back_aw( rubiks_cube_t* const cube_ptr )
{
}

static void rubiks_move_rotate_four( RUBIKS_COLOUR_T* const a_ptr, RUBIKS_COLOUR_T* const b_ptr, RUBIKS_COLOUR_T* const c_ptr, RUBIKS_COLOUR_T* const d_ptr )
{
    RUBIKS_COLOUR_T temp = *d_ptr;
    *d_ptr = *c_ptr;
    *c_ptr = *b_ptr;
    *b_ptr = *a_ptr;
    *a_ptr = temp;
}

