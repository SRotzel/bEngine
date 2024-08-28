#include "bEngine.h"

bReturnType b_init() {
    ASSERT(
        !SDL_Init(SDL_INIT_VIDEO),
        "SDL failed to initialize: %s\n",
        SDL_GetError());
    LOG("successfully initialized SDL!\n", "");

    return B_SUCCESS;
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
}

bReturnType bContext::Start() {
    this->player->Awake();
    /*for(int i = 0; i < sizeof(this->pipe); i++) {
        this->pipe[i].Awake();
    }*/

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
    }
    this->Close();
    return B_SUCCESS;
}

bReturnType bContext::Close() {
    this->player->End();
    /*for(int i = 0; i < sizeof(this->pipe); i++) 
        this->pipe[i].End();*/
    return B_SUCCESS;
}

void bContext::Tick() {
    this->player->Tick();
    /*for(int i = 0; i < sizeof(this->pipe); i++) 
        this->pipe[i].Tick();*/
}