// NOTE: to script objects, assign id to objects. Create folder with its name as the id,
// create behaviour scripts in said folder, and let the engine process them  

#define DEBUG // uncomment to enable debug message
#include <stdio.h>
#include "bEngine.h"

/* --- TO BE DEFINED BY USER --- */
int main() {
    b_info info;
    info.width = 384;
    info.height = 216;
    info.name = "Test";

    b_context c;
    c.title = "Context 1";
    c.id    = 1;

    InitContext(info, &c);
    Tick(&c);
    Close(&c);

    return B_SUCCESS;
}

// Maybe create a struct if more info is given to the player
void PlayerUpdate(const u8 keystate, b_context *cont) {
    // Logic for player goes here, e.g.
    if(cont->id == 1) {
        
    }
}
/* --- TO BE DEFINED BY USER --- */

b_returntype InitContext(b_info i, b_context* c) {
    ASSERT(
        !SDL_Init(SDL_INIT_VIDEO),
        "SDL failed to initialize: %s\n",
        SDL_GetError());
    LOG("successfully initialized SDL!\n", "");

    // create window
    c->window = SDL_CreateWindow(
        i.name, 
        SDL_WINDOWPOS_CENTERED_DISPLAY(0), 
        SDL_WINDOWPOS_CENTERED_DISPLAY(0), 
        i.width, 
        i.height, 
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    LOG("successfully created window\n", "")
    ASSERT(c->window, "ERROR: Failed to create window: %s\n", SDL_GetError());

    c->renderer = SDL_CreateRenderer(c->window, -1, SDL_RENDERER_PRESENTVSYNC);
    ASSERT(c->renderer, "ERROR: Failed to create renderer %s\n", SDL_GetError());
    LOG("successfully created renderer\n", "");

    c->texture = SDL_CreateTexture(
        c->renderer,
        SDL_PIXELFORMAT_ABGR8888,
        SDL_TEXTUREACCESS_STREAMING,
        i.width, i.height
    );
    ASSERT(c->texture, "ERROR: Failed to create texture: %s\n", SDL_GetError());

    c->player.position   = (v2) { 2, 2 };
    c->player.direction  = normalize(((v2) { -1.0f, 0.1f }));
    c->player.plane      = (v2) { 0.0f, 0.66f };

    return B_SUCCESS;
}

b_returntype RenderPipeline(Pipeline p) {
    // memset(c->pixels, 0, sizeof(c->pixels));

    return B_SUCCESS;
}


// This function takes a context, and will loop until the context is closed
// It will process events, and update every Object in the Pipeline and the player
// 1. Process inputs, 2. Update Objects 3. Render
b_returntype Tick(b_context *c) {
    bool shouldClose = false;
    while(!shouldClose) {
        B_input_event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    shouldClose = true;
                    break;
            }
        }

        // Update the context!
        const u8 *keystate = SDL_GetKeyboardState(NULL);
        PlayerUpdate(keystate, c); // To be defined by user!!!! IMPORTANT
        for(int i = 0; i < sizeof(c->pipe); i++) { // Loop through all objects and update

        }

        RenderPipeline(c->pipe);
    }

    return B_SUCCESS;
}

b_returntype Close(b_context *c) {
    LOG("Shutting down application %s...\n", c->title)
    SDL_DestroyTexture(c->texture);
    LOG("Destroyed Texture!\n", "")
    SDL_DestroyRenderer(c->renderer);
    LOG("Destroyed Renderer!\n", "")
    SDL_DestroyWindow(c->window);
    LOG("Destroyed Window!\n", "")

    return B_SUCCESS;
}