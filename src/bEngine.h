// Objects: bObjectName
// Functions/methods: b_method_name();
#ifndef B_ENGINE_H_
#define B_ENGINE_H_

#include <SDL2/SDL.h>
#include <iostream>
#include <stdbool.h>
#include "bObject.h"
#include "bUtil.h"

typedef struct {
    int width, height;
    char* name;
    bObject *character;
} bInfo;

bReturnType b_init();

class bContext {
public:
    bContext();
    bContext(bInfo);
    ~bContext();

    bReturnType Start();
    bReturnType Run();
    bReturnType Close();
    void Tick();

    // TODO: implement that this actually returns usable return types ig
    bReturnType AddObject(bObject);

private:
    char* title;
    int id;
    SDL_Window   *window;
    SDL_Renderer *renderer;
    SDL_Texture  *texture;

    bPipeline    pipe;
    bObject     *player;
};

#endif