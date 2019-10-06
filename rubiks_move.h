#ifndef RUBIKS_MOVE_H
#define RUBIKS_MOVE_H

#include "rubiks.h"

extern void rubiks_move_top_cw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_top_aw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_bottom_cw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_bottom_aw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_left_cw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_left_aw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_right_cw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_right_aw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_front_cw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_front_aw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_back_cw( rubiks_cube_t* const cube_ptr );
extern void rubiks_move_back_aw( rubiks_cube_t* const cube_ptr );

#endif /* RUBIKS_MOVE_H */
