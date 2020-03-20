#include "enviro.h"

using namespace enviro;

class PrincessController : public Process, public AgentInterface {

    public:
    PrincessController() : Process(), AgentInterface() {}
    //Touch the knight and win the game
    void init() {
        notice_collisions_with("Knight", [&](Event &e) {
            teleport(-344, 270, 0);
            emit(Event("win"));
        });
        decorate(R"(<g>
            <circle cx=-5 cy=-3 r=2 style='fill:black'></circle>
            <circle cx=5 cy=-3 r=2 style='fill:black'></circle></g>)");
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
