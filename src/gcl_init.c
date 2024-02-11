// Libraries
#include "gcl_init.h"
#include <stdio.h>
#include <stdlib.h>

// Implementation
// Init Window
GCLWindow* gcl_createWindow(const char* title){

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("error: SDL Init Video - %s\n", SDL_GetError());
        exit(1);
    }

    // Create Window & Renderer
    GCLWindow* app = (GCLWindow*)malloc(sizeof(GCLWindow));
    app->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_MAXIMIZED);
    if (!app->window){
        printf("error: GCLWindow Init Failed");
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app->render = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);

    if (!app->render){
        printf("error: RENDER Init Failed - %s\n", SDL_GetError());
        exit(1);
    }

    // Set Background Color
    app->bg_color = GCL_RED;

    // Set FPS
    app->tick = 60;

    // Initialize User Update Function
    app->update = NULL;

    // Toggle Is running
    app->is_running = false;


    return app;
}

// Prepare Window
void gcl_prepareScene(GCLWindow* app){
    SDL_SetRenderDrawColor(app->render, GCL_GET(app->bg_color));
    SDL_RenderClear(app->render);
}

// Present Window
void gcl_presentScene(GCLWindow* app){
    SDL_RenderPresent(app->render);
}


// Run Game
void gcl_run(GCLWindow* app, void* arg, size_t size){
    app->is_running = true; // Toggle to run

    while(app->is_running){
        
        // Prepare the next
        gcl_prepareScene(app);


        // User Functions
        if (app->update != NULL)
            app->update(arg, size);

        // Present
        // GCL Functions (Not User Implemented)
        gcl_presentScene(app);


        SDL_Delay(app->tick);

    }
}