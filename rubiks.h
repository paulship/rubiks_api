#ifndef RUBIKS_H
#define RUBIKS_H

#include <stdbool.h>
#include <stdint.h>


/*
    Start off with some simple defintions for what our cube looks like. We have the
    size of the cube, defintions for the available colours, definitions for what a
    face looks like, and then the six faces go together to make a cube.
*/
#define CUBE_SIZE 3

/*
    Enum to represent each possible colour face
*/
typedef enum
{
	RUBIKS_RED,
	RUBIKS_BLUE,
	RUBIKS_YELLOW,
	RUBIKS_GREEN,
	RUBIKS_WHITE,
	RUBIKS_ORANGE,
    RUBIKS_BLACK    /* Only used for output control. */
} RUBIKS_COLOUR_T;

/*
    Enum to represent the possible moves that can be made
*/
typedef enum
{
    RUBIKS_MOVE_TOP_CW,
    RUBIKS_MOVE_TOP_AW,
    RUBIKS_MOVE_FRONT_CW,
    RUBIKS_MOVE_FRONT_AW,
    RUBIKS_MOVE_LEFT_CW,
    RUBIKS_MOVE_LEFT_AW,
    RUBIKS_MOVE_RIGHT_CW,
    RUBIKS_MOVE_RIGHT_AW,
    RUBIKS_MOVE_BACK_CW,
    RUBIKS_MOVE_BACK_AW,
    RUBIKS_MOVE_BOTTOM_CW,
    RUBIKS_MOVE_BOTTOM_AW
} RUBIKS_MOVE_T;

typedef struct
{
	RUBIKS_COLOUR_T cubie[CUBE_SIZE][CUBE_SIZE]; /* Numbered [row][column] */
} rubiks_face_t;

typedef struct
{
    rubiks_face_t top;
    rubiks_face_t front;
    rubiks_face_t left;
    rubiks_face_t right;
    rubiks_face_t back;
    rubiks_face_t bottom;
} rubiks_cube_t;

/*
    Functions for doing various things with the cube
*/
extern void rubiks_initialise( rubiks_cube_t* const cube_ptr );
extern bool rubiks_is_solved( const rubiks_cube_t* const cube_ptr );
extern void rubiks_show( const rubiks_cube_t* const cube_ptr );

#endif /* RUBIKS_H */
