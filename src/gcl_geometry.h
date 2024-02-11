#ifdef __cplusplus
extern "C"{
#endif

#ifndef GCL_GEOMETRY_H
#define GCL_GEOMETRY_H

/*
#####################################################################
    All types of Drawable Geometry ( Must Initialize init.h first )

    - Draw Line
    - Draw & Fill Triangle
    - Draw & Fill Rectangle
    - Draw & Fill Circle
    - Check Pixel is inside Triangle
    - Check Pixel is inside Rectangle
    - Check Pixel is inside Circle
#####################################################################
*/


// Libraries
#include <SDL2/SDL.h>
#include "gcl_attrib.h"
#include <stdbool.h>

// Types
// Shape parameters (Must be initialize before running any draw function)
struct GCL_ShapeConfig{
    SDL_Renderer* render;

    struct GCL_RGBA fill;
};


// Functions
// Draw Line (x0, y0) (x1, y1)
void gcl_drawLine_DDA(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1);
void gcl_drawLine_Bresenham(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1);

// Draw Triangles
void gcl_drawTriangle(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1, int x2, int y2);

// Draw Rectangles
void gcl_drawRect(struct GCL_ShapeConfig* config, int x0, int y0, int width, int height);

// Draw Circle
// Draw Points of octants
void gcl_drawPoint_Circle(struct GCL_ShapeConfig* config, int xc, int yc, int x, int y); // Is used to draw circumference with points

void gcl_drawCircle_Polynomial(struct GCL_ShapeConfig* config, int xc, int yc, int r);
void gcl_drawCircle_Bresenham(struct GCL_ShapeConfig* config, int xc, int yc, int r);

// Fill Algorithm
// Traingle
void gcl_fillTriangle_Barycentric(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1, int x2, int y2);
// Rectangle 
void gcl_fillRect(struct GCL_ShapeConfig* config, int x, int y, int width, int height);
// Distance Test
void gcl_fillCircle_Distance(struct GCL_ShapeConfig* config, int xc, int yc, int r, int width, int height);

// Bounding 
void gcl_fillCircle_BoundingBox(struct GCL_ShapeConfig* config, int xc, int yc, int r);
void gcl_fillCircle_BoundingCircle(struct GCL_ShapeConfig* config, int xc, int yc, int r);

// Collision Test
bool gcl_triangleInsideTest(int x0, int y0, int y1, int x2, int y2, int point_x, int point_y);
bool gcl_rectInsideTest(int x, int y, int pixel_x, int pixel_y, int width, int height);
bool gcl_circleInsideTest(int xc, int yc, int pixel_x, int pixel_y, int r);

// Curve Approximation


#endif

#ifdef __cplusplus
}
#endif
