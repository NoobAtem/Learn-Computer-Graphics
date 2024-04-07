#include "src/gcl_init.h"
#include "src/gcl_geometry.h"
#include "src/gcl_math.h"

void event(void){
    SDL_Event ev;

    while(SDL_PollEvent(&ev)){
        switch (ev.type){
            case SDL_QUIT:
                exit(0);
                break;
        }
    }
}

struct UpdateParameters{
    struct GCL_RGBA color;
    struct GCL_ShapeConfig config;
}; 

void update(void* arg, size_t size){
    event();

    if (size != sizeof(struct UpdateParameters)){
        printf("error: UPDATE Not Valid Size\n");
        return;
    }

    struct UpdateParameters* param = (struct UpdateParameters*)arg;

    /* Test Geometry Here */
    test

    //gcl_drawTriangle(&param->config, 100, 100, 200, 200, 50, 140);
    //gcl_drawRect(&param->config, 100, 100, 100, 100);
    //gcl_drawCircle_Polynomial(&param->config, 100, 100, 10);
    //gcl_drawCircle_Bresenham(&param->config, 50, 50, 100);
    //gcl_fillTriangle_Barycentric(&param->config, 100, 100, 200, 200, 50, 140);
    
}


int main(){
    GCLWindow* app = gcl_createWindow("Graphics");
    if (app == NULL){
        printf("error: Window Failed to Return\n");
        exit(1);
    }

    app->update = update;

    struct UpdateParameters param;
    param.color = GCL_BLACK;
    param.config.render = app->render;
    param.config.fill = GCL_YELLOW;

    gcl_run(app, &param, sizeof(struct UpdateParameters));
    return 0;
}
