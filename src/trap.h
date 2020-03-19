
#include "enviro.h"

using namespace enviro;

class TrapController : public Process, public AgentInterface {

    public:
    TrapController() : Process(), AgentInterface() {}
    //Once collide with knight, throw "caught"
    void init() {
        notice_collisions_with("Knight", [&](Event &e) {
            emit(Event("caught"));
        });
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
