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

       if(input[SDLK_RETURN]) {
            printf("You just fucking pressed da d button");
            this->position.x++;
       }
    }
    void End()   override {  }
};

int main(int argc, char** argv) {
    b_init();

    bInfo info;
    info.width      = 680;
    info.height     = 920;
    info.name       = (char*)"Application";
    info.character  = new Player();

    bContext *context = new bContext(info);
    context->Start();
    context->Run();
}
