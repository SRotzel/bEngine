// Objects: bObjectName
// Functions/methods: b_method_name();
#ifndef B_ENGINE_H_
#define B_ENGINE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <iostream>
#include <stdbool.h>
#include "bObject.h"
#include "bUtil.h"

typedef struct {
    int width, height;
    char* name;
    bObject *character;
    bPipeline pipeline;
} bInfo;

bReturnType b_init();
const u8* b_get_input();

class bContext {
public:
    bContext();
    bContext(bInfo);
    ~bContext();

    bReturnType Start();
    bReturnType Run();
    bReturnType Close();

    // TODO: implement that this actually returns usable return types ig
    bReturnType AddObject(bObject);

private:
    void Tick();
    void Render();

    char* title;
    int id;
    SDL_Window   *window;
    SDL_Renderer *renderer;
    SDL_Texture  *texture;

    bPipeline    pipe;
    bObject     *player;
};

#endif