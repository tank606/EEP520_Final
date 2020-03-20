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
        // caught: Back to the starting point after being caughtd by ghost, guard, trap
        watch("caught", [this](Event e) {
            teleport(-360, 270, 0);
        });

        //win: Back to the starting point after saving the princess
        watch("win", [this](Event e) {
            teleport(-370, 270, 0);
            label("Win", 0, 0);
        });

        prevent_rotation(); //prevent rotation during movement

        //kill: The lord has killed the princess, the knight has failed and returned to the starting point
        watch("fail", [this](Event e) {

            label("Fail", 0, 0);
            teleport(-360, 270, 0);
            
        });

        //airborne ensures that it is currently on the plane, not the air.
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

         decorate(R"(<g>
            <circle cx=-5 cy=-3 r=2 style='fill:black'></circle>
            <circle cx=5 cy=-3 r=2 style='fill:black'></circle></g>)");
    }
    void start() {}
    
    //demonstrates how to simulate gravity
    void update() {
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
