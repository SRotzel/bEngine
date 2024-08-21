//#define DEBUG // uncomment to enable debug message
#include <stdio.h>
#include "bEngine.h"

int main() {
    b_info info;
    info.width = 620;
    info.height = 920;
    info.name = "Test";

    context c;
    c.title = "Context 1";
    c.id    = 1;

    init_context(info, &c);
    tick(&c);

    return B_SUCCESS;
}

b_returntype init_context(b_info i, context* c) {
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

b_returntype render_context(context *c) {
    // memset(c->pixels, 0, sizeof(c->pixels));

    return B_SUCCESS;
}

b_returntype tick(context *c) {
    bool shouldClose = false;
    while(!shouldClose) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    shouldClose = true;
                    break;
            }
        }

        render_context(c);
    }

    return B_SUCCESS;
}
