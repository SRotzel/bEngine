/* THIS IS TO BE DEFINED BY THE USER AND WILL NOT BE INCLUDED IN THE RELEASE VERSIONS */
#include "bEngine.h"
#define DEBUG

class Player : public bObject {
public:
    Player() { this->id = 9090; this->position = (v2){ 0.0f, 0.0f }; this->dimension = (v2) {100.f, 100.f}; }
    ~Player() {  }

    void Awake() override {  }
    void Tick()  override { 
        const u8* input = b_get_input(); 

        if(input[SDL_SCANCODE_D])
            this->position.x += speed;
        if(input[SDL_SCANCODE_A])
            this->position.x -= speed;
        if(input[SDL_SCANCODE_W])
            this->position.y -= speed;
        if(input[SDL_SCANCODE_S])
            this->position.y += speed;

        printf("current position: %f%f\n", this->position.x, this->position.y);
    }
    void End()   override {  }

private:
    float speed = 10.f;
};

int main(int argc, char** argv) {
    b_init();
    bObject* obstacle = new bObject(1010, {250.f, 250.f}, {500.f, 500.f});
    bPipeline p;
    p.push_back(obstacle);

    bInfo info;
    info.width      = 680;
    info.height     = 920;
    info.name       = (char*)"Application";
    info.character  = new Player();
    info.pipeline   = p;

    bContext *context = new bContext(info);
    context->Start();
    context->Run();
}
