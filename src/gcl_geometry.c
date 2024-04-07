#include "gcl_geometry.h"
#include <stdio.h>

// Mathematical Operations
#include "gcl_math.h"

/* Line Algorithm */

void gcl_drawLine_DDA(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));

    // DDA (Digital Differential Algorithm)

    // Compute for Width, Height and Start to End using the fact y = mx +   
    // Compute tangent
    float dx = x1-x0;
    float dy = y1-y0;
    int steps;

    // Choose how many steps should be taken
    if (ABSF(dx) > ABSF(dy)) steps = ABSF(dx);
    else steps = ABSF(dy);

    // Fix each increment to match the steps
    float Xincrement = dx/(float)steps;
    float Yincrement = dy/(float)steps;

    float y = y0;
    float x = x0;

    for (int v = 0; v < steps; v++){
        x += Xincrement;
        y += Yincrement;
        SDL_RenderDrawPoint(config->render, ROUND(x), ROUND(y));
    }

}

void gcl_drawLine_Bresenham(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1){
    // Set Draw Color
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));

    int dy = -abs(y1 - y0);
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;

    while (true){
        SDL_RenderDrawPoint(config->render, x0, y0);
        if (x0 == x1 && y0 == y1) break;
        
        if (2*error >= dy){
            if (x0 == x1) break;
            error += dy;
            x0 += sx;
        }
        else if (2*error <= dx){
            if (y0 == y1) break;
            error += dx;
            y0 += sy;
        }
    }
}

/* Triangle Implementation */
void gcl_drawTriangle(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1, int x2, int y2){
    // Valid input check
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));

    // Draw 3 vertices;
    gcl_drawLine_Bresenham(config, x0, y0, x1, y1);
    gcl_drawLine_Bresenham(config, x1, y1, x2, y2);
    gcl_drawLine_Bresenham(config, x2, y2, x0, y0);
}

/* Rectangular Implementation */
void gcl_drawRect(struct GCL_ShapeConfig* config, int x0, int y0, int width, int height){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));

    // Draw 4 vertices
    // Horizontal Lines
    gcl_drawLine_Bresenham(config, x0, y0, x0+width, y0);
    gcl_drawLine_Bresenham(config, x0, y0+height, x0+width, y0+height);
    // Vertical Lines
    gcl_drawLine_Bresenham(config, x0+width, y0, x0+width, y0+height);
    gcl_drawLine_Bresenham(config, x0, y0, x0, y0+height);
}

/* Circle Implementation */

void gcl_drawPoint_Circle(struct GCL_ShapeConfig* config, int xc, int yc, int x, int y){
    // 45 degree Section
    SDL_RenderDrawPoint(config->render, xc+x, yc+y);
    SDL_RenderDrawPoint(config->render, xc-x, yc+y);

    // Reflection of 45 degree section
    SDL_RenderDrawPoint(config->render, xc+x, yc-y);
    SDL_RenderDrawPoint(config->render, xc-x, yc-y);

    // 45 degree Section
    SDL_RenderDrawPoint(config->render, xc+y, yc+x);
    SDL_RenderDrawPoint(config->render, xc-y, yc+x);

    // Reflection of 45 degree Section
    SDL_RenderDrawPoint(config->render, xc+y, yc-x);
    SDL_RenderDrawPoint(config->render, xc-y, yc-x);
}

void gcl_drawCircle_Polynomial(struct GCL_ShapeConfig* config, int xc, int yc, int r){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    // r/sqrt(2) = r*sin(45) = r*cos(45)
    double x = 0, y = r, x2 = r/gcl_sqrt(2, 100);
    while(x<=x2){
        y = gcl_sqrt(r*r - x*x, 100);
        gcl_drawPoint_Circle(config, xc, yc, FLOOR(x), FLOOR(y));
        x++;
    }
}

void gcl_drawCircle_Bresenham(struct GCL_ShapeConfig* config, int xc, int yc, int r){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    gcl_drawPoint_Circle(config, xc, yc, x, y); 
    while (y >= x) 
    { 
        if (d <= 0)
            d+=4*x+6;
        else{
            d+=4*x-4*y+10;
            y--;
        }
        x++;
        gcl_drawPoint_Circle(config, xc, yc, x, y);
    } 
}

// Collision Test

bool gcl_circleInsideTest(int xc, int yc, int pixel_x, int pixel_y, int r){
    int dx = xc - pixel_x;
    int dy = yc - pixel_y;
    int distance = dx*dx+dy*dy;

    return distance <= r*r; 
}

bool gcl_rectInsideTest(int x, int y, int pixel_x, int pixel_y, int width, int height){
    int dx = pixel_x - x;
    int dy = pixel_y - y;
    bool lower_bound = dx > 0 && dy > 0;
    bool upper_bound = dx < width && dy < height;
    return lower_bound && upper_bound;
}

