#include "bEngine.h"

bReturnType b_init() {
    ASSERT(
        !SDL_Init(SDL_INIT_VIDEO),
        "SDL failed to initialize: %s\n",
        SDL_GetError());
    LOG("successfully initialized SDL!\n", "");

    return B_SUCCESS;
}

const u8* b_get_input() { 
    SDL_PumpEvents();
    return SDL_GetKeyboardState(NULL); 
}

bContext::bContext() {  }
bContext::bContext(bInfo info) {
    this->window = SDL_CreateWindow(
        info.name,
        SDL_WINDOWPOS_CENTERED_DISPLAY(0),
        SDL_WINDOWPOS_CENTERED_DISPLAY(0),
        info.width, info.height,
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    ASSERT(this->window, "ERROR: Failed to create window! (%s)\n", SDL_GetError())
    LOG("succesfully created window! \n", "")

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_PRESENTVSYNC);
    ASSERT(this->renderer, "ERROR: Failed to create renderer! (%s)\n", SDL_GetError())
    LOG("Succesfully created renderer! \n", "")

    this->texture = SDL_CreateTexture(
        this->renderer,
        SDL_PIXELFORMAT_ABGR8888,
        SDL_TEXTUREACCESS_STREAMING,
        info.width, info.height
    );
    ASSERT(this->texture, "ERROR: Failed to create texture! (%s)\n", SDL_GetError())
    LOG("Successfully created texture! \n", "")
    
    this->player = info.character;
    for(bObject* o : info.pipeline) {
        this->pipe.push_back(o);
    }
}

bReturnType bContext::Start() {
    this->player->Awake();
    if(this->pipeEmpty)
        return B_SUCCESS;
    for(bObject* o : this->pipe)
        o->Awake();

    return B_SUCCESS;
}

bReturnType bContext::Run() {
    bool shouldRun = true;
    bInputEvent e;  
    while (shouldRun) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT)
                shouldRun = false;
        }
        this->Tick();
        this->Render();
    }
    this->Close();
    return B_SUCCESS;
}

bReturnType bContext::Close() {
    this->player->End();
    for(bObject* o : this->pipe) 
        o->End();
    return B_SUCCESS;
}

void bContext::Tick() {
    this->player->Tick();
    if(this->pipeEmpty)
        return;
    for(bObject* o : this->pipe) 
        o->Tick();
}

void bContext::Render() {
    SDL_Rect rect;
    rect.x = player->getPosition().x;
    rect.y = player->getPosition().y;

    rect.w = player->getDimensions().x;
    rect.h = player->getDimensions().y;
    
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(this->renderer, &rect);
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderPresent(this->renderer);
    SDL_RenderClear(this->renderer); 
}
