
#include "enviro.h"

using namespace enviro;

class TrapController : public Process, public AgentInterface {

    public:
    TrapController() : Process(), AgentInterface() {}

    void init() {
        // By using notice_collisions_with it is possible to emit an
        // event that another class can watch and catch. In this case,
        // all the cameras care about is collisions with the playerAgent. 
        // Collisions with the guards (should it happen) won't trigger anything.
        // notice_collisions_with("playerAgent", [&](Event &e) {
        //     emit(Event("caught"));
        // });
    }
    void start() {}
    void update() {}
    void stop() {}

};

class Trap : public Agent {
    public:
    Trap(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    TrapController c;
};

DECLARE_INTERFACE(Trap)
