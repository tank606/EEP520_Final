#include "enviro.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace enviro;
using namespace std;

double min(double a, double b) {
    if ( a < b ) { 
        return a;
    } else {
        return b;
    }
}

class KnightController : public Process, public AgentInterface {

    public:
    KnightController() : Process(), AgentInterface(), LEFT(false), RIGHT(false), JUMP(false) {}

    double height() {
        return min(sensor_value(0), sensor_value(1));
    }
    double airborne() { 
        return height() > H_MIN;
    }
    void init() {
        // This watch is looking for collisions that took place
        // between the agent and the guards or the cameras. If the
        // event "caught" is heard, the player returns to the 
        // starting point.
        watch("caught", [this](Event e) {
            teleport(-364, 270, 0);
        });
        watch("win", [this](Event e) {
            teleport(-364, 270, 0);
        });
        prevent_rotation();
        // If the time_robot (Commisioner) reached the end, it'll
        // display that you did not make it.
        watch("lockdown", [this](Event e) {
            cpVect vect = position();
            double x = vect.x;
            double y = vect.y;
            if (x > 330 && y > 260) {
                label("I escaped!!!", 15, 0);
                teleport(360, 320, 0);
            } else {
                label("Didn't make it!", 0, 0);
                teleport(-364, 270, 0);
            }
        });
        
        watch("keydown", [&](Event& e) {
            std::string k = e.value()["key"];
            if ( k == " " & !airborne()) {
                JUMP = true;
            } else if ( k == "a" ) {
                LEFT = true;
            } else if ( k == "d" ) {
                RIGHT = true;
            } 
        });
        watch("keyup", [&](Event& e) {
            std::string k = e.value()["key"];
            if ( k == "a" ) {
                LEFT = false;
            } else if ( k == "d" ) {
                RIGHT = false;
            }
        }); 
        //omni_apply_force(xf,yf);
    }
    void start() {}

    void update() {
        //omni_damp_movement();
        double fx;
        double fy = JUMP ? JUMP_F : 0;
        if ( !airborne() ) {
            if ( RIGHT ) {
                vx = VEL_X;
            } if ( LEFT ) {
                vx = -VEL_X;
            } else if ( !RIGHT && !LEFT ) {
                vx = 0;
            }
            fx = -K_X*(velocity().x-vx);
        } else {
            if ( RIGHT ) {
                vx = 0.2*VEL_X;
            } if ( LEFT ) {
                vx = -0.2*VEL_X;
            }            
            fx = 0;
            fx = -K_X*(velocity().x-vx);
        }
        omni_apply_force(fx,G+fy);
        JUMP = false;
    }

    void stop() {}


    bool LEFT, RIGHT, JUMP;
    double vx;

    const double VEL_X = 20;
    const double JUMP_F = -2200;
    const double K_X = 15;
    const double G = 500;
    const double H_MIN = 1.0;

};

class Knight : public Agent {
    public:
    Knight(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    KnightController c;
};

DECLARE_INTERFACE(Knight)

#endif