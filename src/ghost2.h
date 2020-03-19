#ifndef __GHOST2_AGENT__H
#define __GHOST2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class Ghost2Controller : public Process, public AgentInterface {

    public:
    Ghost2Controller() : Process(), AgentInterface(), vx(10) {}

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

class Ghost2 : public Agent {
    public:
    Ghost2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    Ghost2Controller c;
};

DECLARE_INTERFACE(Ghost2)

#endif