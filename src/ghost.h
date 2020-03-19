#include "enviro.h"

using namespace enviro;

class GhostController : public Process, public AgentInterface {

    public:
    GhostController() : Process(), AgentInterface(), vx(10) {}

    void init() {
        prevent_rotation();
        //When bumper is touched, the direction of motion is reversed
        notice_collisions_with("Bumper", [&](Event &e) {
              vx = -vx;  
        });
        // caught knight and let knight go back
        notice_collisions_with("Knight", [&](Event &e) {
            emit(Event("caught"));
        });    
        decorate(R"(<g>
            <circle cx=-5 cy=-3 r=2 style='fill:black'></circle>
            <circle cx=5 cy=-3 r=2 style='fill:black'></circle></g>)");
    }

    void start() {}

    //uniform motion
    void update() {
        double fx = -30*(velocity().x-vx);
        omni_apply_force(fx,0);
    }

    void stop() {}

    double vx;


};

class Ghost : public Agent {
    public:
    Ghost(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    GhostController c;
};

DECLARE_INTERFACE(Ghost)
