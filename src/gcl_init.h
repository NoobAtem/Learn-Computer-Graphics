#ifdef __cplusplus
extern "C"{
#endif

#ifndef GCL_INIT_H
#define GCL_INIT_H

/*
#####################################################################
    Handles Initializers and Game Loop.
    It's used as reference for other files but not the main file.
    This is just a skeleton for games to overlap.

    - Create Window & Renderer
    - Init SDL Video
    - Game Loop
#####################################################################
*/

// Library
#include <SDL2/SDL.h>
#include <stdbool.h>

// Macros
// Window macros
#define WIN_HEIGHT 760
#define WIN_WIDTH 1240

#include "gcl_attrib.h"

typedef void (*GameUpdate)(void*, size_t); // Game Update to be passed to ggl Run

// Objects
typedef struct {

    // Private (Provided by a function to modify)
    // SDL Components
    SDL_Renderer* render;
    SDL_Window* window; 

    // Variables 
    bool is_running;

    // Game Update used in For Loop

    GameUpdate update;
    // Public (Not provided by a function)
    struct GCL_RGBA bg_color;
    Uint32 tick;

} GCLWindow;

// Game Fundemental Components
// Window Setup & SDL Init (Must be Called First)
GCLWindow* gcl_createWindow(const char* title);

// Run Game Loop (Pass a update)

/* The game loop (app, what struct parameter you'll pass to
user function update, the sizeof struct )*/

// Set user function
//void gcl_setUserUpdate();
void gcl_run(GCLWindow* app, void* arg, size_t size);


#endif

#ifdef __cplusplus
}
#endif