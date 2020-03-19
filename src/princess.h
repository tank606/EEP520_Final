#include "enviro.h"

using namespace enviro;

class PrincessController : public Process, public AgentInterface {

    public:
    PrincessController() : Process(), AgentInterface() {}

    void init() {
        notice_collisions_with("playerAgent", [&](Event &e) {
            teleport(-344, 270, 0);
            emit(Event("win"));
        });
    }
    void start() {}
    void update() {}
    void stop() {}

};

class Princess : public Agent {
    public:
    Princess(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    PrincessController c;
};

DECLARE_INTERFACE(Princess)
