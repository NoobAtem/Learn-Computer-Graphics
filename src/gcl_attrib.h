#ifdef __cplusplus
extern "C"{
#endif

#ifndef GCL_ATTRIB_H
#define GCL_ATTRIB_H

/*
#####################################################################
    Handles Any Usefule Attributes Like Color, Physics Stuff. Mostly
    Macros and Structs

    - Colors
#####################################################################
*/


// Library
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdint.h>

// GCL_RGBA macros
#define GCL_COLOR(x, y, w, z) (struct GCL_RGBA){.r = x, .g = y, .b = w, .a = z}
#define GCL_RED GCL_COLOR(255, 0, 0, 255)
#define GCL_BLACK GCL_COLOR(0, 0, 0, 255)
#define GCL_GREEN GCL_COLOR(0, 255, 0, 255)
#define GCL_BLUE GCL_COLOR(0, 0, 255, 255)
#define GCL_YELLOW GCL_COLOR(255, 255, 0, 255)

// This is just for convinience while maintaining Memory
#define GCL_GET(x) x.r, x.g, x.b, x.a // Get Color from GCL_COLOR

// Types
struct GCL_RGBA{
    Uint8 r; // Red
    Uint8 g; // Green
    Uint8 b; // Blue
    Uint8 a; // Alpha
};


// Matrix & Vectors
typedef struct{
    float* data;
    size_t size;
} Vec;

typedef struct{
    Vec* vector;
    size_t size[2];
} Mat;


#endif

#ifdef __cplusplus
}
#endif