bool gcl_triangleInsideTest(int x0, int y0, int y1, int x2, int y2, int point_x, int point_y){
    // using vectors starting at one of the points into ratios of weights
    float w1 = (x0*(y2-y0) + (point_y - y0)*(x2 - x0) - point_x*(y2-y0));
    float denominator = ((y1-y0)*(x2-x0)-(x2-x0)*(y2-y0));
    if (denominator == 0) return false;
    w1 /= denominator;

    float w2 = (point_y - y0 - w1*(y1-y0));
    denominator = y2-y0;
    if (denominator == 0) return false;
    w2 /= denominator;
    return w1 >= 0 && w2 >= 0 && w1 + w2 <= 1;
}



// Fill Polygon
void gcl_fillRect(struct GCL_ShapeConfig* config, int x, int y, int width, int height){
    int steps_x = width + x, steps_y = height + y;

    for (; y < steps_y; y++){
        for (; x < steps_x; x++){
            SDL_RenderDrawPoint(config->render, x, y);
        }
    }
}


void gcl_bottomFillTriangle(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1, int x2, int y2){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    double invert_slope1 = (x1 - x0)/(y1-y0);
    double invert_slope2 = (x2 - x0)/(y2-y0);
    
    double sec_x0 = x0;
    double fir_x0 = x0;

    for (int scanLine_y = y0; scanLine_y <= y1; scanLine_y++){
        gcl_drawLine_Bresenham(config, (int)fir_x0, scanLine_y, (int)sec_x0, scanLine_y);
        fir_x0 += invert_slope1;
        sec_x0 += invert_slope2;
    }
}

void gcl_topFillTriangle(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1, int x2, int y2){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    double invert_slope1 = (x2 - x0)/(y2-y0);
    double invert_slope2 = (x2 - x1)/(y2-y1);
    
    double sec_x0 = x2;
    double fir_x0 = x2;

    for (int scanLine_y = y2; scanLine_y  > y0; scanLine_y--){
        gcl_drawLine_Bresenham(config, (int)fir_x0, scanLine_y, (int)sec_x0, scanLine_y);
        fir_x0 -= invert_slope1;
        sec_x0 -= invert_slope2;
    }
}

void gcl_fillTriangle_Barycentric(struct GCL_ShapeConfig* config, int x0, int y0, int x1, int y1, int x2, int y2){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    // Bounding Box
    int maxX = MAX(x0, MAX(x1, x2));
    int minX = MIN(x0, MIN(x1, x2));
    int maxY = MAX(y0, MIN(y1, y2));
    int minY = MIN(y0, MIN(y1, y2));

    int vsc1_x = x1-x0, vsc1_y = y1-y0;
    int vsc2_x = x2-x0, vsc2_y = y2-y0;

    for (int i = minX; i <= maxX; i++){
        for (int j = minY; j <= maxY; j++){
            int q_x = i - vsc1_x, q_y = j - vsc1_y;
            double denominator = (double)(gcl_dot_product2D(vsc1_x, vsc1_y, vsc2_x, vsc2_y));
            if (denominator == 0)
                return;
            double s = (double)(gcl_dot_product2D(q_x, q_y, vsc2_x, vsc2_y)/denominator);
            double t = (double)(gcl_dot_product2D(vsc1_x, vsc1_y, q_x, q_y)/denominator);

            if ((s >= 0) && (t >= 0) && (s + t <= 1)){
                SDL_RenderDrawPoint(config->render, i, j);
            }
        }
    }
}

// Super slow and dumb because we used width height of the 
//entire screen to scan if it is in fact inside the circle
void gcl_fillCircle_Distance(struct GCL_ShapeConfig* config, int xc, int yc, int r, int width, int height){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            if (gcl_circleInsideTest(xc, yc, x, y, r)){
                SDL_RenderDrawPoint(config->render, x, y);
            }
        }
    }
}


// Much Better
void gcl_fillCircle_BoundingBox(struct GCL_ShapeConfig* config, int xc, int yc, int r){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    int top = yc - r,
        bottom = yc + r,
        left = xc - r,
        right = xc + r;
    for (int y = top; y < bottom; y++){
        for (int x = left; x < right; x++){
            if (gcl_circleInsideTest(xc, yc, x, y, r)){
                SDL_RenderDrawPoint(config->render, x, y);
            }
        }
    }
}

// Even Better
void gcl_fillCircle_BoundingCircle(struct GCL_ShapeConfig* config, int xc, int yc, int r){
    SDL_SetRenderDrawColor(config->render, GCL_GET(config->fill));
    int top = yc - r,
        bottom = yc + r;
    for (int y = top; y < bottom; y++){
        int dy = y - yc;
        double pyt = (double)(r*r - dy*dy); // Pythagorean theorem x*x = r*r - y*y
        float dx = gcl_sqrt(pyt, 100);
        int left = CEIL((xc - dx)),
            right = FLOOR((xc + dx));

        for (int x = left; x < right; x++){
            SDL_RenderDrawPoint(config->render, x, y);
        }
    }
}

/* Curve Approximation */
// Draw Bezier Curve
