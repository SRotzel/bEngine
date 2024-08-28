#include "bEngine.h"
#define DEBUG

class Player : public bObject {
public:
    Player() { this->id = 9090; this->position = (v2){ 0.0f, 0.0f }; this->dimension = (v2) {100.f, 100.f}; }
    ~Player() {  }

    void Awake() override { printf("IM ALIVE!\n"); }
    void Tick()  override { printf("HELL YEAH\n"); }
    void End()   override { printf("eugh...\n"); }
};

int main(int argc, char** argv) {
    b_init();

    bInfo info;
    info.width      = 620;
    info.height     = 480;
    info.name       = (char*)"Application";
    info.character  = new Player();

    bContext *context = new bContext(info);
    context->Start();
    context->Run();
}
