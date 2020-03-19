#include "enviro.h"

using namespace enviro;

class GhostController : public Process, public AgentInterface {

    public:
    GhostController() : Process(), AgentInterface(), vx(10) {}

    void init() {
        prevent_rotation();
        notice_collisions_with("Bumper", [&](Event &e) {
        
              vx = -vx;
            
        });    
        decorate(R"(<g>
            <circle cx=-5 cy=-3 r=2 style='fill:black'></circle>
            <circle cx=5 cy=-3 r=2 style='fill:black'></circle></g>)");
    }

    void start() {}

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
